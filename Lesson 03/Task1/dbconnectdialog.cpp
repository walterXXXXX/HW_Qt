#include "dbconnectdialog.h"
#include "ui_dbconnectdialog.h"

DBConnectDialog::DBConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBConnectDialog)
{
    ui->setupUi(this);
}

DBConnectDialog::~DBConnectDialog()
{
    delete ui;
}
