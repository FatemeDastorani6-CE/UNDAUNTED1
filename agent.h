#ifndef AGENT_H
#define AGENT_H


#include <QString>
#include <QVector>
#include "map.h"

enum class AgentType { Scout, Sniper, Sergeant };
class DiceResult;

class Agent {

protected:
    QString owner;     // "A" یا "B"
    int hp;
    MapCell* position;

public:
    Agent(const QString& owner, MapCell* start);
    virtual ~Agent();

    virtual int diceCount() const = 0;
    DiceResult rollDice() const;

    QString getOwner() const;
    int getHp() const;
    MapCell* getPosition() const;

    bool moveTo(MapCell* dest);

    virtual QVector<MapCell*> possibleMoves() = 0;

    virtual int calculateAttackValue(const QVector<MapCell*>& path, Agent* target) const = 0;
};

#endif // AGENT_H
