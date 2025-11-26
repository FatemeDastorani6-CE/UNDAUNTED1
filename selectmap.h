#ifndef SELECTMAP_H
#define SELECTMAP_H

#include <QDialog>

#include <QMap>
#include <QRadioButton>
#include <QDialog>
#include <QString>



namespace Ui {
class SelectMap;
}

class SelectMap : public QDialog
{
    Q_OBJECT

public:
    explicit SelectMap(QWidget *parent = nullptr);
    ~SelectMap();

    QString selectedMapPath() const;





private slots:
    void on_okButton_clicked();

private:

    void mapSelectionChanged(const QString& path);

    Ui::SelectMap *ui;
    QString chosenMap;
};

#endif // SELECTMAP_H
