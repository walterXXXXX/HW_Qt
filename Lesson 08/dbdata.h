#ifndef DBDATA_H
#define DBDATA_H

#include <QDialog>

// данны БД по умолчанию
#define DB_HOST "981757-ca08998.tmweb.ru"
#define DB_dbNAME "netology_cpp"
#define DB_LOGIN "netology_usr_cpp"
#define DB_PASS "CppNeto3"
#define DB_PORT 5432


namespace Ui {
class DbData;
}

class DbData : public QDialog
{
    Q_OBJECT

public:
    explicit DbData(QWidget *parent = nullptr);
    ~DbData();


 signals:
    void sig_sendData(QVector<QString> dbData);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::DbData *ui;
    QVector<QString> data;

};

#endif // DBDATA_H
