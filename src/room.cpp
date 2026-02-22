#include "Room.h"

// Constructor
Room::Room(const std::string& name) : name(name) {}

// Getter ve Setter metodları
std::string Room::getName() const {
    return name;
}

void Room::setName(const std::string& newName) {
    name = newName;
}

// Karşılaştırma operatörü
bool Room::operator==(const std::string& otherName) const {
    return name == otherName;  // Oda ismini karşılaştır
}

// Cihaz ekleme
void Room::addDevice(Device* device) {
    devices.push_back(device);  // Vektöre cihaz pointer'ı ekle
}
// Cihazı kaldırma
// Cihazı kaldırma
void Room::removeDevice(const QString& deviceName) {
    // devices vektöründe cihazları döngüyle gez
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getName() == deviceName) {  // Cihazın adı eşleşiyorsa
            delete *it;  // Cihazı sil
            devices.erase(it);  // Vektörden cihazı çıkar
            return;  // Silme işlemi tamamlandı, fonksiyonu sonlandır
        }
    }
}

// Cihaz listesini alma
const std::vector<Device*>& Room::getDevices() const {
    return devices;  // Cihaz listesini döndür
}
