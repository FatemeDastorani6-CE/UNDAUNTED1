/********************************************************************************
** Form generated from reading UI file 'selectmap.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTMAP_H
#define UI_SELECTMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SelectMap
{
public:
    QLabel *background3Label;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QRadioButton *radioButton5;
    QPushButton *OK;

    void setupUi(QDialog *SelectMap)
    {
        if (SelectMap->objectName().isEmpty())
            SelectMap->setObjectName("SelectMap");
        SelectMap->resize(900, 600);
        background3Label = new QLabel(SelectMap);
        background3Label->setObjectName("background3Label");
        background3Label->setGeometry(QRect(0, 0, 900, 600));
        background3Label->setToolTipDuration(-1);
        background3Label->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-image: url(\":/image/mao.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}"));
        background3Label->setPixmap(QPixmap(QString::fromUtf8(":/image/map1.jpg")));
        background3Label->setScaledContents(true);
        radioButton1 = new QRadioButton(SelectMap);
        radioButton1->setObjectName("radioButton1");
        radioButton1->setGeometry(QRect(215, 149, 200, 200));
        radioButton1->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    border: 2px solid #b5712f;\n"
"    background-color: #452b13;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid #efdac7;\n"
"    background-color: #efdac7;\n"
"    border-radius: 9px;\n"
"}"));
        radioButton2 = new QRadioButton(SelectMap);
        radioButton2->setObjectName("radioButton2");
        radioButton2->setGeometry(QRect(390, 150, 200, 200));
        radioButton2->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    border: 2px solid #b5712f;\n"
"    background-color: #452b13;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid #efdac7;\n"
"    background-color: #efdac7;\n"
"    border-radius: 9px;\n"
"}"));
        radioButton3 = new QRadioButton(SelectMap);
        radioButton3->setObjectName("radioButton3");
        radioButton3->setGeometry(QRect(570, 150, 200, 200));
        radioButton3->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    border: 2px solid #b5712f;\n"
"    background-color: #452b13;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid #efdac7;\n"
"    background-color: #efdac7;\n"
"    border-radius: 9px;\n"
"}"));
        radioButton4 = new QRadioButton(SelectMap);
        radioButton4->setObjectName("radioButton4");
        radioButton4->setGeometry(QRect(298, 310, 200, 200));
        radioButton4->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    border: 2px solid #b5712f;\n"
"    background-color: #452b13;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid #efdac7;\n"
"    background-color: #efdac7;\n"
"    border-radius: 9px;\n"
"}"));
        radioButton5 = new QRadioButton(SelectMap);
        radioButton5->setObjectName("radioButton5");
        radioButton5->setGeometry(QRect(485, 310, 200, 200));
        radioButton5->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    border: 2px solid #b5712f;\n"
"    background-color: #452b13;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid #efdac7;\n"
"    background-color: #efdac7;\n"
"    border-radius: 9px;\n"
"}"));
        OK = new QPushButton(SelectMap);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(310, 460, 281, 51));
        OK->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", \"Arial\";\n"
"    padding: 12px 30px;\n"
"\n"
"    border-radius: 20px;\n"
"\n"
"    background: qlineargradient(\n"
"        x1:0 y1:0, x2:0 y2:1,\n"
"        stop:0 #a77749,\n"
"        stop:0.4 #d9c89d,\n"
"        stop:0.6 #f0e3cf,\n"
"        stop:1 #a77749\n"
"    );\n"
"\n"
"    border: 2px solid #a77749;\n"
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

        retranslateUi(SelectMap);

        QMetaObject::connectSlotsByName(SelectMap);
    } // setupUi

    void retranslateUi(QDialog *SelectMap)
    {
        SelectMap->setWindowTitle(QCoreApplication::translate("SelectMap", "Dialog", nullptr));
        background3Label->setText(QString());
        radioButton1->setText(QString());
        radioButton2->setText(QString());
        radioButton3->setText(QString());
        radioButton4->setText(QString());
        radioButton5->setText(QString());
        OK->setText(QCoreApplication::translate("SelectMap", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectMap: public Ui_SelectMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMAP_H
