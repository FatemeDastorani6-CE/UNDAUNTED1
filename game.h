#ifndef GAME_H
#define GAME_H

#include "player.h"

enum PendingAction {
    NONE,
    SCOUT_MOVE,
    SNIPER_ATTACK,
    SERGEANT_RELEASE
};

class Game
{
public:
    Game();

    void startGame();
    void endTurn();

    void playCard(int index);

    void moveScout(int row, int col);
    void sniperAttack(int row, int col);
    void sergeantRelease();

    PendingAction getPendingAction() const;

private:
    Player players[2];
    int currentTurn;
    PendingAction pendingAction;

    int scoutRow;
    int scoutCol;
};

#endif
