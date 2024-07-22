#ifndef DBCONNECTDIALOG_H
#define DBCONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class DBConnectDialog;
}

class DBConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DBConnectDialog(QWidget *parent = nullptr);
    ~DBConnectDialog();

private:
    Ui::DBConnectDialog *ui;
};

#endif // DBCONNECTDIALOG_H
