#pragma once
#include <QWidget>
#include <QMap>
#include "mapcell.h"

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = nullptr);
    void loadMap(const QString &mapFile, const QString &pieceFile);

private:
    QMap<QString, MapCell*> cells;

    void clearUI();
    void createMapUI();
    void setupNeighbors();
};
