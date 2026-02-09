#ifndef CARD_H
#define CARD_H

#include <QString>

enum CardType {
    SCOUT,
    SNIPER,
    SERGEANT
};

class Card
{
public:
    Card(QString name = "", CardType type = SCOUT);
    CardType getType() const;

private:
    QString name;
    CardType type;
};

#endif
