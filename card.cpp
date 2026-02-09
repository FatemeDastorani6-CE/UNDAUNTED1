#include "card.h"

Card::Card(QString name, CardType type)
{
    this->name = name;
    this->type = type;
}

CardType Card::getType() const
{
    return type;
}
