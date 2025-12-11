/********************************************************************************
** Form generated from reading UI file 'playerinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERINFO_H
#define UI_PLAYERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PlayerInfo
{
public:
    QLabel *label;
    QLineEdit *player1;
    QLineEdit *player2;
    QPushButton *Next;

    void setupUi(QDialog *PlayerInfo)
    {
        if (PlayerInfo->objectName().isEmpty())
            PlayerInfo->setObjectName("PlayerInfo");
        PlayerInfo->resize(900, 600);
        label = new QLabel(PlayerInfo);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 900, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/back2.jpeg")));
        label->setScaledContents(true);
        player1 = new QLineEdit(PlayerInfo);
        player1->setObjectName("player1");
        player1->setGeometry(QRect(145, 236, 251, 41));
        player1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: #00000;\n"
"    color: #fdf8f2;\n"
"    border: 2px solid #808080;\n"
"    border-radius:10px;\n"
"    padding: 10px 15px;\n"
"    font-size: 18px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #d39457; /* \331\207\331\206\332\257\330\247\331\205 \332\251\331\204\333\214\332\251 */\n"
"    background: #000000;\n"
"}"));
        player2 = new QLineEdit(PlayerInfo);
        player2->setObjectName("player2");
        player2->setGeometry(QRect(510, 236, 251, 41));
        player2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: #00000;\n"
"    color: #fdf8f2;\n"
"    border: 2px solid #808080;\n"
"    border-radius:10px;\n"
"    padding: 10px 15px;\n"
"    font-size: 18px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #d39457; /* \331\207\331\206\332\257\330\247\331\205 \332\251\331\204\333\214\332\251 */\n"
"    background: #000000;\n"
"}"));
        Next = new QPushButton(PlayerInfo);
        Next->setObjectName("Next");
        Next->setGeometry(QRect(352, 377, 210, 53));
        Next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: black;\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", \"Arial\";\n"
"    padding: 12px 30px;\n"
"\n"
"    border-radius: 15px;\n"
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

        retranslateUi(PlayerInfo);

        QMetaObject::connectSlotsByName(PlayerInfo);
    } // setupUi

    void retranslateUi(QDialog *PlayerInfo)
    {
        PlayerInfo->setWindowTitle(QCoreApplication::translate("PlayerInfo", "Dialog", nullptr));
        label->setText(QString());
        player1->setPlaceholderText(QCoreApplication::translate("PlayerInfo", "Enter Player1 Name", nullptr));
        player2->setPlaceholderText(QCoreApplication::translate("PlayerInfo", "Enter Player2 Name", nullptr));
        Next->setText(QCoreApplication::translate("PlayerInfo", "NEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerInfo: public Ui_PlayerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERINFO_H
