#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <vector>
#include <mutex>
#include <memory>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDir>
#include <QStatusBar>
#include <QSettings>
#include <QCloseEvent>
#include <QRandomGenerator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define PREPRARE_TIME 10
#define FINISH_TIME   45


typedef enum ProcessStep{
    STEP_1_IDLE,
    STEP_2_PREPRAING,
    STEP_3_TRAINING,
    STEP_4_RESTING,
    STEP_5_FINISH
}ProcessStep;

typedef struct exercise_t{
    QString m_name;
    int m_set;
    int m_reps;
    int m_set_time;
    int m_rest_time;
}exercise_t;

static exercise_t exer_dip              = {.m_name = "Dip"                      ,.m_set = 4,  .m_reps = 12, .m_set_time = 90, .m_rest_time = 75};
static exercise_t exer_bch_pr           = {.m_name = "Bench  Press"             ,.m_set = 4,  .m_reps = 12, .m_set_time = 80, .m_rest_time = 60};
static exercise_t exer_icl_bch_pr       = {.m_name = "Incline Bench Press"      ,.m_set = 4,  .m_reps = 12, .m_set_time = 90, .m_rest_time = 65};
static exercise_t exer_ovh_db           = {.m_name = "Overhead Dumbbell"        ,.m_set = 4,  .m_reps = 12, .m_set_time = 75, .m_rest_time = 70};
static exercise_t exer_lateral_raise    = {.m_name = "Lateral Raise"            ,.m_set = 4,  .m_reps = 15, .m_set_time = 75, .m_rest_time = 60};
static exercise_t exer_flying_chest     = {.m_name = "Flying Chest"             ,.m_set = 4,  .m_reps = 12, .m_set_time = 75, .m_rest_time = 60};

static exercise_t exer_pull_up          = {.m_name = "Pull Up"                  ,.m_set = 4,  .m_reps = 12, .m_set_time = 90, .m_rest_time = 80};
static exercise_t exer_chin_up          = {.m_name = "Chin Up"                  ,.m_set = 4,  .m_reps = 12, .m_set_time = 90, .m_rest_time = 80};
static exercise_t exer_db_row           = {.m_name = "Dumbbell Row"             ,.m_set = 4,  .m_reps = 12, .m_set_time = 120, .m_rest_time = 60};
static exercise_t exer_bar_row          = {.m_name = "Barbell Row"              ,.m_set = 4,  .m_reps = 12, .m_set_time = 80, .m_rest_time = 80};
static exercise_t exer_db_curl          = {.m_name = "Dumbell Curl"             ,.m_set = 4,  .m_reps = 12, .m_set_time = 80, .m_rest_time = 75};
static exercise_t exer_bar_curl         = {.m_name = "Barbell Curl"             ,.m_set = 4,  .m_reps = 12, .m_set_time = 80, .m_rest_time = 70};
static exercise_t exer_harmer_curl      = {.m_name = "Harmer Curl"              ,.m_set = 4,  .m_reps = 12, .m_set_time = 80, .m_rest_time = 70};

static exercise_t exer_db_split_sq      = {.m_name = "Dumbbell Split Squat"     ,.m_set = 4,  .m_reps = 12, .m_set_time = 120, .m_rest_time = 90};
static exercise_t exer_db_roman_sq      = {.m_name = "Dumbbell Roman Squat"     ,.m_set = 4,  .m_reps = 15, .m_set_time = 90, .m_rest_time = 80};
static exercise_t exer_db_bench_sq      = {.m_name = "Dumbbell Bench Squat"     ,.m_set = 4,  .m_reps = 12, .m_set_time = 120, .m_rest_time = 75};
static exercise_t exer_db_font_sq       = {.m_name = "Dumbbell Font Squat"      ,.m_set = 4,  .m_reps = 12, .m_set_time = 80, .m_rest_time = 90};
static exercise_t exer_db_goblet_sq     = {.m_name = "Dumbbell Goblet Squat"    ,.m_set = 4,  .m_reps = 15, .m_set_time = 80, .m_rest_time = 80};

static exercise_t exer_eliptical        = {.m_name = "Eliptical"                ,.m_set = 1,  .m_reps = 1,  .m_set_time = 4*60, .m_rest_time = 60};
static exercise_t exer_sit_up           = {.m_name = "Sit Up"                   ,.m_set = 1,  .m_reps = 15, .m_set_time = 90, .m_rest_time = 60};
static exercise_t exer_blank            = {.m_name = "Blank"                    ,.m_set = 1,  .m_reps = 1, .m_set_time = 120, .m_rest_time = 45};
static exercise_t exer_side_blank       = {.m_name = "Side Blank"               ,.m_set = 2,  .m_reps = 1, .m_set_time = 120, .m_rest_time = 45};
static exercise_t exer_burpees          = {.m_name = "Burpees"                  ,.m_set = 1,  .m_reps = 20, .m_set_time = 120, .m_rest_time = 60};
static exercise_t exer_rope_jump        = {.m_name = "Rope Jump"                ,.m_set = 1,  .m_reps = 1, .m_set_time = 3*60, .m_rest_time = 90};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent (QCloseEvent *event);

    void songEndEvent(QMediaPlayer::MediaStatus status);

private slots:
    void process();

    void on_pushButton_dip_clicked();

    void on_pushButton_bench_press_clicked();

    void on_pushButton_incline_bp_clicked();

    void on_pushButton_ovh_db_clicked();

    void on_pushButton_lateral_raise_clicked();

    void on_pushButton_fly_chest_clicked();

    void on_pushButton_pull_up_clicked();

    void on_pushButton_chin_up_clicked();

    void on_pushButton_db_row_clicked();

    void on_pushButton_barbell_row_clicked();

    void on_pushButton_db_curl_clicked();

    void on_pushButton_barbell_curl_clicked();

    void on_pushButton_harmer_curl_clicked();

    void on_pushButton_db_spl_squat_clicked();

    void on_pushButton_db_roman_deadlift_clicked();

    void on_pushButton_db_single_squat_bench_clicked();

    void on_pushButton_db_front_squat_clicked();

    void on_pushButton_db_goblet_squat_clicked();

    void on_pushButton_eliptical_clicked();

    void on_pushButton_sit_up_clicked();

    void on_pushButton_blank_clicked();

    void on_pushButton_side_blank_clicked();

    void on_pushButton_burpees_clicked();

    void on_pushButton_rope_jump_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_music_clicked();

    void on_pushButton_music_next_clicked();

    void on_pushButton_music_back_clicked();

    void on_pushButton_open_music_clicked();

    void on_verticalSlider_volume_valueChanged(int value);

    void on_comboBox_dir_list_currentTextChanged(const QString &arg1);

    void on_pushButton_clear_list_clicked();

    void on_checkBox_mix_stateChanged(int arg1);

    void on_checkBox_loop_stateChanged(int arg1);

    void on_pushButton_skip_clicked();

    void on_actionTraining_report_triggered();

    void on_actionSetting_data_log_folder_triggered();

private:
    Ui::MainWindow *ui;
    QVector <exercise_t> m_exercise_list;
    int addExercise(exercise_t _exercise);
    int showTimer();
    int showCurrentExercise();
    int resetCurrentExercise();
    int startExercise(exercise_t* _exercise);
    int playSong(int index);
    int finishProgramHandle();

    void saveWorkoutData();
    QMediaPlayer *m_notify;

    QString m_log_data_dir;

    exercise_t* m_current_exercise;
    int m_set_remain;
    int m_current_time_out;

    ProcessStep m_step;
    std::atomic<bool> m_pause;
    std::mutex m_lock;
    int m_total_time_remain;
    int m_total_time_training;

    QVector <QString> m_music_dir_list;   QString m_musicDir;
    QVector <QString> m_mp3_list;
    int m_song_index;
    QMediaPlayer* m_current_song;
    std::atomic<bool> m_mix;
    std::atomic<bool> m_loop;


    std::atomic<bool> m_musicPause;
    int updateExerciseList();

    std::atomic<bool> m_is_training_today;
};
#endif // MAINWINDOW_H
