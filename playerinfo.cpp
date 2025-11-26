#include "playerinfo.h"
#include "ui_playerinfo.h"
#include <qmessagebox.h>
#include "selectmap.h"
#include "gameboard.h"


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
        QMessageBox::warning(this, "Error", "please eneter names of both players.");
        return;
    }

    if (!CheckName(name1)) {
        QMessageBox::warning(this, "Error", "The first player name is not valid!");
        return;
    }

    if (!CheckName(name2)) {
        QMessageBox::warning(this, "Error", "The second player name is not valid!");
        return;
    }



    SelectMap dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString mapPath;

        switch (dialog.selectedMapNumber) {
        case 1: mapPath = ":/map/1.txt"; break;
        case 2: mapPath = ":/map/2.txt"; break;
        case 3: mapPath = ":/map/3.txt"; break;
        case 4: mapPath = ":/map/4.txt"; break;
        case 5: mapPath = ":/map/5.txt"; break;
        }

        hide();
        GameBoard* game = new GameBoard();
        game->loadMap(mapPath);   // این تابع قبلاً نوشتی
        game->show();
    }

}

