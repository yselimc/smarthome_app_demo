#ifndef HOME_H
#define HOME_H

#include <optional>
#include <string>
#include <vector>
#include "Room.h"  // Room sınıfı tanımlanmış olmalı

class Home {
private:
    std::vector<Room> rooms;  // Room nesnelerinden oluşan bir vektör

public:
    Home();  // Varsayılan constructor

    void addRoom(const std::string& roomName);    // Yeni oda ekleme
    void removeRoom(const std::string& roomName); // Oda silme
    void editRoomName(const std::string& oldName, const std::string& newName); // Oda ismini düzenleme

    std::vector<Room>& getRooms();    // Odaları döndürme
};

#endif // HOME_H

