#include "gameboard.h"
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QDebug>

GameBoard::GameBoard(QWidget *parent) : QWidget(parent) {}

void GameBoard::clearUI()
{
    QList<QWidget*> members = this->findChildren<QWidget*>();
    for(int i=0;i<members.size();++i) delete members[i];

    qDeleteAll(cells);
    cells.clear();
}

void GameBoard::loadMap(const QString &mapFile, const QString &pieceFile)
{
    clearUI();

    // بارگذاری سطح کارت‌ها
    QFile file(mapFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);

    while(!in.atEnd()){
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList parts = line.split('|', QString::SkipEmptyParts);
        for(const QString &p : parts){
            QStringList sub = p.split(':');
            if(sub.size()!=2) continue;

            MapCell* cell = new MapCell;
            cell->id = sub[0].trimmed();
            cell->level = sub[1].trimmed().toInt();
            cells[cell->id] = cell;
        }
    }

    // بارگذاری مالک و مهره‌ها
    QFile f(pieceFile);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream pin(&f);

    while(!pin.atEnd()){
        QString line = pin.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList parts = line.split(':');
        if(parts.size()!=2) continue;

        QString id = parts[0].trimmed();
        if(!cells.contains(id)) continue;
        MapCell* cell = cells[id];

        QStringList props = parts[1].split(',');
        for(const QString &p : props){
            QString prop = p.trimmed();
            if(prop=="A" || prop=="B") cell->owner = prop;
            else if(prop=="Mark"){
                if(cell->owner=="A") cell->markedByA=true;
                else if(cell->owner=="B") cell->markedByB=true;
            }
            else if(prop=="Control"){
                if(cell->owner=="A") cell->controlledByA=true;
                else if(cell->owner=="B") cell->controlledByB=true;
            }
            else if(prop=="Sniper" || prop=="Scout" || prop=="Seargeant")
                cell->pieceType = prop;
        }
    }

    createMapUI();
    setupNeighbors();
}

void GameBoard::createMapUI()
{
    for(MapCell* cell : cells){
        QPushButton* btn = new QPushButton(this);
        QString text = QString("%1\nLvl:%2").arg(cell->id).arg(cell->level);
        if(!cell->owner.isEmpty()) text += "\n" + cell->owner;
        if(!cell->pieceType.isEmpty()) text += "\n" + cell->pieceType;
        if(cell->markedByA || cell->markedByB) text += "\nMark";
        if(cell->controlledByA || cell->controlledByB) text += "\nControl";

        btn->setText(text);
        btn->setFixedSize(60,60);
        cell->widget = btn;

        // موقعیت ساده
        int row = cell->id.mid(1).toInt() - 1;
        int col = cell->id[0].unicode() - 'A';
        int x = col * 55 + (row % 2) * 27;
        int y = row * 50;
        btn->move(x, y);
        btn->show();
    }
}

void GameBoard::setupNeighbors()
{
    // نمونه Hex: هر کارت ۶ همسایه فرضی
    QMap<QString, QList<QString>> neighborMap;
    // برای هر کارت اسم همسایه‌ها را اینجا مشخص کن
    // مثلا neighborMap["A01"] = {"A02","B01","..."};

    for(auto it=cells.begin(); it!=cells.end(); ++it){
        MapCell* c = it.value();
        if(neighborMap.contains(c->id)){
            for(QString nid : neighborMap[c->id]){
                if(cells.contains(nid)) c->neighbors.append(cells[nid]);
            }
        }
    }
}
