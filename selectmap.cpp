#include "selectmap.h"
#include "ui_selectmap.h"
#include <QDebug>


SelectMap::SelectMap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectMap)
{
    ui->setupUi(this);
    ui->okButton->setEnabled(false);

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
    }
    chosenMap=path;
    ui->okButton-> setEnabled(true);
}


void SelectMap::on_okButton_clicked(){
    accept();
}






