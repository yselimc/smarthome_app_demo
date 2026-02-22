#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "usermanagement.h"
#include "homemanagement.h"
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_backButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
