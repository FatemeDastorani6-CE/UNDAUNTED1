#include "card.h"

// تعریف سازنده
Card::Card(QString name, CardType type)
    : name(name), type(type)
{
}

// تعریف تابع getType
CardType Card::getType() const {
    return type;
}
