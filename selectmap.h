#pragma once
#include <QDialog>

namespace Ui { class SelectMap; }

class SelectMap : public QDialog
{
    Q_OBJECT
public:
    explicit SelectMap(QWidget *parent = nullptr);
    ~SelectMap();

    QString selectedMap() const { return chosenMap; }
    QString selectedPiece() const { return chosenPiece; }

private slots:
    void on_okButton_clicked();

private:
    Ui::SelectMap *ui;
    QString chosenMap;
    QString chosenPiece;

    void mapSelectionChanged(const QString &mapFile, const QString &pieceFile);
};
