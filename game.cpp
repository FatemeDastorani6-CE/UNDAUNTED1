#include "game.h"
#include <QDebug>

Game::Game()
{
    currentTurn = 0;
    pendingAction = NONE;
    scoutRow = -1;
    scoutCol = -1;
}

void Game::startGame()
{
    for (int i = 0; i < 2; i++) {
        players[i].initDeck();
        players[i].shuffleDeck();
        players[i].drawCard();
        players[i].drawCard();
    }
}

void Game::endTurn()
{
    pendingAction = NONE;
    currentTurn = 1 - currentTurn;
    players[currentTurn].drawCard();

    qDebug() << "Turn changed. Current player:" << currentTurn;
}

void Game::playCard(int index)
{
    Card c = players[currentTurn].playCard(index);

    if (c.getType() == SCOUT)
        pendingAction = SCOUT_MOVE;
    else if (c.getType() == SNIPER)
        pendingAction = SNIPER_ATTACK;
    else if (c.getType() == SERGEANT)
        pendingAction = SERGEANT_RELEASE;
}

PendingAction Game::getPendingAction() const
{
    return pendingAction;
}


void Game::moveScout(int row, int col)
{
    scoutRow = row;
    scoutCol = col;

    qDebug() << "Scout moved to:" << row << col;

    endTurn();
}

void Game::sniperAttack(int row, int col)
{
    qDebug() << "Sniper attacked enemy at:" << row << col;

    endTurn();
}

void Game::sergeantRelease()
{
    qDebug() << "Sergeant used";

    endTurn();
}
