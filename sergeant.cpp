#include "sergeant.h"
#include <QRandomGenerator>

Sergeant::Sergeant(const QString& owner, MapCell* start)
    : Agent(owner, start)
{
    hp = 3;
}

// Move فقط به خانه‌های دیده‌بانی شده
QVector<MapCell*> Sergeant::possibleMoves() {
    QVector<MapCell*> res;
    for(MapCell* n : position->neighbors){
        if(owner=="A" && n->scoutedByA) res.push_back(n);
        if(owner=="B" && n->scoutedByB) res.push_back(n);
    }
    return res;
}



// معیار حمله
int Sergeant::calculateAttackValue(const QVector<MapCell*>& path,
                                   Agent* target) const
{
    int sum = target->getHp();
    for(MapCell* c : path)
        sum += c->level;
    return sum;
}

// حمله با 1 تاس
bool Sergeant::attackAgent(Agent* target) {
    QVector<MapCell*> path = bfs(position, target->getPosition());
    if(path.isEmpty()) return false;

    int attackValue = calculateAttackValue(path, target);
    int roll = QRandomGenerator::global()->bounded(1,11); // 1 تا 10

    return roll >= attackValue;
}

// Control
void Sergeant::controlCell(MapCell* cell) {
    if(cell->occupant) return;
    cell->control = (owner=="A") ? ControlledByA : ControlledByB;
}

// Release
void Sergeant::releaseCell(MapCell* cell) {
    if(cell->occupant) return;
    if(owner=="A" && cell->control==ControlledByB) cell->control = Neutral;
    if(owner=="B" && cell->control==ControlledByA) cell->control = Neutral;
}
