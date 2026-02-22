#include "homemanagement.h"
#include "ui_homemanagement.h"
#include <QMessageBox>
#include <QInputDialog>  // QInputDialog başlık dosyasını ekledik
#include "homemanagement.h"
#include "ui_homemanagement.h"
#include <QMessageBox>
#include <QInputDialog>  // QInputDialog başlık dosyasını ekledik

HomeManagement::HomeManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeManagement),
    currentUser(nullptr) // Başlangıçta currentUser null olabilir
{
    ui->setupUi(this);
    updateRoomList();  // Oda listesini güncelle

    // Connect roomListWidget's currentItemChanged signal to update SelectedListWidget and SelectedRoomTable
    connect(ui->roomListWidget, &QListWidget::currentItemChanged, [=](QListWidgetItem* current, QListWidgetItem* previous) {
        if (current) {
            std::string roomName = current->text().toStdString();
            auto& rooms = currentUser->getHome().getRooms();
            auto it = std::find_if(rooms.begin(), rooms.end(), [&roomName](const Room& room) {
                return room.getName() == roomName;
            });

            if (it != rooms.end()) {
                // Update the SelectedListWidget with devices of the selected room
                addDeviceToListWidget(ui->SelectedListWidget, *it);

                // Update the SelectedRoomTable (QLabel) with the selected room name in uppercase
                QString upperRoomName = QString::fromStdString(roomName).toUpper();
                ui->SelectedRoomTable->setText(upperRoomName);

                // Center align the text in SelectedRoomTable
                ui->SelectedRoomTable->setAlignment(Qt::AlignCenter);
            }
        }
    });

    // Existing connection for adding a device to the room
    connect(ui->addDeviceButton, &QPushButton::clicked, [=]() {
        QListWidgetItem* selectedRoomItem = ui->roomListWidget->currentItem();
        if (selectedRoomItem) {
            std::string roomName = selectedRoomItem->text().toStdString();
            auto& rooms = currentUser->getHome().getRooms();
            auto it = std::find_if(rooms.begin(), rooms.end(), [&roomName](const Room& room) {
                return room.getName() == roomName;
            });
            if (it != rooms.end()) {
                addDeviceToListWidget(ui->SelectedListWidget, *it);
            }
        }
    });

    // QLabel'ların stilini ayarlamak
    ui->label->setStyleSheet("border-image:none;color: white; font-weight: bold; font-size: 12pt;");
    ui->label_2->setStyleSheet("border-image:none;color: white; font-weight: bold; font-size: 12pt;");
    ui->label_3->setStyleSheet("border-image:none;color: white; font-weight: bold; font-size: 12pt;");
    ui->SelectedRoomTable->setStyleSheet("border-image:none;color: white; font-weight: bold; font-size: 12pt;");
    //ui->label_4->setText("Welcome " + QString::fromStdString(currentUser->getName()));
    ui->label_4->setStyleSheet("border-image:none;color: white; font-weight: bold; font-size: 14pt; text-transform: uppercase;");
    ui->label_4->setAlignment(Qt::AlignCenter);  // Metni ortalar

    // roomListWidget için stil ayarlarını yapıyoruz
    for (int i = 0; i < ui->roomListWidget->count(); ++i) {
        QListWidgetItem* item = ui->roomListWidget->item(i);
        item->setFont(QFont("Arial", 12, QFont::Bold));  // Fontu bold ve 12 yapıyoruz
        item->setForeground(QBrush(Qt::black));  // Rengi siyah yapıyoruz
    }

    // SelectedListWidget için stil ayarlarını yapıyoruz
    for (int i = 0; i < ui->SelectedListWidget->count(); ++i) {
        QListWidgetItem* item = ui->SelectedListWidget->item(i);
        item->setFont(QFont("Arial", 12, QFont::Bold));  // Fontu bold ve 12 yapıyoruz
        item->setForeground(QBrush(Qt::black));  // Rengi siyah yapıyoruz
    }

    // roomListWidget_2 için stil ayarlarını yapıyoruz
    for (int i = 0; i < ui->roomListWidget_2->count(); ++i) {
        QListWidgetItem* item = ui->roomListWidget_2->item(i);
        item->setFont(QFont("Arial", 12, QFont::Bold));  // Fontu bold ve 12 yapıyoruz
        item->setForeground(QBrush(Qt::black));  // Rengi siyah yapıyoruz
    }

}

void HomeManagement::addDeviceToListWidget(QListWidget* listWidget, const Room& room) {
    listWidget->clear(); // Clear the list before updating
    for (const auto& device : room.getDevices()) {
        if (device) {
            listWidget->addItem((device->getName()));
        }
    }
}

HomeManagement::~HomeManagement()
{
    delete ui;
}

void HomeManagement::updateRoomList() {
    ui->roomListWidget->clear();
    if (currentUser && isLoggedIn) {
        for (const auto& room : currentUser->getHome().getRooms()) {  // '->' kullanın
            ui->roomListWidget->addItem(QString::fromStdString(room.getName()));
        }
    }
}

void HomeManagement::on_addRoomButton_clicked()
{
    if (currentUser && isLoggedIn) {
        QString roomName = "Room" + QString::number(roomCounter);
        currentUser->getHome().addRoom(roomName.toStdString());  // '->' kullanın
        roomCounter++;
        updateRoomList();
    }
}

void HomeManagement::on_removeRoomButton_clicked()
{
    QListWidgetItem *selectedItem = ui->roomListWidget->currentItem();
    if (selectedItem) {
        currentUser->getHome().removeRoom(selectedItem->text().toStdString());  // Seçili odayı kullanıcıdan sil
        updateRoomList();  // Listeyi güncelle
    } else {
        QMessageBox::warning(this, "Warning", "Please select a room to delete.");
    }
}

void HomeManagement::on_editRoomButton_clicked()
{
    QListWidgetItem *selectedItem = ui->roomListWidget->currentItem();
    if (selectedItem) {
        bool ok;
        QString newRoomName = QInputDialog::getText(this, "Edit Room Name", "Enter new room name:", QLineEdit::Normal, selectedItem->text(), &ok);
        if (ok && !newRoomName.isEmpty()) {
            currentUser->getHome().editRoomName(selectedItem->text().toStdString(), newRoomName.toStdString());  // Oda ismini değiştir
            updateRoomList();  // Listeyi güncelle
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a room to edit.");
    }
}

void HomeManagement::loginUser(const std::string& email, const std::string& password) {
    UserManagement userManager;
    const auto& users = userManager.users;
    for (const auto& user : users) {
        if (user.getEmail() == email && user.getPassword() == password) {
            currentUser = const_cast<User*>(&user);  // const_cast kullanarak const'u kaldırın
            isLoggedIn = true;
            updateRoomList();
            ui->label_4->setText("Welcome " + QString::fromStdString(currentUser->getName()));
            ui->label_4->setAlignment(Qt::AlignCenter);  // Metni ortalar
            break;
        }
    }
}


void HomeManagement::on_pushButton_clicked()
{
    this->hide();
    UserManagement mng;
    mng.setModal(true);
    mng.exec();
}


void HomeManagement::on_addDeviceButton_clicked() {
    // Get the selected room from roomListWidget
    QListWidgetItem* selectedRoomItem = ui->roomListWidget->currentItem();
    if (!selectedRoomItem) {
        QMessageBox::warning(this, "Warning", "Please select a room.");
        return;
    }

    // Get the selected device from roomListWidget_2
    QListWidgetItem* selectedDeviceItem = ui->roomListWidget_2->currentItem();
    if (!selectedDeviceItem) {
        QMessageBox::warning(this, "Warning", "Please select a device.");
        return;
    }

    // Retrieve the room object using the room name
    std::string roomName = selectedRoomItem->text().toStdString();
    auto& rooms = currentUser->getHome().getRooms();
    auto it = std::find_if(rooms.begin(), rooms.end(), [&roomName](const Room& room) {
        return room.getName() == roomName;
    });

    if (it == rooms.end()) {
        QMessageBox::warning(this, "Error", "Room not found.");
        return;
    }

    Room& selectedRoom = *it;

    // Create a new device object
    std::string deviceName = selectedDeviceItem->text().toStdString();
    Device* newDevice;  // Replace with specific device type if needed

    if (deviceName == "Light") {
        newDevice = new Lights(0.0, "White",0); // Example parameters
        // Butona tıklanınca listeyi güncelle

    }else if (deviceName == "TV") {
        newDevice = new TV("TV", 0.0, 0,0); // Example parameters
    } else if (deviceName == "ACSystem") {
        newDevice = new ACSystem("ACSystem", 0.0, 0.0, 0); // Example parameters
    }  else if (deviceName == "Curtain") {
        newDevice = new Curtains("Curtain", 0.0, 0); // Example parameters
    } else {
        QMessageBox::warning(this, "Error", "Unknown device type.");
        return;
    }
    // Add the new device to the room's device vector
    selectedRoom.addDevice(newDevice);

    // Provide feedback to the user
    QMessageBox::information(this, "Success", QString("Device '%1' added to room '%2'.")
                                                  .arg(selectedDeviceItem->text(), selectedRoomItem->text()));
}


void HomeManagement::on_SelectedListWidget_clicked(const QModelIndex &index)
{
    // Tıklanan öğeyi almak için index'ten QListWidgetItem alın
    QListWidgetItem *item = ui->SelectedListWidget->itemFromIndex(index);

    if (item) {
        // Öğenin metnini alıyoruz (Burada cihaz veya oda adı)
        QString itemText = item->text();

        // Home içerisindeki odaları alıyoruz
        for (auto room : currentUser->home.getRooms()) {
            // Odanın adını QString'e dönüştürüp karşılaştıralım
            if (QString::fromStdString(room.getName()).compare(ui->SelectedRoomTable->text(), Qt::CaseInsensitive) == 0) {
                // Oda adı eşleştiyse, cihazlar üzerinde işlem yapalım
                for (auto device : room.getDevices()) {
                    if (device->getName().compare(itemText, Qt::CaseInsensitive) == 0) {
                        if (itemText.contains("light", Qt::CaseInsensitive)){
                            Lights* light = dynamic_cast<Lights*>(device);
                            // Eşleşen cihazın bilgilerini infoLabel'a aktaralım
                            ui->infoLabel->setText(light->getLightInfo());
                            return; // Eşleşen cihaz bulundu, döngüden çıkıyoruz
                        }
                        if (itemText.contains("TV", Qt::CaseInsensitive)){
                            TV* tv = dynamic_cast<TV*>(device);
                            // Eşleşen cihazın bilgilerini infoLabel'a aktaralım
                            ui->infoLabel->setText(tv->showDetails());
                            return; // Eşleşen cihaz bulundu, döngüden çıkıyoruz
                        }
                        if (itemText.contains("curtain", Qt::CaseInsensitive)) {
                            Curtains* curtain = dynamic_cast<Curtains*>(device);
                            if (curtain) {
                                // Perdenin detaylarını infoLabel'a aktar
                                ui->infoLabel->setText(curtain->showDetails());
                                return; // Eşleşen cihaz bulundu, döngüden çık
                            }
                        }

                        if (itemText.contains("AC", Qt::CaseInsensitive)) {
                            ACSystem* acSystem = dynamic_cast<ACSystem*>(device);
                            if (acSystem) {
                                // AC sisteminin detaylarını infoLabel'a aktar
                                ui->infoLabel->setText(acSystem->showDetails());
                                return; // Eşleşen cihaz bulundu, döngüden çık
                            }
                        }

                    }
                }
            }
        }

    }
}





void HomeManagement::on_SelectedListWidget_doubleClicked(const QModelIndex &index)
{
    // Tıklanan öğeyi almak için index'ten QListWidgetItem alın
    QListWidgetItem *item = ui->SelectedListWidget->itemFromIndex(index);

    if (item) {
        // Öğenin metnini alıyoruz (Burada cihaz veya oda adı)
        QString itemText = item->text();

        // Home içerisindeki odaları alıyoruz
        for (auto room : currentUser->home.getRooms()) {
            // Odanın adını QString'e dönüştürüp karşılaştıralım
            if (QString::fromStdString(room.getName()).compare(ui->SelectedRoomTable->text(), Qt::CaseInsensitive) == 0) {
                // Oda adı eşleştiyse, cihazlar üzerinde işlem yapalım
                for (auto device : room.getDevices()) {
                    if (device->getName().compare(itemText, Qt::CaseInsensitive) == 0) {
                        if (itemText.contains("light", Qt::CaseInsensitive)){
                            Lights* light = dynamic_cast<Lights*>(device);
                            // Eşleşen cihazın bilgilerini infoLabel'a aktaralım
                            // Eğer light objesi varsa, kullanıcıdan renk, parlaklık ve açık/kapalı durumu almak için QInputDialog kullanıyoruz
                            bool ok;

                            // QComboBox kullanarak renk seçimini sağlıyoruz
                            QStringList colors;
                            colors << "Blue" << "Yellow" << "Red";  // Seçenekler


                            QInputDialog colorDialog;
                            colorDialog.setStyleSheet("QDialog { border-image: none; color :white;}"); // Yazı rengini beyaz yapıyoruz
                            QString newColor = colorDialog.getItem(this, "Edit Light Color", "Select color:", colors, 0, false, &ok);
                            if (ok && !newColor.isEmpty()) {
                                // Kullanıcı geçerli bir renk seçtiyse
                                light->setColor(newColor);  // Seçilen rengi objeye ayarlıyoruz
                            }


                            // Parlaklık almak için QInputDialog kullanımı
                            int newBrightness = QInputDialog::getInt(this, "Edit Light Brightness", "Enter new brightness (0-100):", light->getBrightness(), 0, 100, 1, &ok);
                            if (ok) {
                                light->setBrightness(newBrightness);  // Parlaklık değerini güncelliyoruz
                            }

                            // Açık/Kapalı durumu almak için QInputDialog kullanımı
                            QStringList statusOptions = {"On", "Off"};
                            QString newStatus = QInputDialog::getItem(this, "Edit Light Status", "Choose the status:", statusOptions, 0, false, &ok);
                            if (ok && !newStatus.isEmpty()) {
                                bool control = newStatus == "On" ? true:false;
                                light->setStatus(control);  // Durumu güncelliyoruz
                            }
                            ui->infoLabel->setText(light->getLightInfo());
                            return; // Eşleşen cihaz bulundu, döngüden çıkıyoruz
                        }
                        if (itemText.contains("TV", Qt::CaseInsensitive)) {
                            TV* tv = dynamic_cast<TV*>(device);
                            if (tv) {
                                bool ok;

                                // Kullanıcıdan kanal bilgisi almak için QInputDialog kullanımı
                                int newChannel = QInputDialog::getInt(this, "Edit TV Channel", "Enter new channel:", tv->getChannel(), 0, 999, 1, &ok);
                                if (ok) {
                                    tv->setChannel(newChannel);  // Kanal değerini güncelliyoruz
                                }

                                // Kullanıcıdan ses seviyesi almak için QInputDialog kullanımı
                                int newVolume = QInputDialog::getInt(this, "Edit TV Volume", "Enter new volume (0-100):", tv->getVolume(), 0, 100, 1, &ok);
                                if (ok) {
                                    tv->setVolume(newVolume);  // Ses seviyesi değerini güncelliyoruz
                                }

                                // Açık/Kapalı durumu almak için QInputDialog kullanımı
                                QStringList statusOptions = {"On", "Off"};
                                QString newStatus = QInputDialog::getItem(this, "Edit TV Status", "Choose the status:", statusOptions, 0, false, &ok);
                                if (ok && !newStatus.isEmpty()) {
                                    bool control = newStatus == "On";
                                    tv->setStatus(control);  // Durumu güncelliyoruz
                                }

                                // Bilgileri infoLabel'a yazdırıyoruz
                                ui->infoLabel->setText(tv->showDetails());
                                return; // Eşleşen cihaz bulundu, döngüden çıkıyoruz
                            }
                        }

                        if (itemText.contains("curtain", Qt::CaseInsensitive)) {
                            Curtains* curtain = dynamic_cast<Curtains*>(device);
                            if (curtain) {
                                bool ok;

                                // Kullanıcıdan seviye bilgisi almak için QInputDialog kullanımı
                                int newLevel = QInputDialog::getInt(this, "Edit Curtain Level", "Enter new level (0-100):", curtain->getLevel(), 0, 100, 1, &ok);
                                if (ok) {
                                    curtain->setLevel(newLevel);  // Seviye değerini güncelliyoruz
                                }

                                // Bilgileri infoLabel'a yazdırıyoruz
                                ui->infoLabel->setText(curtain->showDetails());
                                return; // Eşleşen cihaz bulundu, döngüden çıkıyoruz
                            }
                        }
                        if (itemText.contains("ACSystem", Qt::CaseInsensitive)) {
                            ACSystem* acSystem = dynamic_cast<ACSystem*>(device);
                            if (acSystem) {
                                bool ok;

                                // Kullanıcıdan sıcaklık bilgisi almak için QInputDialog kullanımı
                                double newTemperature = QInputDialog::getDouble(this, "Edit AC Temperature", "Enter new temperature:", acSystem->getTemperature(), -50.0, 50.0, 1, &ok);
                                if (ok) {
                                    acSystem->setTemperature(newTemperature);  // Sıcaklık değerini güncelliyoruz
                                }

                                // Kullanıcıdan fan hızı almak için QInputDialog kullanımı
                                int newFanSpeed = QInputDialog::getInt(this, "Edit AC Fan Speed", "Enter new fan speed (1-5):", acSystem->getFanSpeed(), 1, 5, 1, &ok);
                                if (ok) {
                                    acSystem->setFanSpeed(newFanSpeed);  // Fan hızı değerini güncelliyoruz
                                }

                                // Açık/Kapalı durumu almak için QInputDialog kullanımı
                                QStringList statusOptions = {"On", "Off"};
                                QString newStatus = QInputDialog::getItem(this, "Edit AC Status", "Choose the status:", statusOptions, 0, false, &ok);
                                if (ok && !newStatus.isEmpty()) {
                                    bool control = newStatus == "On";
                                    acSystem->setStatus(control);  // Durumu güncelliyoruz
                                }

                                // Bilgileri infoLabel'a yazdırıyoruz
                                ui->infoLabel->setText(acSystem->showDetails());
                                return; // Eşleşen cihaz bulundu, döngüden çıkıyoruz
                            }
                        }

                    }
                }
            }
        }

    }
}





void HomeManagement::on_removeDeviceButton_clicked()
{
    // SelectedListWidget üzerinde seçili olan cihazı alıyoruz
    QListWidgetItem* selectedItem = ui->SelectedListWidget->currentItem();

    if (selectedItem) {
        QString selectedDeviceName = selectedItem->text();  // Seçilen cihazın ismini alıyoruz

        // Kullanıcının evindeki odalarda bulunan cihazları kontrol ediyoruz
        for (auto& room : currentUser->home.getRooms()) {
            // Odanın cihazlar vektöründe, cihaz ismi eşleşen cihazı arıyoruz
            QString selectedRoomName = ui->SelectedRoomTable->text(); // Oda ismi genellikle 0. sütundadır

            // QString'i std::string'e dönüştürüyoruz
            std::string roomName = selectedRoomName.toStdString();
            if(room.getName() == roomName){
                for (auto it = room.getDevices().begin(); it != room.getDevices().end(); ++it) {
                    if ((*it)->getName() == selectedDeviceName) {
                        // Cihaz bulundu, siliniyor
                        room.removeDevice(selectedDeviceName);  // Adını gönderiyoruz
                        break;  // Cihaz silindikten sonra döngüden çıkıyoruz
                    }
                }
            }

        }

        // Seçilen cihazı listeden de siliyoruz
        delete selectedItem;  // Listeden kaldırma
        ui->infoLabel->setText("");
    }
}
