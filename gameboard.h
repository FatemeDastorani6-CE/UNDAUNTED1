#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QDialog>
#include <QVector>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>


#include "agent.h"    // برای نمایش مهره‌ها
#include "map.h"      // Map واقعی با neighbors


class GameBoard : public QDialog
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

    void updateBoardView();

    void loadMap(const QString &phase1Path, const QString &phase2Path);
    QVector<MapCell> cells; // فرضا برای کل خانه‌ها

private:
    QWidget *boardWidget;
    QGridLayout *gridLayout;
    Map* gameMap;
    QVector<QVector<MapCell>> mapCells;

    QString getImageForLevel(int level);

    const int tileW = 80;
    const int tileH = 80;
};

#endif // GAMEBOARD_H
