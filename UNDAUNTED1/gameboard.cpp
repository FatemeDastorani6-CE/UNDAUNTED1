#include "gameboard.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPixmap>

GameBoard::GameBoard(QWidget *parent)
    : QDialog(parent)
{

    this->setFixedSize(900, 600);


    boardWidget = new QWidget(this);
    boardWidget->setGeometry(0,0,900,600);
    boardWidget->setStyleSheet("background-color: #9CAF88;");
}

GameBoard::~GameBoard()
{
}

QString GameBoard::getImageForLevel(int level){
    switch (level) {
    case 0: return ":/card/image0.JPG";
    case 1: return ":/card/image1.JPG";
    case 2: return ":/card/image2.JPG";
    default: return ":/card/image0.JPG";
    }
}

void GameBoard::loadMap(const QString &path)
{

    const int tileW = 60;
    const int tileH = 60;

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Cannot open the file" << path;
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


    QList<QWidget*> children = boardWidget->findChildren<QWidget*>();
    for(QWidget* w : children){
        delete w;
    }

    int rows = mapCells.size();
    int cols = mapCells[0].size();

    int boardWidth = cols * tileW + tileW / 2;
    int boardHeight = rows * tileH;

    int startX = (900 - boardWidth) / 2;
    int startY = (600 - boardHeight) / 2;


    for(int r = 0; r < mapCells.size(); ++r){
        for(int c = 0; c < mapCells[r].size(); ++c){
            QWidget *cellWidget = new QWidget(boardWidget);
            int offset = (r % 2 == 1) ? tileW / 2 : 0;

            cellWidget->setGeometry(
                startX + c * tileW + offset,
                startY + r * tileH,
                tileW,
                tileH
                );

            cellWidget->setStyleSheet("background-color: #ffffff; border:1px solid #555;");

            QLabel *imgLabel = new QLabel(cellWidget);
            imgLabel->setPixmap(QPixmap(getImageForLevel(mapCells[r][c].level))
                                    .scaled(tileW, tileH*0.75, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
            imgLabel->setGeometry(0,0,tileW, tileH*0.75);
            imgLabel->setAlignment(Qt::AlignCenter);

            QLabel *txtLabel = new QLabel(mapCells[r][c].name, cellWidget);
            txtLabel->setGeometry(0,tileH*0.75,tileW, tileH*0.25);
            txtLabel->setAlignment(Qt::AlignCenter);
            txtLabel->setStyleSheet("color:black; font-weight:bold; font-size:12px;");
        }
    }

    boardWidget->show();
}
