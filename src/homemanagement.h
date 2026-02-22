#ifndef HOMEMANAGEMENT_H
#define HOMEMANAGEMENT_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include "user.h"
#include "usermanagement.h"
#include "device.h"
#include "lights.h"
#include <QVBoxLayout>   // For QVBoxLayout
#include <QComboBox>     // For QComboBox
#include <QSlider>       // For QSlider
#include <QCheckBox>     // For QCheckBox
#include <QPushButton>   // For QPushButton
#include <QLabel>        // For QLabel
#include "tv.h"
#include "curtains.h"
#include "acsystem.h"

namespace Ui {
class HomeManagement;
}

class HomeManagement : public QDialog
{
    Q_OBJECT

public:
    explicit HomeManagement(QWidget *parent = nullptr);
    ~HomeManagement();
    void updateRoomList();
   // void setUser(User* user);
   // void setUser(User* user);
void loginUser(const std::string& email, const std::string& password);
    void addDeviceToListWidget(QListWidget* listWidget, const Room& room);


private slots:
    void on_addRoomButton_clicked();
    void on_removeRoomButton_clicked();
    void on_editRoomButton_clicked();

    void on_pushButton_clicked();

    void on_addDeviceButton_clicked();

    void on_SelectedListWidget_clicked(const QModelIndex &index);

    void on_SelectedListWidget_doubleClicked(const QModelIndex &index);

    void on_removeDeviceButton_clicked();

private:
    Ui::HomeManagement *ui;
    int roomCounter = 1; // Oda isimlerini takip etmek için sayaç
    User* currentUser;
bool isLoggedIn = false;
};

#endif // HOMEMANAGEMENT_H

