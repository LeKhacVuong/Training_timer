#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QmessageBox>
#include <QInputDialog>
#include <QDate>


QString secondsToMinutes(int seconds) {
    if(seconds < 0)
        seconds = 0;
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    return QString("%1m %2s").arg(minutes).arg(remainingSeconds);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::process);
    timer->setInterval(1000);
    timer->start();
    resetCurrentExercise();
    m_pause = false;
    ui->label_pause->setText("");

    ui->pushButton_music->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_music_next->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->pushButton_music_back->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    ui->pushButton_stop->setDisabled(true);

    m_musicPause = true;
    m_current_song = new QMediaPlayer(this);
    connect(m_current_song, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::songEndEvent);

    ui->verticalSlider_volume->setMaximum(100);
    ui->verticalSlider_volume->setMinimum(1);
    ui->verticalSlider_volume->setValue(5);

    m_notify = new QMediaPlayer(this);
    m_notify->setMedia(QUrl("qrc:/sounds/sounds/nofity_5s.mp3"));
    m_notify->setVolume(100);
    QSettings settings("YourCompany", "YourApp");

    m_mix = ui->checkBox_mix->isChecked();
    m_loop = ui->checkBox_loop->isChecked();

    settings.beginGroup("Vuong");

    m_log_data_dir = settings.value("log_dir").toString();

    int size = settings.beginReadArray("config");

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString dir = settings.value("value").toString();
        if(QDir(dir).exists()){
            if(QDir(dir).exists()){
                m_music_dir_list.push_back(dir);
                ui->comboBox_dir_list->addItem(m_music_dir_list.at(i));
            }
        }
    }

    settings.endArray();
    settings.endGroup();
    m_step = STEP_1_IDLE;
    m_is_training_today = false;
}

void MainWindow::closeEvent (QCloseEvent *event){
    if(QMessageBox::question(this, "Exit app ?", "App will be close") == QMessageBox::No){
       event->ignore();
       return;
    }

    QSettings settings("YourCompany", "YourApp");
    settings.beginGroup("Vuong");

    settings.setValue("log_dir", m_log_data_dir);

    settings.beginWriteArray("config");

    for (int i = 0; i < m_music_dir_list.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("value", m_music_dir_list.at(i));
        qDebug() << "save dir " << m_music_dir_list.at(i);
    }

    settings.endArray();
    settings.endGroup();

    event->accept();
}

void MainWindow::songEndEvent(QMediaPlayer::MediaStatus status){
    if(status == QMediaPlayer::EndOfMedia){
        qDebug() << "song end, play next song";
        if(m_loop){
            qDebug() << "loop again song";
            m_current_song->play();
            return;
        }

        if(m_mix){
            int new_index = 0;
            do{
                new_index = QRandomGenerator::global()->bounded(0, m_mp3_list.size());
            }while(new_index == m_song_index);
            m_song_index = new_index;
        }else{
            m_song_index++;
            if(m_song_index >= m_mp3_list.size())
                m_song_index = 0;
        }
        playSong(m_song_index);
    }
}

void MainWindow::process(){
    static int tick = 0;
    tick++;

    if(m_pause){
        m_total_time_training++;
        showTimer();
        return;
    }

    if(m_current_exercise){
        if(m_current_time_out <= 0){
                switch (m_step){
                case STEP_1_IDLE:
                    break;
                case STEP_2_PREPRAING:
                    m_step = STEP_3_TRAINING;
                    m_current_time_out = m_current_exercise->m_set_time;
                    break;
                case STEP_3_TRAINING:
                    m_step = STEP_4_RESTING;
                    m_current_time_out = m_current_exercise->m_rest_time;
                    break;
                case STEP_4_RESTING:
                    m_set_remain--;
                    if(m_set_remain > 0){
                        m_step = STEP_2_PREPRAING;
                        m_current_time_out = PREPRARE_TIME;
                    }else{
                        qDebug() << "Finish " << m_current_exercise->m_name;
                        m_step = STEP_5_FINISH;
                        m_current_time_out = FINISH_TIME;
                    }
                    showCurrentExercise();
                    break;
                case STEP_5_FINISH:
                    for (int i = 0; i < ui->listWidget->count(); ++i) {
                        QListWidgetItem *item = ui->listWidget->item(i);
                        if (item->text() == m_current_exercise->m_name) {
                            item->setForeground(QBrush(Qt::white));
                            item->setBackground(QBrush(Qt::gray));
                        }
                    }
                    if(m_current_exercise+1 != m_exercise_list.end()){
                        m_pause = true;
                        QMessageBox::information(this, "Finsh " + m_current_exercise->m_name, "Prepare " + (m_current_exercise+1)->m_name);
                        m_pause = false;
                        startExercise(m_current_exercise+1);
                    }else{
                        finishProgramHandle();
                    }
                    showCurrentExercise();
                    break;
                default:
                    break;
                }
        }
        showTimer();
        if(m_current_time_out == 5 && m_step != STEP_1_IDLE){
            qDebug() << "now notify";
            m_notify->play();
        }
        m_current_time_out--;
        m_total_time_remain--;
        qDebug() << "Timer count " << QString::number(m_current_time_out);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::updateExerciseList(){

    return 0;
}

int MainWindow::showTimer(){

    switch (m_step){
    case STEP_1_IDLE:
        ui->label_timer_stage->setText("None");
        ui->label_timer_remain->setText("None");
        return -1;
        break;
    case STEP_2_PREPRAING:
        ui->label_timer_stage->setText("Pre");
        break;
    case STEP_3_TRAINING:
        ui->label_timer_stage->setText("Train");
        break;
    case STEP_4_RESTING:
        ui->label_timer_stage->setText("Rest");
        break;
    case STEP_5_FINISH:
        ui->label_timer_stage->setText("Finish");
        break;
    default:
        break;
    }
    ui->label_total_time->setText(secondsToMinutes(m_total_time_training));
    ui->label_total_remain_time->setText(secondsToMinutes(m_total_time_remain));
    ui->label_timer_remain->setText(secondsToMinutes(m_current_time_out));
    return 0;
}

int MainWindow::resetCurrentExercise(){
    m_current_exercise = nullptr;
    m_set_remain = 0;
    m_step = STEP_1_IDLE;
    m_current_time_out = 1;
    return 0;
}

int MainWindow::startExercise(exercise_t* _exercise){
    if(!_exercise)
        return -1;
    qDebug() << "Start exercise " << _exercise->m_name;
    m_current_exercise = _exercise;
    m_current_time_out = PREPRARE_TIME;
    m_set_remain = _exercise->m_set;
    m_step = STEP_2_PREPRAING;
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (item->text() == m_current_exercise->m_name) {
            item->setForeground(QBrush(Qt::darkGray));
            item->setBackground(QBrush(Qt::yellow));
        }
    }
    ui->pushButton_pause->setEnabled(true);
    ui->pushButton_skip->setEnabled(true);
    return 0;
}

int MainWindow::playSong(int index){
    if(m_mp3_list.isEmpty() || index >= m_mp3_list.size()){
        qDebug() << "Cannot play song";
        return -1;
    }

    m_current_song->stop();
     qDebug() << "now play song index " << QString::number(m_song_index);
    qDebug() << "now play song " << m_musicDir + '/' + m_mp3_list.at(index);
    ui->label_song_name->setText(m_mp3_list.at(index));
    m_current_song->setMedia(QUrl(m_musicDir + '/' + m_mp3_list.at(index)));

    m_current_song->setVolume(ui->verticalSlider_volume->value());
    if(!m_musicPause)
        m_current_song->play();
    return 0;
}

int MainWindow::finishProgramHandle(){
    showTimer();
    resetCurrentExercise();
    qDebug() << "Done all exercise";
    m_pause = true;
    QMessageBox::information(this, "Finish", "Go to eating");
    m_pause = false;
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_skip->setEnabled(false);
    ui->pushButton_stop->setEnabled(false);

    if(m_log_data_dir.isEmpty()){
        QString logDir = QFileDialog::getExistingDirectory(this, tr("Choose folder to save log"), QDir::homePath() + "/Desktop", QFileDialog::ReadOnly);
        if (logDir.isEmpty()) {
            QMessageBox::warning(this, "Error", "log folder is invalid, use default log dir");
            m_log_data_dir = QDir::homePath() + "/Desktop";

        }else{
            m_log_data_dir = logDir;
        }
        if(!QDir(m_log_data_dir).exists()){
            QDir(m_log_data_dir).mkpath(".");
            qDebug() << "create log folder " << m_log_data_dir;
        }

        qDebug() << "log folder is: " + m_log_data_dir;
    }

    if(QMessageBox::question(this, "Train note ?", "Program today is done, save it?") == QMessageBox::No){
        for(int i = 0; i < 5; i++){
            bool ok;
            QString password = QInputDialog::getText(this, "Confirm ignore ?", "Enter vuonglk to confirm ignore", QLineEdit::Normal, "", &ok);
            if (ok && password == "vuonglk") {
                QMessageBox::information(this, "Success", "Ignore today result");
                m_is_training_today = false;
                break;
            } else {
                QMessageBox::warning(this, "Fail", "Try again time " + QString::number(i + 1) + " on 5 time");
            }
        }
    }

     QMessageBox::information(this, "Save data", "Training report been saved");

     saveWorkoutData();

    return 0;
}

void MainWindow::saveWorkoutData() {
    qDebug() << "Now save data to: " << m_log_data_dir;

    QDate currentDate = QDate::currentDate();
    QString mm_yy = currentDate.toString("MM-yy");
    QString dd_mm_yy = currentDate.toString("dd-MM-yy");

    QString file_path = m_log_data_dir + '/' + mm_yy + "-workout.txt";

    QFile file(file_path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Open workout data " << file_path;
        QTextStream out(&file);
        out << dd_mm_yy << " - " << secondsToMinutes(m_total_time_training) << " - ";
        for(auto &item: m_exercise_list){
            out << item.m_name << "  ";
        }
        out << "\n";
        file.close();
    }else{
        qDebug() << "Cannot open log file";
    }
}

int MainWindow::showCurrentExercise(){
    if(!m_current_exercise)
        return -1;

    ui->label_current_name->setText(m_current_exercise->m_name);
    ui->label_current_rep->setText(QString::number(m_current_exercise->m_reps));
    ui->label_current_rest_time->setText(QString::number(m_current_exercise->m_rest_time));
    ui->label_current_set_time->setText(QString::number(m_current_exercise->m_set_time));
    ui->label_set_remain->setText(QString::number(m_set_remain));
    return 0;
}

int MainWindow::addExercise(exercise_t _exercise){
    std::lock_guard<std::mutex> lockGuard(m_lock);

    int count = 0;
    for(auto& item: m_exercise_list){
        if(item.m_name.contains(_exercise.m_name)){
            count++;
        }
    }

    if(count > 0){
        if(ui->tabWidget->currentIndex() == 3){
            qDebug() << "choose a cardio";
            _exercise.m_name.append("-").append(QString::number(count));
        }else{
            qDebug() << "Exercise " << _exercise.m_name <<" is exist!!!";
            return -1;
        }
    }

    ui->pushButton_start->setEnabled(true);
    ui->pushButton_delete->setEnabled(true);

    m_exercise_list.push_back(_exercise);
    qDebug() << "Add exercise " << _exercise.m_name <<" to today list!!!";

    ui->listWidget->addItem(_exercise.m_name);

    int total_time = 0;
    for(auto& item: m_exercise_list){
        total_time+= (item.m_set_time + item.m_rest_time + PREPRARE_TIME) * item.m_set + FINISH_TIME;
    }
    m_total_time_remain = m_total_time_training = total_time;

    ui->label_total_time->setText(secondsToMinutes(total_time));
    return 0;
}

void MainWindow::on_pushButton_dip_clicked()
{
    this->addExercise(exer_dip);
}


void MainWindow::on_pushButton_bench_press_clicked()
{
    this->addExercise(exer_bch_pr);
}


void MainWindow::on_pushButton_incline_bp_clicked()
{
    this->addExercise(exer_icl_bch_pr);
}


void MainWindow::on_pushButton_ovh_db_clicked()
{
    this->addExercise(exer_ovh_db);
}


void MainWindow::on_pushButton_lateral_raise_clicked()
{
    this->addExercise(exer_lateral_raise);
}


void MainWindow::on_pushButton_fly_chest_clicked()
{
    this->addExercise(exer_flying_chest);
}


void MainWindow::on_pushButton_pull_up_clicked()
{
    this->addExercise(exer_pull_up);
}


void MainWindow::on_pushButton_chin_up_clicked()
{
    this->addExercise(exer_chin_up);
}


void MainWindow::on_pushButton_db_row_clicked()
{
    this->addExercise(exer_db_row);
}


void MainWindow::on_pushButton_barbell_row_clicked()
{
    this->addExercise(exer_bar_row);
}


void MainWindow::on_pushButton_db_curl_clicked()
{
    this->addExercise(exer_bar_curl);
}


void MainWindow::on_pushButton_barbell_curl_clicked()
{
    this->addExercise(exer_bar_curl);
}


void MainWindow::on_pushButton_harmer_curl_clicked()
{
    this->addExercise(exer_harmer_curl);
}


void MainWindow::on_pushButton_db_spl_squat_clicked()
{
    this->addExercise(exer_db_split_sq);
}


void MainWindow::on_pushButton_db_roman_deadlift_clicked()
{
    this->addExercise(exer_db_roman_sq);
}


void MainWindow::on_pushButton_db_single_squat_bench_clicked()
{
    this->addExercise(exer_db_bench_sq);
}


void MainWindow::on_pushButton_db_front_squat_clicked()
{
    this->addExercise(exer_db_font_sq);
}


void MainWindow::on_pushButton_db_goblet_squat_clicked()
{
    this->addExercise(exer_db_goblet_sq);
}


void MainWindow::on_pushButton_eliptical_clicked()
{
    this->addExercise(exer_eliptical);
}


void MainWindow::on_pushButton_sit_up_clicked()
{
    this->addExercise(exer_sit_up);
}


void MainWindow::on_pushButton_blank_clicked()
{
    this->addExercise(exer_blank);
}


void MainWindow::on_pushButton_side_blank_clicked()
{
    this->addExercise(exer_side_blank);
}


void MainWindow::on_pushButton_burpees_clicked()
{
    this->addExercise(exer_burpees);
}


void MainWindow::on_pushButton_rope_jump_clicked()
{
    this->addExercise(exer_rope_jump);
}


void MainWindow::on_pushButton_delete_clicked()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
    if(selectedItems.size() <= 0)
        return;

    for(auto item = m_exercise_list.begin(); item != m_exercise_list.end();){
        for (const auto& selectedItem : selectedItems) {
            QString selectedText = selectedItem->text();
            if (item->m_name == selectedText) {
                qDebug() << "Remove exercise:" << item->m_name;
                m_exercise_list.erase(item);
            }else{
                item++;
            }
        }
    }

    foreach(QListWidgetItem * item, selectedItems)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }

    int total_time = 0;
    for(auto& item: m_exercise_list){
        total_time+= (item.m_set_time + item.m_rest_time + PREPRARE_TIME) * item.m_set + FINISH_TIME;
    }
    ui->label_total_time->setText(secondsToMinutes(total_time));

    if(m_exercise_list.empty()){
        ui->pushButton_start->setEnabled(false);
        ui->pushButton_pause->setEnabled(false);
        ui->pushButton_delete->setEnabled(false);
        ui->pushButton_skip->setEnabled(false);
        ui->pushButton_stop->setEnabled(false);
    }
}


void MainWindow::on_pushButton_start_clicked()
{
    if(m_exercise_list.empty()){
        ui->label_pause->setText("No exercise");
        return;
    }
    ui->label_pause->setText("");
    m_pause = false;

    startExercise(m_exercise_list.begin());
    showCurrentExercise();

    ui->pushButton_start->setDisabled(true);

    int total_time = 0;
    for(auto& item: m_exercise_list){
        total_time+= (item.m_set_time + item.m_rest_time + PREPRARE_TIME) * item.m_set + FINISH_TIME;
    }
    m_total_time_remain = m_total_time_training = total_time;
    ui->pushButton_delete->setDisabled(true);
    ui->pushButton_stop->setDisabled(false);
}


void MainWindow::on_pushButton_pause_clicked()
{
    m_pause = !m_pause;
    ui->label_pause->setText(m_pause?"Pausing!!!":"");
    ui->pushButton_pause->setText(m_pause?"Resume":"Pause");
    showTimer();

    if(m_current_time_out <= 5 && m_step != STEP_1_IDLE){
        if(m_pause){
           m_notify->pause();
        }else{
           m_notify->play();
        }
    }
}


void MainWindow::on_pushButton_stop_clicked()
{

    if(QMessageBox::question(this, "Do you want to stop training program", "Process will be loss") == QMessageBox::No){
       return;
    }

    m_notify->stop();
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_skip->setEnabled(false);
    ui->pushButton_stop->setEnabled(false);
    resetCurrentExercise();
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setForeground(QBrush(Qt::black));
        item->setBackground(QBrush(Qt::white));
    }
    showTimer();

}


void MainWindow::on_pushButton_music_clicked()
{
    if(m_mp3_list.empty()){
        ui->statusbar->showMessage("No songs in list", 3000);
        return;
    }
    qDebug() << QString::number(m_mp3_list.size()) << "song in list";

    m_musicPause = !m_musicPause;
    if(m_musicPause){
        ui->pushButton_music->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        qDebug() << "now stop background music";
        m_current_song->pause();
    }else{
        ui->pushButton_music->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        qDebug() << "now play background music";
        if(m_current_song == nullptr){
            m_song_index = 0;
            playSong(m_song_index);
        }else{
            m_current_song->play();
        }
    }
}


void MainWindow::on_pushButton_music_next_clicked()
{
    if(m_mix){
        int new_index = 0;
        do{
            new_index = QRandomGenerator::global()->bounded(0, m_mp3_list.size());
        }while(new_index == m_song_index);
        m_song_index = new_index;
    }else{
        m_song_index++;
        if(m_song_index >= m_mp3_list.size())
            m_song_index = 0;
    }
    playSong(m_song_index);
}


void MainWindow::on_pushButton_music_back_clicked()
{
    if(m_mix){
        int new_index = 0;
        do{
            new_index = QRandomGenerator::global()->bounded(0, m_mp3_list.size());
        }while(new_index == m_song_index);
        m_song_index = new_index;
    }else{
        m_song_index--;
        if(m_song_index <= 0)
            m_song_index = m_mp3_list.size() - 1;
    }

    playSong(m_song_index);
}


void MainWindow::on_pushButton_open_music_clicked()
{
    QString musicDir = QFileDialog::getExistingDirectory(this, tr("Choose music folder"), QDir::homePath() + "/Desktop", QFileDialog::ReadOnly);
    if (musicDir.isEmpty()) {
        return;
    }
    qDebug() << "Music folder" << musicDir;
    QDir directory(musicDir);
    QStringList songList = directory.entryList(QStringList() << "*.mp3" << "*.MP3",QDir::Files);

    if(songList.isEmpty()){
        qDebug() << "Folder not contain any song";
        return;
    }

    m_mp3_list.clear();
    m_musicDir = musicDir;
    foreach(QString filename, songList) {
        m_mp3_list.push_back(filename);
        qDebug() << "add to song list " << filename;
    }

    for(int i = 0; i < m_mp3_list.size(); i++){
        qDebug() << m_mp3_list.at(i);
    }


    for(auto item: m_music_dir_list){
        if(item == musicDir){
            ui->comboBox_dir_list->currentTextChanged(musicDir);
            return;
        }
    }

    m_music_dir_list.push_back(musicDir);
    ui->comboBox_dir_list->addItem(musicDir);
    ui->comboBox_dir_list->setCurrentText(musicDir);

}


void MainWindow::on_verticalSlider_volume_valueChanged(int value)
{
    if(m_current_song){
        m_current_song->setVolume(value);
        qDebug() << "set volume to " << QString::number(value);
    }
}


void MainWindow::on_comboBox_dir_list_currentTextChanged(const QString &arg1)
{
    QDir directory(arg1);
    QStringList songList = directory.entryList(QStringList() << "*.mp3" << "*.MP3",QDir::Files);

    if(songList.isEmpty()){
        qDebug() << "Folder not contain any song";
        return;
    }

    m_musicDir = arg1;
    m_mp3_list.clear();
    foreach(QString filename, songList) {
        m_mp3_list.push_back(filename);
        qDebug() << "add to song list " << filename;
    }

    for(int i = 0; i < m_mp3_list.size(); i++){
        qDebug() << m_mp3_list.at(i);
    }

    m_song_index = 0;
    playSong(m_song_index);
}


void MainWindow::on_pushButton_clear_list_clicked()
{
    if(QMessageBox::question(this, "Clear data ?", "Choose ok to continue") == QMessageBox::No){
       return;
    }
    m_current_song->stop();
    m_mp3_list.clear();
    m_music_dir_list.clear();
    ui->pushButton_music->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    qDebug() << "now clear background music";
    m_current_song->pause();
    m_musicPause = true;
    ui->label_song_name->setText("none");
    ui->comboBox_dir_list->clear();
}


void MainWindow::on_checkBox_mix_stateChanged(int arg1)
{
    m_mix = arg1;
}


void MainWindow::on_checkBox_loop_stateChanged(int arg1)
{
    m_loop = arg1;
}


void MainWindow::on_pushButton_skip_clicked()
{
    if(QMessageBox::question(this, "Skip ?", "Jumo to next step") == QMessageBox::No){
       return;
    }

    if(m_current_exercise && m_step != STEP_1_IDLE){
        m_total_time_remain -= m_current_time_out;
        switch (m_step){
        case STEP_1_IDLE:
            break;
        case STEP_2_PREPRAING:
            m_step = STEP_3_TRAINING;
            m_current_time_out = m_current_exercise->m_set_time;
            break;
        case STEP_3_TRAINING:
            m_step = STEP_4_RESTING;
            m_current_time_out = m_current_exercise->m_rest_time;
            break;
        case STEP_4_RESTING:
            m_set_remain--;
            if(m_set_remain > 0){
                m_step = STEP_2_PREPRAING;
                m_current_time_out = PREPRARE_TIME;
            }else{
                qDebug() << "Finish " << m_current_exercise->m_name;
                m_step = STEP_5_FINISH;
                m_current_time_out = FINISH_TIME;
            }
            showCurrentExercise();
            break;
        case STEP_5_FINISH:
            for (int i = 0; i < ui->listWidget->count(); ++i) {
                QListWidgetItem *item = ui->listWidget->item(i);
                if (item->text() == m_current_exercise->m_name) {
                    item->setForeground(QBrush(Qt::white));
                    item->setBackground(QBrush(Qt::gray));
                }
            }
            if(m_current_exercise+1 != m_exercise_list.end()){
                m_pause = true;
                QMessageBox::information(this, "Finsh " + m_current_exercise->m_name, "Prepare " + (m_current_exercise+1)->m_name);
                m_pause = false;
                startExercise(m_current_exercise+1);
            }else{
                finishProgramHandle();
            }
            showCurrentExercise();
            break;
        default:
            break;
        }
    }
    showTimer();
    m_notify->stop();
}


void MainWindow::on_actionTraining_report_triggered()
{
}


void MainWindow::on_actionSetting_data_log_folder_triggered()
{
    if(!m_log_data_dir.isEmpty()){
        if(QMessageBox::question(this, "Folder exist ?", "Current log folder is "+ m_log_data_dir +", do you want to change it?") == QMessageBox::No){
           return;
        }
    }

    QString logDir = QFileDialog::getExistingDirectory(this, tr("Choose folder to save log"), QDir::homePath() + "/Desktop", QFileDialog::ReadOnly);
    if (logDir.isEmpty()) {
        return;
    }

    qDebug() << "log folder is " + logDir;
    m_log_data_dir = logDir;

}

