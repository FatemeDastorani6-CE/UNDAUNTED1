#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include "card.h"

class Player
{
public:
    Player();

    void initDeck();

    Card playCard(int index);
    void addToHand(const Card &c);

    const QVector<Card>& getHand() const;

private:
    QVector<Card> deck;
    QVector<Card> hand;
    QVector<Card> discard;
};

#endif
