#include "selectmap.h"
#include "ui_selectmap.h"
#include <QFile>
#include <QDebug>

SelectMap::SelectMap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectMap)
{
    ui->setupUi(this);

    // پیشفرض
    ui->radioButton1->setChecked(true);
    mapSelectionChanged(":/map/1.txt", ":/map2/agent1.txt");

    connect(ui->radioButton1, &QRadioButton::toggled, this,
            [this](bool c){ if(c) mapSelectionChanged(":/map/1.txt", ":/map2/agent1.txt"); });
    connect(ui->radioButton2, &QRadioButton::toggled, this,
            [this](bool c){ if(c) mapSelectionChanged(":/map/2.txt", ":/map2/agent2.txt"); });
    connect(ui->radioButton3, &QRadioButton::toggled, this,
            [this](bool c){ if(c) mapSelectionChanged(":/map/3.txt", ":/map2/agent3.txt.txt"); });
    connect(ui->radioButton4, &QRadioButton::toggled, this,
            [this](bool c){ if(c) mapSelectionChanged(":/map/4.txt", ":/map2/agent4.txt"); });
    connect(ui->radioButton5, &QRadioButton::toggled, this,
            [this](bool c){ if(c) mapSelectionChanged(":/map/5.txt", ":/map2/agent5.txt"); });
}

SelectMap::~SelectMap() { delete ui; }

void SelectMap::mapSelectionChanged(const QString &mapFile, const QString &pieceFile)
{
    QFile f(mapFile);
    if(!f.exists()){ ui->okButton->setEnabled(false); qDebug() << "Map not found"; return; }
    QFile pf(pieceFile);
    if(!pf.exists()){ ui->okButton->setEnabled(false); qDebug() << "Piece file not found"; return; }

    chosenMap = mapFile;
    chosenPiece = pieceFile;
    ui->okButton->setEnabled(true);
}

void SelectMap::on_okButton_clicked()
{
    accept();
}
