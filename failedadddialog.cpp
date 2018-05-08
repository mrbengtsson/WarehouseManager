#include "failedadddialog.h"
#include "ui_failedadddialog.h"

FailedAddDialog::FailedAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FailedAddDialog)
{
    ui->setupUi(this);
    QApplication::beep();
}

FailedAddDialog::~FailedAddDialog()
{
    delete ui;
}

void FailedAddDialog::setDescription(QString message)
{
    ui->message->setText(message);
}

void FailedAddDialog::on_buttonBox_accepted()
{
    this->close();
}
