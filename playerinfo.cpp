#include "playerinfo.h"
#include "ui_playerinfo.h"
#include "selectmap.h"
#include <qmessagebox.h>


bool PlayerInfo :: CheckName ( const QString &name ) {
    if (name.length() < 8)
        return false;

    if (!name[0].isLetter())
        return false;

    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasSpecial = false;

    QString specials = "!@#$%^&*()_+-=[]{}|;:'\",.<>/?";

    for (QChar c : name)
    {
        if (c.isDigit()) hasDigit = true;
        if (c.isUpper()) hasUpper = true;
        if (c.isLower()) hasLower = true;
        if (specials.contains(c)) hasSpecial = true;
    }

    return hasDigit && hasUpper && hasLower && hasSpecial;
}

PlayerInfo::PlayerInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerInfo)
{
    ui->setupUi(this);
}

PlayerInfo::~PlayerInfo()
{
    delete ui;
}

void PlayerInfo::on_Next_clicked()
{
    QString name1 = ui->player1->text();
    QString name2 = ui->player2->text();

    if (name1.isEmpty() || name2.isEmpty()) {
        QMessageBox::warning(this, "Error", "نام هر دو بازیکن را وارد کنید.");
        return;
    }

    if (!CheckName(name1)) {
        QMessageBox::warning(this, "Error", "نام بازیکن اول معتبر نیست!");
        return;
    }

    if (!CheckName(name2)) {
        QMessageBox::warning(this, "Error", "نام بازیکن دوم معتبر نیست!");
        return;
    }
    SelectMap sm ;
    sm.exec() ;
}

