#include "agent.h"
#include "dice.h"

DiceResult Agent::rollDice() const {
    return Dice::roll(diceCount());
}


Agent::Agent(const QString& owner, MapCell* start)
    : owner(owner), position(start)
{
    if(position)
        position->occupant = this;
}

Agent::~Agent() {}

QString Agent::getOwner() const {
    return owner;
}

int Agent::getHp() const {
    return hp;
}

MapCell* Agent::getPosition() const {
    return position;
}

bool Agent::moveTo(MapCell* dest) {
    if(!dest) return false;
    if(dest->occupant) return false;
    if(!position->neighbors.contains(dest)) return false;

    position->occupant = nullptr;
    dest->occupant = this;
    position = dest;
    return true;
}
