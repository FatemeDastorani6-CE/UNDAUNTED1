#include "sniper.h"
#include <QRandomGenerator>

Sniper::Sniper(const QString& owner, MapCell* start)
    : Agent(owner, start)
{
    hp = 4;
}

// Move فقط به خانه‌های دیده‌بانی شده
QVector<MapCell*> Sniper::possibleMoves() {
    QVector<MapCell*> res;
    for(MapCell* n : position->neighbors){
        if(owner=="A" && n->scoutedByA) res.push_back(n);
        if(owner=="B" && n->scoutedByB) res.push_back(n);
    }
    return res;
}



// معیار حمله
int Sniper::calculateAttackValue(const QVector<MapCell*>& path,
                                 Agent* target) const
{
    int sum = target->getHp();
    for(MapCell* c : path)
        sum += c->level;
    return sum;
}

// حمله با 3 تاس
bool Sniper::attackAgent(Agent* target) {
    QVector<MapCell*> path = bfs(position, target->getPosition());
    if(path.isEmpty()) return false;

    int attackValue = calculateAttackValue(path, target);
    bool success = false;

    for(int i=0; i<diceCount(); i++){
        int roll = QRandomGenerator::global()->bounded(1,11); // 1 تا 10
        if(roll >= attackValue) success = true;
    }

    return success;
}
