#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "agent.h"  // <-- همینجا AgentType رو میاره
#include <QVector>
#include <QRandomGenerator>
#include <algorithm>


#include <random>       // برای std::mt19937 و std::random_device
#include <QList>


class Deck {
private:
    QVector<Card> cards;
public:
    void initialize(const QString& owner);
    void shuffle();
    bool isEmpty() const;
    Card drawCard();
    int remaining() const;
};

#endif
