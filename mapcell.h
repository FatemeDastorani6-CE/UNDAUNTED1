#ifndef MAPCELL_H
#define MAPCELL_H

#include <QString>

class MapCell
{
public:
    MapCell() : name(""), level(0) {}
    MapCell(const QString& name, int level) : name(name), level(level) {}

    QString getName() const { return name; }
    int getLevel() const { return level; }

private:
    QString name;
    int level;
};

#endif // MAPCELL_H
