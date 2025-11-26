#include "gameboard.h"
#include "ui_gameboard.h"
#include "QDebug"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

GameBoard::GameBoard(const QString &MapName ,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameBoard)
{
    ui->setupUi(this);

    Select_M = MapName ;

    qDebug() << "selected map :" << Select_M ;
}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::on_pushButton_clicked()
{

}




void GameBoard::loadMap(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "خطا", "فایل نقشه باز نشد!");
        return;
    }

    QMap<QString, int> map;
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        line.replace("|", " ");

        QStringList parts = line.split(" ", Qt::SkipEmptyParts);
        for (int i = 0; i < parts.size(); i++) {
            QString p = parts[i];
            if (p.contains(":")) {
                QStringList x = p.split(":");
                if (x.size() == 2) {
                    QString coord = x[0].trimmed();   // A01
                    int value = x[1].toInt();         // 0,1,2
                    map[coord] = value;
                }
            }
        }
    }
    file.close();
    namayeshMap(map);
}

void GameBoard::namayeshMap(const QMap<QString, int>& map)
{
    int maxRow = 0, maxCol = 0;
    foreach (QString key, map.keys()) {
        int r = key[0].toLatin1() - 'A';
        int c = key.mid(1).toInt();
        if (r > maxRow) maxRow = r;
        if (c > maxCol) maxCol = c;
    }

    for (int r = 0; r <= maxRow; r++) {
        for (int c = 1; c <= maxCol; c++) {
            QString name = QString("%1%2").arg(QChar('A'+r)).arg(c, 2, 10, QChar('0'));
            int val = map.value(name, 0);

            QPushButton* btn = new QPushButton(name);
            btn->setFixedSize(70, 70);

            if (val == 1) btn->setStyleSheet("background: blue; color: white;");
            else if (val == 2) btn->setStyleSheet("background: red; color: white;");
            else btn->setStyleSheet("background: gray;");

            connect(btn, &QPushButton::clicked, [=]() {
                ui->label->setText("کلیک کردی روی: " + name);
            });

            ui->gridLayout->addWidget(btn, r, c-1);
        }
    }
}
