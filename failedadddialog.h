#ifndef FAILEDADDDIALOG_H
#define FAILEDADDDIALOG_H

#include <QDialog>

namespace Ui {
class FailedAddDialog;
}

class FailedAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FailedAddDialog(QWidget *parent = 0);
    ~FailedAddDialog();

    void setDescription(QString message);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::FailedAddDialog *ui;
};

#endif // FAILEDADDDIALOG_H
