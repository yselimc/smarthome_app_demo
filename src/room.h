#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Device.h"  // Device sınıfını dahil ettik

class Room {
private:
    std::string name;  // Oda ismi
    std::vector<Device*> devices;  // Device pointer'larını tutan vektör

public:
    // Constructor
    explicit Room(const std::string& name);

    // Getter ve Setter metodları
    std::string getName() const;              // Oda adını almak için
    void setName(const std::string& newName); // Oda adını değiştirmek için

    // Karşılaştırma operatörü
    bool operator==(const std::string& otherName) const;

    // Cihaz ekleme ve cihaz listesini alma
    void addDevice(Device* device);
    void removeDevice(const QString& deviceName);
    const std::vector<Device*>& getDevices() const;
};

#endif // ROOM_H
