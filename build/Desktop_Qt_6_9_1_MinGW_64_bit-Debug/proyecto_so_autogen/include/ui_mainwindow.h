/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_6;
    QTableWidget *tableWidget_procesos;
    QPushButton *pushButton_ejecutar;
    QLabel *label_resultado;
    QLabel *label_seleccion_alg;
    QRadioButton *radioButton_fcfs;
    QRadioButton *radioButton_sjf;
    QRadioButton *radioButton_rr;
    QRadioButton *radioButton_priority;
    QLabel *label_config_alg;
    QStackedWidget *stackedWidget_config;
    QWidget *roundRobinPage;
    QWidget *roundRobinWidget;
    QLabel *label_quantum;
    QLineEdit *quantumInput;
    QWidget *fcfsPage;
    QWidget *fcfsWidget;
    QLabel *label_fcfs;
    QWidget *sjfPage;
    QWidget *sjfWidget;
    QLabel *label_sjf;
    QWidget *priorityPage;
    QWidget *priorityWidget;
    QLabel *label_prioridad;
    QComboBox *comboBox_prioridad;
    QFrame *frame_7;
    QTableWidget *tableWidget_resultados;
    QLabel *label_avg_waiting_time;
    QLabel *label_avg_turnaround_time;
    QLabel *label_cpu_utilization;
    QLabel *label_proy_so;
    QFrame *frame_3;
    QLabel *label_num_procesos;
    QSpinBox *spinBox_num_procesos;
    QMenuBar *menubar;
    QMenu *menuProyecto_de_Sistemas_Operativos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1016, 592);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1001, 541));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: qlineargradient(spread:pad, x1:0.498, y1:1, x2:0.495673, y2:0.00028853, stop:0 rgba(255, 129, 0, 255), stop:1 rgba(255, 255, 255, 255))}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(220, 0, 781, 291));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color: rgb(248, 255, 243);\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 80, 781, 171));
        QFont font;
        font.setKerning(true);
        frame_6->setFont(font);
        frame_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border 0px;\n"
"}"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        frame_6->setLineWidth(0);
        tableWidget_procesos = new QTableWidget(frame_6);
        tableWidget_procesos->setObjectName("tableWidget_procesos");
        tableWidget_procesos->setGeometry(QRect(10, 10, 471, 151));
        tableWidget_procesos->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        pushButton_ejecutar = new QPushButton(frame_6);
        pushButton_ejecutar->setObjectName("pushButton_ejecutar");
        pushButton_ejecutar->setGeometry(QRect(560, 60, 111, 41));
        pushButton_ejecutar->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        label_resultado = new QLabel(frame_2);
        label_resultado->setObjectName("label_resultado");
        label_resultado->setGeometry(QRect(0, 250, 781, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        label_resultado->setFont(font1);
        label_resultado->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0,0,0);\n"
"}"));
        label_resultado->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_seleccion_alg = new QLabel(frame);
        label_seleccion_alg->setObjectName("label_seleccion_alg");
        label_seleccion_alg->setGeometry(QRect(0, 80, 221, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        label_seleccion_alg->setFont(font2);
        label_seleccion_alg->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0, 0, 0);\n"
"}"));
        label_seleccion_alg->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radioButton_fcfs = new QRadioButton(frame);
        radioButton_fcfs->setObjectName("radioButton_fcfs");
        radioButton_fcfs->setGeometry(QRect(10, 130, 201, 20));
        radioButton_sjf = new QRadioButton(frame);
        radioButton_sjf->setObjectName("radioButton_sjf");
        radioButton_sjf->setGeometry(QRect(10, 160, 201, 20));
        radioButton_rr = new QRadioButton(frame);
        radioButton_rr->setObjectName("radioButton_rr");
        radioButton_rr->setGeometry(QRect(10, 190, 201, 20));
        radioButton_priority = new QRadioButton(frame);
        radioButton_priority->setObjectName("radioButton_priority");
        radioButton_priority->setGeometry(QRect(10, 220, 201, 20));
        label_config_alg = new QLabel(frame);
        label_config_alg->setObjectName("label_config_alg");
        label_config_alg->setGeometry(QRect(0, 250, 221, 41));
        label_config_alg->setFont(font2);
        label_config_alg->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0,0,0);\n"
"}"));
        label_config_alg->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_config = new QStackedWidget(frame);
        stackedWidget_config->setObjectName("stackedWidget_config");
        stackedWidget_config->setGeometry(QRect(20, 370, 181, 161));
        stackedWidget_config->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(255, 255, 255,0.45);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(255, 255, 255,0.15);\n"
"}"));
        roundRobinPage = new QWidget();
        roundRobinPage->setObjectName("roundRobinPage");
        roundRobinWidget = new QWidget(roundRobinPage);
        roundRobinWidget->setObjectName("roundRobinWidget");
        roundRobinWidget->setGeometry(QRect(0, 20, 181, 141));
        label_quantum = new QLabel(roundRobinWidget);
        label_quantum->setObjectName("label_quantum");
        label_quantum->setGeometry(QRect(20, 40, 61, 21));
        label_quantum->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        quantumInput = new QLineEdit(roundRobinWidget);
        quantumInput->setObjectName("quantumInput");
        quantumInput->setGeometry(QRect(100, 40, 51, 21));
        stackedWidget_config->addWidget(roundRobinPage);
        fcfsPage = new QWidget();
        fcfsPage->setObjectName("fcfsPage");
        fcfsWidget = new QWidget(fcfsPage);
        fcfsWidget->setObjectName("fcfsWidget");
        fcfsWidget->setGeometry(QRect(0, 20, 181, 141));
        label_fcfs = new QLabel(fcfsWidget);
        label_fcfs->setObjectName("label_fcfs");
        label_fcfs->setGeometry(QRect(0, 40, 171, 21));
        stackedWidget_config->addWidget(fcfsPage);
        sjfPage = new QWidget();
        sjfPage->setObjectName("sjfPage");
        sjfWidget = new QWidget(sjfPage);
        sjfWidget->setObjectName("sjfWidget");
        sjfWidget->setGeometry(QRect(0, 20, 181, 141));
        label_sjf = new QLabel(sjfWidget);
        label_sjf->setObjectName("label_sjf");
        label_sjf->setGeometry(QRect(10, 40, 161, 21));
        stackedWidget_config->addWidget(sjfPage);
        priorityPage = new QWidget();
        priorityPage->setObjectName("priorityPage");
        priorityWidget = new QWidget(priorityPage);
        priorityWidget->setObjectName("priorityWidget");
        priorityWidget->setGeometry(QRect(0, 20, 181, 141));
        label_prioridad = new QLabel(priorityWidget);
        label_prioridad->setObjectName("label_prioridad");
        label_prioridad->setGeometry(QRect(30, 20, 111, 21));
        comboBox_prioridad = new QComboBox(priorityWidget);
        comboBox_prioridad->addItem(QString());
        comboBox_prioridad->addItem(QString());
        comboBox_prioridad->setObjectName("comboBox_prioridad");
        comboBox_prioridad->setGeometry(QRect(40, 50, 91, 21));
        stackedWidget_config->addWidget(priorityPage);
        frame_7 = new QFrame(frame);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(230, 300, 771, 211));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(255, 255, 255, 0.45);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(255, 255, 255, 0.15);\n"
"}\n"
"	"));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        tableWidget_resultados = new QTableWidget(frame_7);
        tableWidget_resultados->setObjectName("tableWidget_resultados");
        tableWidget_resultados->setGeometry(QRect(10, 10, 461, 191));
        tableWidget_resultados->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}\n"
""));
        label_avg_waiting_time = new QLabel(frame_7);
        label_avg_waiting_time->setObjectName("label_avg_waiting_time");
        label_avg_waiting_time->setGeometry(QRect(500, 80, 241, 31));
        label_avg_waiting_time->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        label_avg_waiting_time->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_avg_turnaround_time = new QLabel(frame_7);
        label_avg_turnaround_time->setObjectName("label_avg_turnaround_time");
        label_avg_turnaround_time->setGeometry(QRect(500, 20, 241, 31));
        label_avg_turnaround_time->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        label_avg_turnaround_time->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_cpu_utilization = new QLabel(frame_7);
        label_cpu_utilization->setObjectName("label_cpu_utilization");
        label_cpu_utilization->setGeometry(QRect(500, 140, 241, 31));
        label_cpu_utilization->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        label_cpu_utilization->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_proy_so = new QLabel(frame);
        label_proy_so->setObjectName("label_proy_so");
        label_proy_so->setGeometry(QRect(0, 0, 1001, 81));
        label_proy_so->setFont(font1);
        label_proy_so->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0,0,0);\n"
"}"));
        label_proy_so->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(220, 290, 781, 251));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(212, 249, 255);\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_num_procesos = new QLabel(frame);
        label_num_procesos->setObjectName("label_num_procesos");
        label_num_procesos->setGeometry(QRect(20, 305, 181, 21));
        label_num_procesos->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(255, 255, 255, 0.15);\n"
"}"));
        label_num_procesos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_num_procesos = new QSpinBox(frame);
        spinBox_num_procesos->setObjectName("spinBox_num_procesos");
        spinBox_num_procesos->setGeometry(QRect(80, 330, 61, 31));
        spinBox_num_procesos->setMinimum(2);
        spinBox_num_procesos->setMaximum(10);
        spinBox_num_procesos->setValue(10);
        frame_3->raise();
        frame_2->raise();
        label_seleccion_alg->raise();
        radioButton_fcfs->raise();
        radioButton_sjf->raise();
        radioButton_rr->raise();
        radioButton_priority->raise();
        label_config_alg->raise();
        stackedWidget_config->raise();
        frame_7->raise();
        label_proy_so->raise();
        label_num_procesos->raise();
        spinBox_num_procesos->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1016, 22));
        menuProyecto_de_Sistemas_Operativos = new QMenu(menubar);
        menuProyecto_de_Sistemas_Operativos->setObjectName("menuProyecto_de_Sistemas_Operativos");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuProyecto_de_Sistemas_Operativos->menuAction());

        retranslateUi(MainWindow);

        stackedWidget_config->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_ejecutar->setText(QCoreApplication::translate("MainWindow", "Ejecutar", nullptr));
        label_resultado->setText(QCoreApplication::translate("MainWindow", "Resultado", nullptr));
        label_seleccion_alg->setText(QCoreApplication::translate("MainWindow", "Selecci\303\263n de Algoritmo", nullptr));
        radioButton_fcfs->setText(QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        radioButton_sjf->setText(QCoreApplication::translate("MainWindow", "SJF", nullptr));
        radioButton_rr->setText(QCoreApplication::translate("MainWindow", "Round Robin", nullptr));
        radioButton_priority->setText(QCoreApplication::translate("MainWindow", "Prioridades", nullptr));
        label_config_alg->setText(QCoreApplication::translate("MainWindow", "Configuraci\303\263n del Algoritmo", nullptr));
        label_quantum->setText(QCoreApplication::translate("MainWindow", "Quantum", nullptr));
        label_fcfs->setText(QCoreApplication::translate("MainWindow", "FCFS no requiere configuraci\303\263n", nullptr));
        label_sjf->setText(QCoreApplication::translate("MainWindow", "SJF no requiere configuraci\303\263n", nullptr));
        label_prioridad->setText(QCoreApplication::translate("MainWindow", "Modo de Prioridad", nullptr));
        comboBox_prioridad->setItemText(0, QCoreApplication::translate("MainWindow", "Con Desalojo", nullptr));
        comboBox_prioridad->setItemText(1, QCoreApplication::translate("MainWindow", "Sin Desalojo", nullptr));

        label_avg_waiting_time->setText(QCoreApplication::translate("MainWindow", "Tiempo promedio de espera", nullptr));
        label_avg_turnaround_time->setText(QCoreApplication::translate("MainWindow", "Tiempo promedio de espera", nullptr));
        label_cpu_utilization->setText(QCoreApplication::translate("MainWindow", "Utilizaci\303\263n de la CPU", nullptr));
        label_proy_so->setText(QCoreApplication::translate("MainWindow", "Proyecto de Sistemas Operativos", nullptr));
        label_num_procesos->setText(QCoreApplication::translate("MainWindow", "N\303\272mero de procesos", nullptr));
        menuProyecto_de_Sistemas_Operativos->setTitle(QCoreApplication::translate("MainWindow", "Proyecto de Sistemas Operativos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
