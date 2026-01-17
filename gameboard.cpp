#include "gameboard.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPixmap>
#include <QVBoxLayout>

MapCell::MapCell()
    : level(0),
    agentOwner('-'),
    markedByA(false),
    markedByB(false),
    controlledByA(false),
    controlledByB(false)
{}

bool MapCell::isMarkedBy(char player) const {
    return (player=='A') ? markedByA : markedByB;
}

void MapCell::setMarkedBy(char player){
    if(player=='A') markedByA = true;
    else markedByB = true;
}

bool MapCell::hasAgent() const {
    return !agentType.isEmpty();
}

bool MapCell::isControlledBy(char player) const {
    return (player=='A') ? controlledByA : controlledByB;
}

void MapCell::setControlledBy(char player) {
    if(player=='A') controlledByA = true;
    else controlledByB = true;
}

// --------------------- GameBoard ---------------------

GameBoard::GameBoard(QWidget *p)
    : QDialog(p)
{
    this->showFullScreen();

    boardWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(boardWidget);
    boardWidget->setStyleSheet("background-color: #8FBC8F;");
}

GameBoard::~GameBoard() {}

QString GameBoard::getImageForLevel(int level){
    switch (level) {
    case 0: return ":/card/image0.JPG";
    case 1: return ":/card/image1.JPG";
    case 2: return ":/card/image2.JPG";
    default: return ":/card/image0.JPG";
    }
}

// --------------------- loadMap ---------------------
void GameBoard::loadMap(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Cannot open the file:" << path;
        return;
    }

    QTextStream in(&file);
    mapCells.clear();

    while(!in.atEnd()){
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList parts = line.split('|', Qt::SkipEmptyParts);
        QVector<MapCell> row;
        for(QString p : parts){
            QStringList sub = p.split(':');
            if(sub.size() != 2) continue;

            MapCell cell;
            cell.name = sub[0].trimmed();
            cell.level = sub[1].trimmed().toInt();
            row.append(cell);
        }
        mapCells.append(row);
    }
    file.close();

    updateBoardUI();
}

// --------------------- loadAgents ---------------------
void GameBoard::loadAgents(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Cannot open agent file:" << path;
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd()){
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList parts = line.split(':');
        if(parts.size() != 2) continue;

        QString cellName = parts[0].trimmed();
        QStringList valueParts = parts[1].split(',');
        if(valueParts.size() != 2) continue;

        char player = valueParts[0].trimmed()[0].toLatin1(); // A یا B
        QString action = valueParts[1].trimmed(); // Sniper, Scout, Sergeant, Mark, Control

        // پیدا کردن سلول با نام cellName
        for(auto &row : mapCells){
            for(auto &cell : row){
                if(cell.name == cellName){
                    if(action == "Mark") cell.setMarkedBy(player);
                    else if(action == "Control") cell.setControlledBy(player);
                    else { // Agent
                        cell.agentType = action;
                        cell.agentOwner = player;
                    }
                    break;
                }
            }
        }
    }

    file.close();
    updateBoardUI();
}

// --------------------- updateBoardUI ---------------------
void GameBoard::updateBoardUI()
{
    QList<QWidget*> members = boardWidget->findChildren<QWidget*>();
    for(QWidget* w : members) delete w;

    int rows = mapCells.size();
    if(rows == 0) return;
    int cols = mapCells[0].size();

    int boardWidth = cols * tileW + tileW/2;
    int boardHeight = rows * tileH;
    int startX = (1300 - boardWidth)/2;
    int startY = (700 - boardHeight)/2;

    for(int r=0; r<rows; ++r){
        for(int c=0; c<cols; ++c){
            MapCell &cell = mapCells[r][c];

            QWidget *cellWidget = new QWidget(boardWidget);
            int offset = (r % 2 == 1) ? tileW/2 : 0;
            cellWidget->setGeometry(startX + c*tileW + offset, startY + r*tileH, tileW, tileH);
            cellWidget->setStyleSheet("background-color: #ffffff; border:1px solid #555;");

            // کارت و سطح
            QLabel *imgLabel = new QLabel(cellWidget);
            imgLabel->setPixmap(QPixmap(getImageForLevel(cell.level))
                                    .scaled(tileW, tileH*0.75, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
            imgLabel->setGeometry(0,0,tileW, tileH*0.75);
            imgLabel->setAlignment(Qt::AlignCenter);

            // نام کارت
            QLabel *txtLabel = new QLabel(cell.name, cellWidget);
            txtLabel->setGeometry(0,tileH*0.75,tileW, tileH*0.25);
            txtLabel->setAlignment(Qt::AlignCenter);
            txtLabel->setStyleSheet("color:green; font-weight:bold; font-size:12px;");

            // overlay برای Agent و Mark/Control
            QLabel *overlay = new QLabel(cellWidget);
            overlay->setGeometry(0,0,tileW,tileH);
            overlay->setAlignment(Qt::AlignCenter);
            overlay->setStyleSheet("background: transparent;");

            // Agent
            if(cell.hasAgent()){
                QString agentImg;
                if(cell.agentType=="Scout") agentImg = (cell.agentOwner=='A') ? ":/agents/ScoutA.png" : ":/agents/ScoutB.png";
                else if(cell.agentType=="Sniper") agentImg = (cell.agentOwner=='A') ? ":/agents/SniperA.png" : ":/agents/SniperB.png";
                else if(cell.agentType=="Sergeant") agentImg = (cell.agentOwner=='A') ? ":/agents/SergeantA.png" : ":/agents/SergeantB.png";

                overlay->setPixmap(QPixmap(agentImg).scaled(tileW, tileH, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }

            // Mark
            if(cell.markedByA) overlay->setStyleSheet(overlay->styleSheet() + "background-color: rgba(0,0,255,80);"); // آبی
            if(cell.markedByB) overlay->setStyleSheet(overlay->styleSheet() + "background-color: rgba(255,0,0,80);"); // قرمز

            // Control
            if(cell.controlledByA) overlay->setStyleSheet(overlay->styleSheet() + "border:2px solid blue;");
            if(cell.controlledByB) overlay->setStyleSheet(overlay->styleSheet() + "border:2px solid red;");
        }
    }

    boardWidget->show();
}
