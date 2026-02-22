#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->label_3->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");
    ui->label_6->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");

    ui->emailLineEdit->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");
    ui->passwordLineEdit->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");

}

Login::~Login()
{
    delete ui;
}

void Login::on_backButton_clicked()
{
    this->hide();
    UserManagement management;
    management.setModal(true);
    management.exec();
}


void Login::on_nextButton_clicked()
{
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Missing Information");
        msgBox.setText("Both email and password must be filled out.");
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #e0e0e0; color: black; }"
            "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
            "QMessageBox QPushButton:hover { background-color: #45a049; }"
            );
        msgBox.exec();
    }
    else{
        UserManagement userManager;
        const auto& users = userManager.getUsers();
        bool userFound = false;
        for (const auto& user : users) {
            if (user.getEmail() == email.toStdString() &&
                user.getPassword() == password.toStdString()) {
                userFound = true;
                this->hide();
                HomeManagement home;
                home.loginUser(email.toStdString(), password.toStdString());
                home.setModal(true);
                home.exec();
                break;
            }
        }


        if (!userFound){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Login Failed");
            msgBox.setText("Incorrect email or password. Please try again.");
            msgBox.setStyleSheet(
                "QMessageBox { background-color: #e0e0e0; color: black; }"
                "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
                "QMessageBox QPushButton:hover { background-color: #45a049; }"
                );
            msgBox.exec();

        }
    }
}
