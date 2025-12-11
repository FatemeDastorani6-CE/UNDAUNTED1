/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Play;
    QLabel *label1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainwindow{\n"
"border-image: url(: /image/ back1.jpg)\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#QWidget{\n"
"background-image: url(\" :/ image/ back1.jpg\");\n"
"background-repeats: no-repeat;\n"
"background-position: center;\n"
"}"));
        Play = new QPushButton(centralwidget);
        Play->setObjectName("Play");
        Play->setGeometry(QRect(340, 430, 201, 51));
        Play->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", \"Arial\";\n"
"    padding: 12px 30px;\n"
"\n"
"    border-radius: 25px;\n"
"\n"
"    background: qlineargradient(\n"
"        x1:0 y1:0, x2:0 y2:1,\n"
"        stop:0 #cf8d37,\n"
"        stop:0.4 #e8c469,\n"
"        stop:0.6 #f0e3cf,\n"
"        stop:1 #cf8d37\n"
"    );\n"
"\n"
"    border: 2px solid #cf8d37;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0 y1:0, x2:0 y2:1,\n"
"        stop:0 #b98751,\n"
"        stop:0.4 #e2d4a8,\n"
"        stop:0.6 #f7eddb,\n"
"        stop:1 #b98751\n"
"    );\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1:0 y1:0, x2:0 y2:1,\n"
"        stop:0 #8c6138,\n"
"        stop:0.4 #c8b486,\n"
"        stop:0.6 #e3d3ba,\n"
"        stop:1 #8c6138\n"
"    );\n"
"    border: 2px solid #8c6138;\n"
"}"));
        label1 = new QLabel(centralwidget);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(0, -20, 900, 600));
        label1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Roboto\";\n"
"    font-size: 34px;\n"
"    font-weight: bold;\n"
"    color: #000000;            /* \331\205\330\264\332\251\333\214 */\n"
"\n"
"    background-color: #E6E6E6;  /* \330\267\331\210\330\263\333\214 \330\261\331\210\330\264\331\206 */\n"
"    border-radius: 15px;\n"
"    padding: 10px 20px;\n"
"    border: 2px solid #C8C8C8;\n"
"}\n"
"\n"
"/* \331\210\331\202\330\252\333\214 \331\205\331\210\330\263 \330\261\331\210\333\214 \330\257\332\251\331\205\331\207 \330\261\331\201\330\252 \333\214\330\247 \332\251\331\204\333\214\332\251 \330\264\330\257 */\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #7896FF;  /* \330\242\330\250\333\214 */\n"
"    border: 2px solid #5A78FF;\n"
"}"));
        label1->setPixmap(QPixmap(QString::fromUtf8(":/image/back1.jpg")));
        label1->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        label1->raise();
        Play->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
        label1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
