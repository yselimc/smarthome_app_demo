#include "TV.h"
#include <iostream>

int TV::tvCounter = 0;

// Constructor
TV::TV(const QString& name, double consumption, int channel, int volume)
    : channel(channel), volume(volume), consumption(consumption) {
    ++tvCounter;
    setName(name + QString::number(tvCounter)); // TV adını sayaçla güncelle
}


// Set Channel
void TV::setChannel(int newChannel) {
    channel = newChannel;
}

// Set Volume
void TV::setVolume(int newVolume) {
    volume = newVolume;
}

// Show Details
QString TV::showDetails() const {
    return QString("TV: %1\nStatus: %2\nChannel: %3\nVolume: %4%")
        .arg(name)
        .arg(isOn ? "On" : "Off")
        .arg(channel)
        .arg(volume);
}

void TV::setStatus(bool status) {
    this->status = status;  // Durumu ayarlıyoruz
}
bool TV::getStatus() const {
    return this->status;  // Durum bilgisini döndürüyoruz
}
// Get Channel
int TV::getChannel() const {  // Getter metodu
    return channel;
}
// Get Volume
int TV::getVolume() const {  // Getter metodu
    return volume;
}
