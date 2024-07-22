#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QmessageBox>

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
    m_current_song = nullptr;

    ui->pushButton_music->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_music_next->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->pushButton_music_back->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    ui->pushButton_stop->setDisabled(true);

    m_musicPause = true;

    ui->verticalSlider_volume->setMaximum(100);
    ui->verticalSlider_volume->setMinimum(1);
    ui->verticalSlider_volume->setValue(50);

    m_notify = new QMediaPlayer(this);
    m_notify->setMedia(QUrl("qrc:/sounds/sounds/nofity_5s.mp3"));
    m_notify->setVolume(100);
}

void MainWindow::closeEvent (QCloseEvent *event){
    if(QMessageBox::question(this, "Do you want to exits", "App will be close") == QMessageBox::No){
       event->ignore();
       return;
    }


    event->accept();
}

void MainWindow::process(){
    static int tick = 0;
    tick++;

    if(m_pause)
        return;

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
                        m_current_time_out = 6;
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
                        startExercise(m_current_exercise+1);
                    }else{
                        resetCurrentExercise();
                        qDebug() << "Done all exercise";
                        ui->label_pause->setText("Done for today!!!");
                    }
                    showCurrentExercise();
                    break;
                default:
                    break;
                }
        }
        showTimer();
        if(m_current_time_out == 5){
            qDebug() << "now notify";
            m_notify->play();
        }
        m_current_time_out--;
        m_total_time--;
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
    ui->label_total_remain_time->setText(secondsToMinutes(m_total_time));
    ui->label_timer_remain->setText(secondsToMinutes(m_current_time_out));
    return 0;
}

int MainWindow::resetCurrentExercise(){
    m_current_exercise = nullptr;
    m_set_remain = 0;
    m_step = STEP_1_IDLE;
    m_current_time_out = 0;
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
    return 0;
}

int MainWindow::playSong(int index){
    if(m_mp3_list.isEmpty() || index >= m_mp3_list.size()){
        qDebug() << "Cannot play song";
        return -1;
    }
    if(m_current_song == nullptr){
        m_current_song = new QMediaPlayer(this);
    }
    qDebug() << "now play song " << m_musicDir + '/' + m_mp3_list.at(index);
    ui->label_song_name->setText(m_mp3_list.at(index));
    m_current_song->setMedia(QUrl(m_musicDir + '/' + m_mp3_list.at(index)));
    m_current_song->play();
    return 0;
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

    _exercise.m_set_time = 15;
    _exercise.m_rest_time = 15;
    _exercise.m_set = 3;

    for(auto& item: m_exercise_list){
        if(_exercise.m_name == item.m_name){
            qDebug() << "Exercise " << _exercise.m_name <<" is exist!!!";
            return -1;
        }
    }
    m_exercise_list.push_back(_exercise);
    qDebug() << "Add exercise " << _exercise.m_name <<" to today list!!!";

    ui->listWidget->addItem(_exercise.m_name);

    int total_time = 0;
    for(auto& item: m_exercise_list){
        total_time+= (item.m_set_time + item.m_rest_time + PREPRARE_TIME) * item.m_set;
    }
    total_time+= FINISH_TIME;
    m_total_time = total_time;

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

}


void MainWindow::on_pushButton_chin_up_clicked()
{

}


void MainWindow::on_pushButton_db_row_clicked()
{

}


void MainWindow::on_pushButton_barbell_row_clicked()
{

}


void MainWindow::on_pushButton_db_curl_clicked()
{

}


void MainWindow::on_pushButton_barbell_curl_clicked()
{

}


void MainWindow::on_pushButton_harmer_curl_clicked()
{

}


void MainWindow::on_pushButton_db_spl_squat_clicked()
{

}


void MainWindow::on_pushButton_db_roman_deadlift_clicked()
{

}


void MainWindow::on_pushButton_db_single_squat_bench_clicked()
{

}


void MainWindow::on_pushButton_db_front_squat_clicked()
{

}


void MainWindow::on_pushButton_db_goblet_squat_clicked()
{

}


void MainWindow::on_pushButton_eliptical_clicked()
{

}


void MainWindow::on_pushButton_sit_up_clicked()
{

}


void MainWindow::on_pushButton_blank_clicked()
{

}


void MainWindow::on_pushButton_side_blank_clicked()
{

}


void MainWindow::on_pushButton_burpees_clicked()
{

}


void MainWindow::on_pushButton_rope_jump_clicked()
{

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
        total_time+= (item.m_set_time + item.m_rest_time) * item.m_set;
    }
    ui->label_total_time->setText(secondsToMinutes(total_time));
}


void MainWindow::on_pushButton_start_clicked()
{
    ui->pushButton_delete->setDisabled(true);
    ui->pushButton_stop->setDisabled(false);

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
        total_time+= (item.m_set_time + item.m_rest_time + PREPRARE_TIME) * item.m_set;
    }
    total_time+= FINISH_TIME;
    m_total_time = total_time;

}


void MainWindow::on_pushButton_pause_clicked()
{
    m_pause = !m_pause;
    ui->label_pause->setText(m_pause?"Pausing!!!":"");
    if(m_pause){
        m_notify->pause();
    }else{
        m_notify->play();
    }
}


void MainWindow::on_pushButton_stop_clicked()
{

    if(QMessageBox::question(this, "Do you want to stop training program", "Process will be loss") == QMessageBox::No){
       return;
    }
    m_notify->stop();
    ui->pushButton_delete->setDisabled(false);
    ui->pushButton_start->setDisabled(false);
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
    m_song_index++;
    if(m_song_index >= m_mp3_list.size())
        m_song_index = 0;
    playSong(m_song_index);
}


void MainWindow::on_pushButton_music_back_clicked()
{
    m_song_index--;
    if(m_song_index <= 0)
        m_song_index = m_mp3_list.size() - 1;
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

    m_musicDir = musicDir;
    foreach(QString filename, songList) {
        m_mp3_list.push_back(filename);
        qDebug() << "add to song list " << filename;
    }

    for(int i = 0; i < m_mp3_list.size(); i++){
        qDebug() << m_mp3_list.at(i);
    }
}


void MainWindow::on_verticalSlider_volume_valueChanged(int value)
{
    if(m_current_song){
        m_current_song->setVolume(value);
        qDebug() << "set volume to " << QString::number(value);
    }
}

