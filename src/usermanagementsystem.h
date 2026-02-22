#ifndef USERMANAGEMENTSYSTEM_H
#define USERMANAGEMENTSYSTEM_H

#include <QDialog>
#include "User.h"
#include <vector>
#include <string>

namespace Ui {
class UserManagementSystem;
}

class UserManagementSystem : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagementSystem(QWidget *parent = nullptr);
    ~UserManagementSystem();

    // Kullanıcı yönetimi metodları
    void addUser(const User& user);              // Kullanıcı ekleme
    void removeUser(const std::string& name);    // Kullanıcı kaldırma
    User* getUser(const std::string& name);      // Kullanıcı bulma
    void listUsers() const;                      // Kullanıcıları listeleme

private slots:
    void on_addUserButton_clicked();             // Kullanıcı ekleme butonu tıklandığında çağrılacak slot
    void on_removeUserButton_clicked();          // Kullanıcı silme butonu tıklandığında çağrılacak slot
    void on_listUsersButton_clicked();           // Kullanıcıları listeleme butonu tıklandığında çağrılacak slot

private:
    Ui::UserManagementSystem *ui;                // UI işaretçisi
    std::vector<User> users;                     // Kullanıcı listesini tutar
};

#endif // USERMANAGEMENTSYSTEM_H
