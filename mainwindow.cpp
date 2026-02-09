#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerinfo.h"
#include "gameboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label1->lower();

    game.startGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Play_clicked()
{
    hide();

    PlayerInfo dlg(this);
    if (dlg.exec() == QDialog::Accepted) {

        GameBoard *board = new GameBoard(&game, this);
        board->loadMap(":/map/1.txt");
        board->show();
    }
}
