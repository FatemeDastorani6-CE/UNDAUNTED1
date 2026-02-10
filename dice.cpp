#include "dice.h"
#include <QRandomGenerator>

int DiceResult::sum() const {
    int s = 0;
    for(int v : values) s += v;
    return s;
}

DiceResult Dice::roll(int count) {
    DiceResult r;
    for(int i = 0; i < count; ++i) {
        r.values.append(QRandomGenerator::global()->bounded(1, 11));
    }
    return r;
}
