#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QDialog>
#include <QVector>
#include <QLabel>
#include <QWidget>

class MapCell {
public:
    QString name;
    int level;

    QString agentType;   // Sniper / Scout / Sergeant
    char agentOwner;     // A / B

    bool markedByA;
    bool markedByB;

    bool controlledByA;
    bool controlledByB;

    MapCell();

    bool isMarkedBy(char player) const;
    void setMarkedBy(char player);

    bool hasAgent() const;

    bool isControlledBy(char player) const;
    void setControlledBy(char player);
};

class GameBoard : public QDialog
{
    Q_OBJECT

public:
    GameBoard(QWidget *p = nullptr);
    ~GameBoard();

    void loadMap(const QString &path);
    void loadAgents(const QString &path);

private:
    QWidget *boardWidget;
    QVector<QVector<MapCell>> mapCells;

    QString getImageForLevel(int level);
    void updateBoardUI();

    const int tileW = 80;
    const int tileH = 80;
};

#endif
