#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QDialog>

namespace Ui {
class GameBoard;
}

class GameBoard : public QDialog
{
    Q_OBJECT

public:
    explicit GameBoard(const QString &MapName ,QWidget *parent = nullptr);
    ~GameBoard();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameBoard *ui;
    QString Select_M ;

};

#endif // GAMEBOARD_H
