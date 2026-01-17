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
    SelectMap(QWidget *p = nullptr);
    ~SelectMap();

    QString selectedMapPath() const;

    QString selectedAgentPath() const { return chosenAgentFile; } //جدید





private slots:
    void on_okButton_clicked();
    void mapSelectionChanged(const QString &path);

private:
    Ui::SelectMap *ui;
    QString chosenMap;
    QString chosenAgentFile;   // اضافه شد
};

#endif
