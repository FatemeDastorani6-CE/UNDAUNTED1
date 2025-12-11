/********************************************************************************
** Form generated from reading UI file 'gameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_centeralWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *mainLayout;

    void setupUi(QDialog *centeralWidget)
    {
        if (centeralWidget->objectName().isEmpty())
            centeralWidget->setObjectName("centeralWidget");
        centeralWidget->resize(900, 600);
        gridLayoutWidget = new QWidget(centeralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 611));
        mainLayout = new QGridLayout(gridLayoutWidget);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(centeralWidget);

        QMetaObject::connectSlotsByName(centeralWidget);
    } // setupUi

    void retranslateUi(QDialog *centeralWidget)
    {
        centeralWidget->setWindowTitle(QCoreApplication::translate("centeralWidget", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class centeralWidget: public Ui_centeralWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
