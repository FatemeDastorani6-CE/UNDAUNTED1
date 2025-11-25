#ifndef SELECTMAP_H
#define SELECTMAP_H

#include <QDialog>

namespace Ui {
class SelectMap;
}

class SelectMap : public QDialog
{
    Q_OBJECT

public:
    explicit SelectMap(QWidget *parent = nullptr);
    ~SelectMap();

private slots:

    void on_Map_6_clicked();

    void on_Map_7_clicked();

    void on_Map_8_clicked();

    void on_Map_9_clicked();

    void on_Map_10_clicked();

private:
    Ui::SelectMap *ui;
    QString Select_M ;

};

#endif // SELECTMAP_H
