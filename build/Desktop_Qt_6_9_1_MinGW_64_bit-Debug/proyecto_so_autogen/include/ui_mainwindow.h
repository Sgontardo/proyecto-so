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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QLabel *label_7;
    QLabel *label_3;
    QRadioButton *radioButton_fcfs;
    QRadioButton *radioButton_sjf;
    QRadioButton *radioButton_rr;
    QRadioButton *radioButton_priority;
    QLabel *label_4;
    QStackedWidget *stackedWidget_config;
    QWidget *roundRobinPage;
    QWidget *roundRobinWidget;
    QLabel *label_5;
    QLineEdit *quantumInput;
    QWidget *page_2;
    QWidget *widget_2;
    QFrame *frame_7;
    QTableWidget *tableWidget_resultados;
    QLabel *label_6;
    QLabel *label_8;
    QFrame *frame_3;
    QMenuBar *menubar;
    QMenu *menuProyecto_de_Sistemas_Operativos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(815, 570);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 801, 521));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: qlineargradient(spread:pad, x1:0.498, y1:1, x2:0.495673, y2:0.00028853, stop:0 rgba(255, 129, 0, 255), stop:1 rgba(255, 255, 255, 255))}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(220, 0, 581, 291));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color: rgb(248, 255, 243);\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 80, 581, 171));
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
        tableWidget_procesos->setGeometry(QRect(10, 10, 451, 151));
        tableWidget_procesos->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        pushButton_ejecutar = new QPushButton(frame_6);
        pushButton_ejecutar->setObjectName("pushButton_ejecutar");
        pushButton_ejecutar->setGeometry(QRect(470, 60, 91, 41));
        pushButton_ejecutar->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 250, 581, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0,0,0);\n"
"}"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 80, 221, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0, 0, 0);\n"
"}"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
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
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 250, 221, 41));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0,0,0);\n"
"}"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_config = new QStackedWidget(frame);
        stackedWidget_config->setObjectName("stackedWidget_config");
        stackedWidget_config->setGeometry(QRect(20, 320, 181, 161));
        stackedWidget_config->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(255, 255, 255,0.45);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(255, 255, 255,0.15);\n"
"}"));
        roundRobinPage = new QWidget();
        roundRobinPage->setObjectName("roundRobinPage");
        roundRobinWidget = new QWidget(roundRobinPage);
        roundRobinWidget->setObjectName("roundRobinWidget");
        roundRobinWidget->setGeometry(QRect(10, 30, 161, 101));
        label_5 = new QLabel(roundRobinWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 40, 61, 21));
        label_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        quantumInput = new QLineEdit(roundRobinWidget);
        quantumInput->setObjectName("quantumInput");
        quantumInput->setGeometry(QRect(100, 40, 51, 21));
        stackedWidget_config->addWidget(roundRobinPage);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 20, 161, 121));
        stackedWidget_config->addWidget(page_2);
        frame_7 = new QFrame(frame);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(230, 300, 561, 211));
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
        label_6 = new QLabel(frame_7);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(490, 90, 51, 31));
        label_6->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgba(125, 151, 255, 0.15);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgba(125, 151, 255, 0.15);\n"
"}"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 0, 801, 81));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0,0,0);\n"
"}"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(220, 290, 581, 251));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(212, 249, 255);\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        frame_3->raise();
        frame_2->raise();
        label_3->raise();
        radioButton_fcfs->raise();
        radioButton_sjf->raise();
        radioButton_rr->raise();
        radioButton_priority->raise();
        label_4->raise();
        stackedWidget_config->raise();
        frame_7->raise();
        label_8->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 815, 22));
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
        label_7->setText(QCoreApplication::translate("MainWindow", "Resultado", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Selecci\303\263n de Algoritmo", nullptr));
        radioButton_fcfs->setText(QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        radioButton_sjf->setText(QCoreApplication::translate("MainWindow", "SJF", nullptr));
        radioButton_rr->setText(QCoreApplication::translate("MainWindow", "Round Robin", nullptr));
        radioButton_priority->setText(QCoreApplication::translate("MainWindow", "Prioridades", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Configuraci\303\263n del Algoritmo", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Quantum", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "T.P", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Proyecto de Sistemas Operativos", nullptr));
        menuProyecto_de_Sistemas_Operativos->setTitle(QCoreApplication::translate("MainWindow", "Proyecto de Sistemas Operativos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
