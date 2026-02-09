#include "gameboard.h"

GameBoard::GameBoard(Game *g, QWidget *parent)
    : QDialog(parent), game(g)
{
    setFixedSize(900, 600);

    handWidget = new QWidget(this);
    handWidget->setGeometry(0, 500, 900, 100);
    handWidget->setStyleSheet("background:#333;");

    handLayout = new QHBoxLayout(handWidget);
    handLayout->setAlignment(Qt::AlignCenter);

    updateHandUI();
}

GameBoard::~GameBoard() {}

void GameBoard::loadMap(const QString &path)
{
    Q_UNUSED(path);
}

void GameBoard::updateHandUI()
{
    QLayoutItem *item;
    while ((item = handLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    cardButtons.clear();

    const QVector<Card> &hand = game->getCurrentPlayer().getHand();

    for (int i = 0; i < hand.size(); i++) {
        QPushButton *btn = new QPushButton(this);
        btn->setFixedSize(120, 80);

        QString text;
        switch (hand[i].getType()) {
        case SCOUT: text = "Scout"; break;
        case SNIPER: text = "Sniper"; break;
        case SERGEANT: text = "Sergeant"; break;
        }

        btn->setText(text);

        connect(btn, &QPushButton::clicked, this, [=]() {
            game->playCard(i);
        });

        handLayout->addWidget(btn);
        cardButtons.push_back(btn);
    }
}

bool GameBoard::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj)
    Q_UNUSED(event)
    return false;
}
