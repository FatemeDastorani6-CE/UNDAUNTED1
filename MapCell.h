#ifndef MAPCELL_H
#define MAPCELL_H



#include <QString>
#include <QVector>

class Agent;

enum ControlStatus { Neutral, ControlledByA, ControlledByB };

struct MapCell {
    QString name;
    int level;

    // دیده‌بانی
    bool scoutedByA = false;
    bool scoutedByB = false;

    // کنترل
    ControlStatus control = Neutral;

    // چه مهره‌ای روی خانه است
    Agent* occupant = nullptr;

    // همسایه‌ها
    QVector<MapCell*> neighbors;
};


#endif // MAPCELL_H
