#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include "game.h"

class GameBoard : public QDialog
{
    Q_OBJECT
public:
    explicit GameBoard(Game *g, QWidget *parent = nullptr);
    ~GameBoard();

    void loadMap(const QString &path);
    void updateHandUI();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Game *game;

    QWidget *handWidget;
    QHBoxLayout *handLayout;
    QVector<QPushButton*> cardButtons;
};

#endif
