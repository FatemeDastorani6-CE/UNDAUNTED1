#pragma once
#include <QVector>

class DiceResult {
public:
    QVector<int> values;   // مثلا {3, 7, 10}
    int sum() const;
};

class Dice {
public:
    static DiceResult roll(int count); // تعداد تاس
};
