#include "selectmap.h"
#include "ui_selectmap.h"
#include "gameboard.h"

SelectMap::SelectMap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectMap)
{
    ui->setupUi(this);
}

SelectMap::~SelectMap()
{
    delete ui;
}

void SelectMap::on_Map_6_clicked()
{
    Select_M = "map1" ;
    GameBoard *gb = new GameBoard (Select_M , nullptr );
    gb -> show();
    this -> close() ;
}


void SelectMap::on_Map_7_clicked()
{
    Select_M = "map2" ;
    GameBoard *gb = new GameBoard (Select_M , nullptr );
    gb -> show();
    this -> close() ;
}


void SelectMap::on_Map_8_clicked()
{
    GameBoard *gb = new GameBoard (Select_M , nullptr );
    gb -> show();
    this -> close() ;
}


void SelectMap::on_Map_9_clicked()
{
    GameBoard *gb = new GameBoard (Select_M , nullptr );
    gb -> show();
    this -> close() ;
}


void SelectMap::on_Map_10_clicked()
{
    Select_M = "map5" ;
    GameBoard *gb = new GameBoard (Select_M , nullptr );
    gb -> show();
    this -> close() ;
}

