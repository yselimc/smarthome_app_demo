#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H
#include "user.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "homemanagement.h"
#include <QRegularExpression>
#include "login.h"

namespace Ui {
class UserManagement;
}

class UserManagement : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();
    const std::vector<User>& getUsers() const; // Getter fonksiyonunu tanımlayın
static std::vector<User> users;

private slots:
    void on_addUserButton_clicked();

    void on_phoneNumberLineEdit_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::UserManagement *ui;


};

#endif // USERMANAGEMENT_H
