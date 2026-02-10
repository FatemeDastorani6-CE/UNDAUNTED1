#include "gameboard.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPixmap>

GameBoard::GameBoard(QWidget *parent)
    : QDialog(parent)

{


this->showFullScreen();

    boardWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(boardWidget);
    boardWidget->setStyleSheet("background-color: #8FBC8F;");
}

GameBoard::~GameBoard()
{
}



void GameBoard::updateBoardView() {
    // اینجا کد رسم نقشه روی UI میره
    for(int r = 0; r < mapCells.size(); ++r) {
        for(int c = 0; c < mapCells[r].size(); ++c) {

        }
    }
}


QString GameBoard::getImageForLevel(int level){
    switch (level) {
    case 0: return ":/card/image0.JPG";
    case 1: return ":/card/image1.JPG";
    case 2: return ":/card/image2.JPG";
    default: return ":/card/image0.JPG";
    }
}

void GameBoard::loadMap(const QString &phase1Path, const QString &phase2Path)
{

    const int tileW = 60;
    const int tileH = 60;

    QFile file1(phase1Path);
    if(!file1.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Cannot open Phase1 file:" << phase1Path;
        return;
    }
    QTextStream in1(&file1);
    while(!in1.atEnd()){
        QString line = in1.readLine();
        // پردازش خانه‌ها، level و name
    }
    file1.close();

    // فایل phase2
    QFile file2(phase2Path);
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Cannot open Phase2 file:" << phase2Path;
        return;
    }
    QTextStream in2(&file2);
    while(!in2.atEnd()){
        QString line = in2.readLine();
        // پردازش Mark و Control و occupant
    }
    file2.close();

    QList<QWidget*> children = boardWidget->findChildren<QWidget*>();
    qDeleteAll(children);
    children.clear();

    int rows = mapCells.size();
    int cols = mapCells[0].size();

    int boardWidth = cols * tileW + tileW / 2;
    int boardHeight = rows * tileH;

    int startX = (1300 - boardWidth) / 2;
    int startY = (700 - boardHeight) / 2;


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
