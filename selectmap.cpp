#include "selectmap.h"
#include "ui_selectmap.h"
#include <QDebug>


SelectMap::SelectMap(QWidget *p)
    : QDialog(p)
    , ui(new Ui::SelectMap)
{
    ui->setupUi(this);


    ui->radioButton1->setChecked(true);
    mapSelectionChanged(":/map/1.txt");


    connect(ui->radioButton1, &QRadioButton::toggled, this,
            [this](bool c){ if(c)  mapSelectionChanged(":/map/1.txt"); });
    connect(ui->radioButton2, &QRadioButton::toggled, this,
            [this](bool c){ if(c)  mapSelectionChanged(":/map/2.txt"); });
    connect(ui->radioButton3, &QRadioButton::toggled, this,
            [this](bool c){ if(c)  mapSelectionChanged(":/map/3.txt"); });
    connect(ui->radioButton4, &QRadioButton::toggled, this,
            [this](bool c){ if(c)  mapSelectionChanged(":/map/4.txt"); });
    connect(ui->radioButton5, &QRadioButton::toggled, this,
            [this](bool c){ if(c)  mapSelectionChanged(":/map/5.txt"); });

}



SelectMap::~SelectMap()
{
    delete ui;
}
QString SelectMap:: selectedMapPath() const {
    return chosenMap;
}

void SelectMap:: mapSelectionChanged(const QString& path){
    QFile file(path);
    if(!file.exists()){
        qDebug() << "Map file not found:" << path;
        ui->okButton->setEnabled(false);
        return;
    }
    chosenMap=path;


    if (path == ":/map/1.txt") chosenAgentFile = "::/map2/agent1.txt";
    else if (path == ":/map/2.txt") chosenAgentFile = ":/map2/agent2.txt";
    else if (path == ":/map/3.txt") chosenAgentFile = ":/map2/agent3.txt";
    else if (path == ":/map/4.txt") chosenAgentFile = ":/map2/agent4.txt";
    else if (path == ":/map/5.txt") chosenAgentFile = ":/map2/agent5.txt";


    ui->okButton-> setEnabled(true);
}


void SelectMap::on_okButton_clicked(){
    accept();
}






\
