#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QDialog>
#include <QVector>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>

struct MapCell {
    QString name;
    int level;
};

class GameBoard : public QDialog
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

    void loadMap(const QString &path);

private:
    QWidget *boardWidget;
    QGridLayout *gridLayout;
    QVector<QVector<MapCell>> mapCells;

    QString getImageForLevel(int level);

    const int tileW = 80;
    const int tileH = 80;
};

#endif // GAMEBOARD_H
