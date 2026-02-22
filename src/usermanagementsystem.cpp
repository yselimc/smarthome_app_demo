#include "UserManagementSystem.h"
#include "ui_UserManagementSystem.h"
#include <QMessageBox>

// Constructor
UserManagementSystem::UserManagementSystem(QWidget *parent)
    : QDialog(parent), ui(new Ui::UserManagementSystem)
{
    ui->setupUi(this);
}

// Destructor
UserManagementSystem::~UserManagementSystem() {
    delete ui;
}

// Kullanıcı ekleme
void UserManagementSystem::addUser(const User& user) {
    users.push_back(user);
    QMessageBox::information(this, "User Added",
                             QString("User %1 added successfully.")
                                 .arg(QString::fromStdString(user.getName())));
}

// Kullanıcı kaldırma
void UserManagementSystem::removeUser(const std::string& name) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getName() == name) {
            users.erase(it);
            QMessageBox::information(this, "User Removed",
                                     QString("User %1 removed successfully.")
                                         .arg(QString::fromStdString(name)));
            return;
        }
    }
    QMessageBox::warning(this, "User Not Found",
                         QString("User %1 not found.")
                             .arg(QString::fromStdString(name)));
}

// Kullanıcı bulma
User* UserManagementSystem::getUser(const std::string& name) {
    for (auto& user : users) {
        if (user.getName() == name) {
            return &user;
        }
    }
    QMessageBox::warning(this, "User Not Found",
                         QString("User %1 not found.")
                             .arg(QString::fromStdString(name)));
    return nullptr;
}

void UserManagementSystem::listUsers() const {
    QString userList = "Registered Users:\n";
    for (const auto& user : users) {
        userList += QString("Name: %1, Email: %2, Blood Type: %3, Phone: %4\n")
                        .arg(QString::fromStdString(user.getName()))
                        .arg(QString::fromStdString(user.getEmail()))
                        .arg(QString::fromStdString(user.getBloodType()))
                        .arg(QString::number(user.getPhoneNumber())); // Phone number int türünde
    }
    if (users.empty()) {
        userList = "No registered users.";
    }

    // QMessageBox için parent QWidget'i nullptr olarak ayarlayın
    QMessageBox messageBox;
    messageBox.setText(userList);
    messageBox.setWindowTitle("User List");
    messageBox.exec();
}


