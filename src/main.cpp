#include <QApplication>
#include "usermanagement.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserManagement usermanagementsystem;
    usermanagementsystem.setModal(true);
    usermanagementsystem.exec();
    return a.exec();
}
