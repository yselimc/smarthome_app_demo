#include "Home.h"
#include <algorithm>  // std::find için gerekli

// Constructor
Home::Home() {}

// Yeni oda ekleme
void Home::addRoom(const std::string& roomName) {
    rooms.emplace_back(roomName);  // Room constructor'ını kullanarak ekleme
}

// Oda silme
void Home::removeRoom(const std::string& roomName) {
    auto it = std::find_if(rooms.begin(), rooms.end(),
                           [&roomName](const Room& room) {
                               return room.getName() == roomName;
                           });
    if (it != rooms.end()) {
        rooms.erase(it);  // Odayı vektörden sil
    }
}

// Oda ismini düzenleme
void Home::editRoomName(const std::string& oldName, const std::string& newName) {
    auto it = std::find_if(rooms.begin(), rooms.end(),
                           [&oldName](Room& room) {
                               return room.getName() == oldName;
                           });
    if (it != rooms.end()) {
        it->setName(newName);  // Odanın adını değiştir
    }
}

// Odaları döndürme
std::vector<Room>& Home::getRooms() {
    return rooms;
}

