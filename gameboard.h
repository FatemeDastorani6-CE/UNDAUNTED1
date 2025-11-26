#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QString>
#include <QVector>
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

    void loadMap(const QString& fileName);     // مثلاً ":/maps/1.txt"
    void namayeshMap(const QMap<QString, int>& m);

};

#endif // GAMEBOARD_H
