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
    QVector<Card> drawPile;
    QVector<Card> discardPile;
    QVector<Card> removedPile;   // کارت‌های حذف‌شده از بازی
public:
    QVector<Card> cards;
    void initialize(const QString& owner);
    void shuffle();
    Card drawCard();
    void discard(const Card& card);
    bool isEmpty() const;
    int remaining() const;
    void removeFromGame(const Card& card);



};

#endif
