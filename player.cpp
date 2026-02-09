#include "player.h"

Player::Player()
{
    initDeck();
}

void Player::initDeck()
{
    deck.clear();
    hand.clear();
    discard.clear();

    deck.push_back(Card(SCOUT));
    deck.push_back(Card(SCOUT));
    deck.push_back(Card(SCOUT));
    deck.push_back(Card(SNIPER));
    deck.push_back(Card(SERGEANT));

    for (int i = 0; i < 3; i++) {
        hand.push_back(deck.back());
        deck.pop_back();
    }
}

Card Player::playCard(int index)
{
    Card c = hand[index];
    hand.removeAt(index);
    discard.push_back(c);
    return c;
}

void Player::addToHand(const Card &c)
{
    hand.push_back(c);
}

const QVector<Card>& Player::getHand() const
{
    return hand;
}
