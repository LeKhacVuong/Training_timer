/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTraining_report;
    QAction *actionSetting_data_log_folder;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_push;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Push_list;
    QPushButton *pushButton_dip;
    QPushButton *pushButton_bench_press;
    QPushButton *pushButton_incline_bp;
    QPushButton *pushButton_ovh_db;
    QPushButton *pushButton_lateral_raise;
    QPushButton *pushButton_fly_chest;
    QWidget *tab_pull;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *pull_list;
    QPushButton *pushButton_pull_up;
    QPushButton *pushButton_chin_up;
    QPushButton *pushButton_db_row;
    QPushButton *pushButton_barbell_row;
    QPushButton *pushButton_db_curl;
    QPushButton *pushButton_barbell_curl;
    QPushButton *pushButton_harmer_curl;
    QWidget *tab_leg;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *leg_list;
    QPushButton *pushButton_db_spl_squat;
    QPushButton *pushButton_db_roman_deadlift;
    QPushButton *pushButton_db_single_squat_bench;
    QPushButton *pushButton_db_front_squat;
    QPushButton *pushButton_db_goblet_squat;
    QWidget *tab_cardio;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *cardio_list;
    QPushButton *pushButton_eliptical;
    QPushButton *pushButton_sit_up;
    QPushButton *pushButton_blank;
    QPushButton *pushButton_side_blank;
    QPushButton *pushButton_burpees;
    QPushButton *pushButton_rope_jump;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *control_list;
    QPushButton *pushButton_start;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QListWidget *listWidget;
    QLabel *label_total_remain_time;
    QLabel *label_excercise_list;
    QLabel *label_total_time;
    QPushButton *pushButton_delete;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_current_name;
    QLabel *label_current_rep_text;
    QLabel *label_current_rep;
    QLabel *label_7;
    QLabel *label_current_set_time;
    QLabel *label_current_rest_text;
    QLabel *label_current_rest_time;
    QLabel *label_set_remain_text;
    QLabel *label_set_remain;
    QLabel *label_excercise_list_2;
    QLabel *label_slash;
    QLabel *label_pause;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_excercise_list_3;
    QPushButton *pushButton_skip;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_timer_stage;
    QLabel *label_timer_remain;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox_dir_list;
    QLabel *label_song_name;
    QHBoxLayout *horizontalLayout_4;
    QSlider *verticalSlider_volume;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_music_back;
    QPushButton *pushButton_music;
    QPushButton *pushButton_music_next;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_mix;
    QCheckBox *checkBox_loop;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_open_music;
    QPushButton *pushButton_clear_list;
    QMenuBar *menubar;
    QMenu *menuOption;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1066, 669);
        MainWindow->setMaximumSize(QSize(1066, 669));
        actionTraining_report = new QAction(MainWindow);
        actionTraining_report->setObjectName(QString::fromUtf8("actionTraining_report"));
        actionSetting_data_log_folder = new QAction(MainWindow);
        actionSetting_data_log_folder->setObjectName(QString::fromUtf8("actionSetting_data_log_folder"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 301, 571));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab_push = new QWidget();
        tab_push->setObjectName(QString::fromUtf8("tab_push"));
        verticalLayoutWidget_3 = new QWidget(tab_push);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 271, 331));
        Push_list = new QVBoxLayout(verticalLayoutWidget_3);
        Push_list->setObjectName(QString::fromUtf8("Push_list"));
        Push_list->setContentsMargins(0, 0, 0, 0);
        pushButton_dip = new QPushButton(verticalLayoutWidget_3);
        pushButton_dip->setObjectName(QString::fromUtf8("pushButton_dip"));
        pushButton_dip->setFont(font);

        Push_list->addWidget(pushButton_dip);

        pushButton_bench_press = new QPushButton(verticalLayoutWidget_3);
        pushButton_bench_press->setObjectName(QString::fromUtf8("pushButton_bench_press"));
        pushButton_bench_press->setFont(font);

        Push_list->addWidget(pushButton_bench_press);

        pushButton_incline_bp = new QPushButton(verticalLayoutWidget_3);
        pushButton_incline_bp->setObjectName(QString::fromUtf8("pushButton_incline_bp"));
        pushButton_incline_bp->setFont(font);

        Push_list->addWidget(pushButton_incline_bp);

        pushButton_ovh_db = new QPushButton(verticalLayoutWidget_3);
        pushButton_ovh_db->setObjectName(QString::fromUtf8("pushButton_ovh_db"));
        pushButton_ovh_db->setFont(font);

        Push_list->addWidget(pushButton_ovh_db);

        pushButton_lateral_raise = new QPushButton(verticalLayoutWidget_3);
        pushButton_lateral_raise->setObjectName(QString::fromUtf8("pushButton_lateral_raise"));
        pushButton_lateral_raise->setFont(font);

        Push_list->addWidget(pushButton_lateral_raise);

        pushButton_fly_chest = new QPushButton(verticalLayoutWidget_3);
        pushButton_fly_chest->setObjectName(QString::fromUtf8("pushButton_fly_chest"));
        pushButton_fly_chest->setFont(font);

        Push_list->addWidget(pushButton_fly_chest);

        tabWidget->addTab(tab_push, QString());
        tab_pull = new QWidget();
        tab_pull->setObjectName(QString::fromUtf8("tab_pull"));
        verticalLayoutWidget_4 = new QWidget(tab_pull);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 271, 341));
        pull_list = new QVBoxLayout(verticalLayoutWidget_4);
        pull_list->setObjectName(QString::fromUtf8("pull_list"));
        pull_list->setContentsMargins(0, 0, 0, 0);
        pushButton_pull_up = new QPushButton(verticalLayoutWidget_4);
        pushButton_pull_up->setObjectName(QString::fromUtf8("pushButton_pull_up"));
        pushButton_pull_up->setFont(font);

        pull_list->addWidget(pushButton_pull_up);

        pushButton_chin_up = new QPushButton(verticalLayoutWidget_4);
        pushButton_chin_up->setObjectName(QString::fromUtf8("pushButton_chin_up"));
        pushButton_chin_up->setFont(font);

        pull_list->addWidget(pushButton_chin_up);

        pushButton_db_row = new QPushButton(verticalLayoutWidget_4);
        pushButton_db_row->setObjectName(QString::fromUtf8("pushButton_db_row"));
        pushButton_db_row->setFont(font);

        pull_list->addWidget(pushButton_db_row);

        pushButton_barbell_row = new QPushButton(verticalLayoutWidget_4);
        pushButton_barbell_row->setObjectName(QString::fromUtf8("pushButton_barbell_row"));
        pushButton_barbell_row->setFont(font);

        pull_list->addWidget(pushButton_barbell_row);

        pushButton_db_curl = new QPushButton(verticalLayoutWidget_4);
        pushButton_db_curl->setObjectName(QString::fromUtf8("pushButton_db_curl"));
        pushButton_db_curl->setFont(font);

        pull_list->addWidget(pushButton_db_curl);

        pushButton_barbell_curl = new QPushButton(verticalLayoutWidget_4);
        pushButton_barbell_curl->setObjectName(QString::fromUtf8("pushButton_barbell_curl"));
        pushButton_barbell_curl->setFont(font);

        pull_list->addWidget(pushButton_barbell_curl);

        pushButton_harmer_curl = new QPushButton(verticalLayoutWidget_4);
        pushButton_harmer_curl->setObjectName(QString::fromUtf8("pushButton_harmer_curl"));
        pushButton_harmer_curl->setFont(font);

        pull_list->addWidget(pushButton_harmer_curl);

        tabWidget->addTab(tab_pull, QString());
        tab_leg = new QWidget();
        tab_leg->setObjectName(QString::fromUtf8("tab_leg"));
        verticalLayoutWidget_5 = new QWidget(tab_leg);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 273, 301));
        leg_list = new QVBoxLayout(verticalLayoutWidget_5);
        leg_list->setObjectName(QString::fromUtf8("leg_list"));
        leg_list->setContentsMargins(0, 0, 0, 0);
        pushButton_db_spl_squat = new QPushButton(verticalLayoutWidget_5);
        pushButton_db_spl_squat->setObjectName(QString::fromUtf8("pushButton_db_spl_squat"));
        pushButton_db_spl_squat->setFont(font);

        leg_list->addWidget(pushButton_db_spl_squat);

        pushButton_db_roman_deadlift = new QPushButton(verticalLayoutWidget_5);
        pushButton_db_roman_deadlift->setObjectName(QString::fromUtf8("pushButton_db_roman_deadlift"));
        pushButton_db_roman_deadlift->setFont(font);

        leg_list->addWidget(pushButton_db_roman_deadlift);

        pushButton_db_single_squat_bench = new QPushButton(verticalLayoutWidget_5);
        pushButton_db_single_squat_bench->setObjectName(QString::fromUtf8("pushButton_db_single_squat_bench"));
        pushButton_db_single_squat_bench->setFont(font);

        leg_list->addWidget(pushButton_db_single_squat_bench);

        pushButton_db_front_squat = new QPushButton(verticalLayoutWidget_5);
        pushButton_db_front_squat->setObjectName(QString::fromUtf8("pushButton_db_front_squat"));
        pushButton_db_front_squat->setFont(font);

        leg_list->addWidget(pushButton_db_front_squat);

        pushButton_db_goblet_squat = new QPushButton(verticalLayoutWidget_5);
        pushButton_db_goblet_squat->setObjectName(QString::fromUtf8("pushButton_db_goblet_squat"));
        pushButton_db_goblet_squat->setFont(font);

        leg_list->addWidget(pushButton_db_goblet_squat);

        tabWidget->addTab(tab_leg, QString());
        tab_cardio = new QWidget();
        tab_cardio->setObjectName(QString::fromUtf8("tab_cardio"));
        verticalLayoutWidget_6 = new QWidget(tab_cardio);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 10, 271, 301));
        cardio_list = new QVBoxLayout(verticalLayoutWidget_6);
        cardio_list->setObjectName(QString::fromUtf8("cardio_list"));
        cardio_list->setContentsMargins(0, 0, 0, 0);
        pushButton_eliptical = new QPushButton(verticalLayoutWidget_6);
        pushButton_eliptical->setObjectName(QString::fromUtf8("pushButton_eliptical"));
        pushButton_eliptical->setFont(font);

        cardio_list->addWidget(pushButton_eliptical);

        pushButton_sit_up = new QPushButton(verticalLayoutWidget_6);
        pushButton_sit_up->setObjectName(QString::fromUtf8("pushButton_sit_up"));
        pushButton_sit_up->setFont(font);

        cardio_list->addWidget(pushButton_sit_up);

        pushButton_blank = new QPushButton(verticalLayoutWidget_6);
        pushButton_blank->setObjectName(QString::fromUtf8("pushButton_blank"));
        pushButton_blank->setFont(font);

        cardio_list->addWidget(pushButton_blank);

        pushButton_side_blank = new QPushButton(verticalLayoutWidget_6);
        pushButton_side_blank->setObjectName(QString::fromUtf8("pushButton_side_blank"));
        pushButton_side_blank->setFont(font);

        cardio_list->addWidget(pushButton_side_blank);

        pushButton_burpees = new QPushButton(verticalLayoutWidget_6);
        pushButton_burpees->setObjectName(QString::fromUtf8("pushButton_burpees"));
        pushButton_burpees->setFont(font);

        cardio_list->addWidget(pushButton_burpees);

        pushButton_rope_jump = new QPushButton(verticalLayoutWidget_6);
        pushButton_rope_jump->setObjectName(QString::fromUtf8("pushButton_rope_jump"));
        pushButton_rope_jump->setFont(font);

        cardio_list->addWidget(pushButton_rope_jump);

        tabWidget->addTab(tab_cardio, QString());
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(340, 450, 311, 115));
        control_list = new QVBoxLayout(verticalLayoutWidget);
        control_list->setObjectName(QString::fromUtf8("control_list"));
        control_list->setContentsMargins(0, 0, 0, 0);
        pushButton_start = new QPushButton(verticalLayoutWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setEnabled(false);
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_start->setFont(font1);

        control_list->addWidget(pushButton_start);

        pushButton_pause = new QPushButton(verticalLayoutWidget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setEnabled(false);
        pushButton_pause->setFont(font1);

        control_list->addWidget(pushButton_pause);

        pushButton_stop = new QPushButton(verticalLayoutWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setEnabled(false);
        pushButton_stop->setFont(font1);

        control_list->addWidget(pushButton_stop);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(330, 40, 321, 351));
        QFont font2;
        font2.setPointSize(16);
        listWidget->setFont(font2);
        label_total_remain_time = new QLabel(centralwidget);
        label_total_remain_time->setObjectName(QString::fromUtf8("label_total_remain_time"));
        label_total_remain_time->setGeometry(QRect(330, 400, 111, 16));
        label_total_remain_time->setFont(font);
        label_excercise_list = new QLabel(centralwidget);
        label_excercise_list->setObjectName(QString::fromUtf8("label_excercise_list"));
        label_excercise_list->setGeometry(QRect(380, 0, 281, 51));
        label_excercise_list->setFont(font1);
        label_total_time = new QLabel(centralwidget);
        label_total_time->setObjectName(QString::fromUtf8("label_total_time"));
        label_total_time->setGeometry(QRect(560, 400, 111, 20));
        label_total_time->setFont(font);
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setEnabled(false);
        pushButton_delete->setGeometry(QRect(550, 360, 91, 27));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_delete->setFont(font3);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(670, 40, 291, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setPointSize(18);
        label->setFont(font4);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_current_name = new QLabel(formLayoutWidget);
        label_current_name->setObjectName(QString::fromUtf8("label_current_name"));
        label_current_name->setFont(font4);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_current_name);

        label_current_rep_text = new QLabel(formLayoutWidget);
        label_current_rep_text->setObjectName(QString::fromUtf8("label_current_rep_text"));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        label_current_rep_text->setFont(font5);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_current_rep_text);

        label_current_rep = new QLabel(formLayoutWidget);
        label_current_rep->setObjectName(QString::fromUtf8("label_current_rep"));
        label_current_rep->setFont(font5);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_current_rep);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        label_current_set_time = new QLabel(formLayoutWidget);
        label_current_set_time->setObjectName(QString::fromUtf8("label_current_set_time"));
        label_current_set_time->setFont(font4);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_current_set_time);

        label_current_rest_text = new QLabel(formLayoutWidget);
        label_current_rest_text->setObjectName(QString::fromUtf8("label_current_rest_text"));
        label_current_rest_text->setFont(font4);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_current_rest_text);

        label_current_rest_time = new QLabel(formLayoutWidget);
        label_current_rest_time->setObjectName(QString::fromUtf8("label_current_rest_time"));
        label_current_rest_time->setFont(font4);

        formLayout->setWidget(3, QFormLayout::FieldRole, label_current_rest_time);

        label_set_remain_text = new QLabel(formLayoutWidget);
        label_set_remain_text->setObjectName(QString::fromUtf8("label_set_remain_text"));
        label_set_remain_text->setFont(font5);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_set_remain_text);

        label_set_remain = new QLabel(formLayoutWidget);
        label_set_remain->setObjectName(QString::fromUtf8("label_set_remain"));
        label_set_remain->setFont(font5);

        formLayout->setWidget(4, QFormLayout::FieldRole, label_set_remain);

        label_excercise_list_2 = new QLabel(centralwidget);
        label_excercise_list_2->setObjectName(QString::fromUtf8("label_excercise_list_2"));
        label_excercise_list_2->setGeometry(QRect(720, -20, 211, 71));
        label_excercise_list_2->setFont(font1);
        label_slash = new QLabel(centralwidget);
        label_slash->setObjectName(QString::fromUtf8("label_slash"));
        label_slash->setGeometry(QRect(490, 400, 21, 16));
        label_slash->setFont(font);
        label_pause = new QLabel(centralwidget);
        label_pause->setObjectName(QString::fromUtf8("label_pause"));
        label_pause->setGeometry(QRect(790, 220, 121, 31));
        label_pause->setFont(font3);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(660, 250, 361, 175));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_excercise_list_3 = new QLabel(layoutWidget);
        label_excercise_list_3->setObjectName(QString::fromUtf8("label_excercise_list_3"));
        QFont font6;
        font6.setPointSize(24);
        font6.setBold(true);
        font6.setWeight(75);
        font6.setStyleStrategy(QFont::PreferDefault);
        label_excercise_list_3->setFont(font6);

        horizontalLayout_5->addWidget(label_excercise_list_3);

        pushButton_skip = new QPushButton(layoutWidget);
        pushButton_skip->setObjectName(QString::fromUtf8("pushButton_skip"));
        pushButton_skip->setEnabled(false);
        QFont font7;
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        pushButton_skip->setFont(font7);

        horizontalLayout_5->addWidget(pushButton_skip);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font8;
        font8.setPointSize(28);
        label_11->setFont(font8);

        verticalLayout->addWidget(label_11);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font8);

        verticalLayout->addWidget(label_13);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_timer_stage = new QLabel(layoutWidget);
        label_timer_stage->setObjectName(QString::fromUtf8("label_timer_stage"));
        QFont font9;
        font9.setPointSize(36);
        font9.setBold(true);
        font9.setWeight(75);
        label_timer_stage->setFont(font9);

        verticalLayout_2->addWidget(label_timer_stage);

        label_timer_remain = new QLabel(layoutWidget);
        label_timer_remain->setObjectName(QString::fromUtf8("label_timer_remain"));
        label_timer_remain->setFont(font9);

        verticalLayout_2->addWidget(label_timer_remain);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(660, 444, 371, 121));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox_dir_list = new QComboBox(layoutWidget1);
        comboBox_dir_list->setObjectName(QString::fromUtf8("comboBox_dir_list"));

        verticalLayout_6->addWidget(comboBox_dir_list);

        label_song_name = new QLabel(layoutWidget1);
        label_song_name->setObjectName(QString::fromUtf8("label_song_name"));
        label_song_name->setScaledContents(false);

        verticalLayout_6->addWidget(label_song_name);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalSlider_volume = new QSlider(layoutWidget1);
        verticalSlider_volume->setObjectName(QString::fromUtf8("verticalSlider_volume"));
        verticalSlider_volume->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(verticalSlider_volume);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_music_back = new QPushButton(layoutWidget1);
        pushButton_music_back->setObjectName(QString::fromUtf8("pushButton_music_back"));
        QFont font10;
        font10.setPointSize(10);
        font10.setBold(true);
        font10.setWeight(75);
        pushButton_music_back->setFont(font10);

        horizontalLayout_2->addWidget(pushButton_music_back);

        pushButton_music = new QPushButton(layoutWidget1);
        pushButton_music->setObjectName(QString::fromUtf8("pushButton_music"));
        pushButton_music->setFont(font10);

        horizontalLayout_2->addWidget(pushButton_music);

        pushButton_music_next = new QPushButton(layoutWidget1);
        pushButton_music_next->setObjectName(QString::fromUtf8("pushButton_music_next"));
        pushButton_music_next->setFont(font10);

        horizontalLayout_2->addWidget(pushButton_music_next);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        checkBox_mix = new QCheckBox(layoutWidget1);
        checkBox_mix->setObjectName(QString::fromUtf8("checkBox_mix"));
        checkBox_mix->setFont(font10);

        horizontalLayout_3->addWidget(checkBox_mix);

        checkBox_loop = new QCheckBox(layoutWidget1);
        checkBox_loop->setObjectName(QString::fromUtf8("checkBox_loop"));
        QFont font11;
        font11.setBold(true);
        font11.setWeight(75);
        checkBox_loop->setFont(font11);

        horizontalLayout_3->addWidget(checkBox_loop);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton_open_music = new QPushButton(layoutWidget1);
        pushButton_open_music->setObjectName(QString::fromUtf8("pushButton_open_music"));
        QFont font12;
        font12.setPointSize(14);
        pushButton_open_music->setFont(font12);

        verticalLayout_4->addWidget(pushButton_open_music);

        pushButton_clear_list = new QPushButton(layoutWidget1);
        pushButton_clear_list->setObjectName(QString::fromUtf8("pushButton_clear_list"));
        pushButton_clear_list->setFont(font12);

        verticalLayout_4->addWidget(pushButton_clear_list);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1066, 20));
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOption->menuAction());
        menuOption->addAction(actionTraining_report);
        menuOption->addAction(actionSetting_data_log_folder);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTraining_report->setText(QApplication::translate("MainWindow", "Training report", nullptr));
        actionSetting_data_log_folder->setText(QApplication::translate("MainWindow", "Setting data log folder", nullptr));
        pushButton_dip->setText(QApplication::translate("MainWindow", "Dip", nullptr));
        pushButton_bench_press->setText(QApplication::translate("MainWindow", "Bench Press", nullptr));
        pushButton_incline_bp->setText(QApplication::translate("MainWindow", "Incline Bench Press", nullptr));
        pushButton_ovh_db->setText(QApplication::translate("MainWindow", "Over Head Dumbbell", nullptr));
        pushButton_lateral_raise->setText(QApplication::translate("MainWindow", "Lateral Raises", nullptr));
        pushButton_fly_chest->setText(QApplication::translate("MainWindow", "Flying Chest", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_push), QApplication::translate("MainWindow", "Push", nullptr));
        pushButton_pull_up->setText(QApplication::translate("MainWindow", "Pull Up", nullptr));
        pushButton_chin_up->setText(QApplication::translate("MainWindow", "Chin Up", nullptr));
        pushButton_db_row->setText(QApplication::translate("MainWindow", "Dumbbell Row", nullptr));
        pushButton_barbell_row->setText(QApplication::translate("MainWindow", "Barbel Row", nullptr));
        pushButton_db_curl->setText(QApplication::translate("MainWindow", "Dumbbell Curl", nullptr));
        pushButton_barbell_curl->setText(QApplication::translate("MainWindow", "Barbell Curl", nullptr));
        pushButton_harmer_curl->setText(QApplication::translate("MainWindow", "Harmer Curl", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_pull), QApplication::translate("MainWindow", "Pull", nullptr));
        pushButton_db_spl_squat->setText(QApplication::translate("MainWindow", "Dumbbell Split Squat", nullptr));
        pushButton_db_roman_deadlift->setText(QApplication::translate("MainWindow", "Dumbbel Roman Deadlift", nullptr));
        pushButton_db_single_squat_bench->setText(QApplication::translate("MainWindow", "Dumbbell Single Squat Bench", nullptr));
        pushButton_db_front_squat->setText(QApplication::translate("MainWindow", "Dumbell Font Squat", nullptr));
        pushButton_db_goblet_squat->setText(QApplication::translate("MainWindow", "Dumbbell Goblet Squat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_leg), QApplication::translate("MainWindow", "Leg", nullptr));
        pushButton_eliptical->setText(QApplication::translate("MainWindow", "Ecliptical", nullptr));
        pushButton_sit_up->setText(QApplication::translate("MainWindow", "Sit Up", nullptr));
        pushButton_blank->setText(QApplication::translate("MainWindow", "Blank", nullptr));
        pushButton_side_blank->setText(QApplication::translate("MainWindow", "Side Blank", nullptr));
        pushButton_burpees->setText(QApplication::translate("MainWindow", "Burpees", nullptr));
        pushButton_rope_jump->setText(QApplication::translate("MainWindow", "Rope Jump", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_cardio), QApplication::translate("MainWindow", "Cardio", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushButton_pause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        label_total_remain_time->setText(QApplication::translate("MainWindow", "time remain", nullptr));
        label_excercise_list->setText(QApplication::translate("MainWindow", "Today Excercise List", nullptr));
        label_total_time->setText(QApplication::translate("MainWindow", "total time", nullptr));
        pushButton_delete->setText(QApplication::translate("MainWindow", "Delete ", nullptr));
        label->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_current_name->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_current_rep_text->setText(QApplication::translate("MainWindow", "Reps", nullptr));
        label_current_rep->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Set time", nullptr));
        label_current_set_time->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_current_rest_text->setText(QApplication::translate("MainWindow", "Rest Time", nullptr));
        label_current_rest_time->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_set_remain_text->setText(QApplication::translate("MainWindow", "Set remain", nullptr));
        label_set_remain->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_excercise_list_2->setText(QApplication::translate("MainWindow", "Current Excercise", nullptr));
        label_slash->setText(QApplication::translate("MainWindow", "/", nullptr));
        label_pause->setText(QApplication::translate("MainWindow", "Pausing!!!", nullptr));
        label_excercise_list_3->setText(QApplication::translate("MainWindow", "Timer ", nullptr));
        pushButton_skip->setText(QApplication::translate("MainWindow", "Skip", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Stage", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Remain", nullptr));
        label_timer_stage->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_timer_remain->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_song_name->setText(QApplication::translate("MainWindow", "Song name", nullptr));
        pushButton_music_back->setText(QString());
        pushButton_music->setText(QString());
        pushButton_music_next->setText(QString());
        checkBox_mix->setText(QApplication::translate("MainWindow", "Mix", nullptr));
        checkBox_loop->setText(QApplication::translate("MainWindow", "Loop", nullptr));
        pushButton_open_music->setText(QApplication::translate("MainWindow", "Open", nullptr));
        pushButton_clear_list->setText(QApplication::translate("MainWindow", "Clear list", nullptr));
        menuOption->setTitle(QApplication::translate("MainWindow", "Option", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
