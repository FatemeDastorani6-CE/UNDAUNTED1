#include "gameboard.h"
#include "ui_gameboard.h"
#include "QDebug"

GameBoard::GameBoard(const QString &MapName ,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameBoard)
{
    ui->setupUi(this);

    Select_M = MapName ;

    qDebug() << "selected map :" << Select_M ;
}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::on_pushButton_clicked()
{

}

