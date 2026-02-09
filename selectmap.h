#ifndef SELECTMAP_H
#define SELECTMAP_H

#include <QMap>
#include <QRadioButton>
#include <QDialog>
#include <QString>
#include <QFile>



namespace Ui {
class SelectMap;
}

class SelectMap : public QDialog
{
    Q_OBJECT

public:
     SelectMap(QWidget *parent = nullptr);
    ~SelectMap();

    QString selectedMapPath() const;





private slots:
    void on_OK_clicked();
    void mapSelectionChanged(const QString &path);

private:

    Ui::SelectMap *ui;
    QString chosenMap;
};

#endif
