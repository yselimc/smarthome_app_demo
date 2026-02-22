#include "ACSystem.h"
#include <QString>
#include <iostream>

int ACSystem::acCounter = 0;  // Sayaç başlangıcı

// Constructor

ACSystem::ACSystem(const QString& name, double consumption, double temperature, int fanSpeed)
    : Device() {  // Device'ın varsayılan constructor'ı çağrıldı
    ++acCounter;  // Sayaç artırma
    setName(name + QString::number(acCounter));  // AC ismini sayaçla güncelle
    this->consumptionPerHour = consumption;  // consumptionPerHour'ı manuel olarak atıyoruz
    this->temperature = temperature;
    this->fanSpeed = fanSpeed;
}

// Set Temperature
void ACSystem::setTemperature(double newTemperature) {
    temperature = newTemperature;
}

// Set Fan Speed
void ACSystem::setFanSpeed(int newSpeed) {
    fanSpeed = newSpeed;
}

// Set Status
void ACSystem::setStatus(bool status) {
    if (status) {
        turnOn();  // AC'yi açıyoruz
    } else {
        turnOff(); // AC'yi kapatıyoruz
    }
}

// Get Status
bool ACSystem::getStatus() const {
    return isOn;  // AC'nin durumunu döndürüyoruz
}

// Show Details
QString ACSystem::showDetails() const {
    return QString("AC: %1\nStatus: %2\nTemperature: %3\nFan Speed: %4")
        .arg(name)
        .arg(isOn ? "On" : "Off")
        .arg(temperature)
        .arg(fanSpeed);
}

// Getter for Temperature
double ACSystem::getTemperature() const {
    return temperature;
}

// Getter for Fan Speed
int ACSystem::getFanSpeed() const {
    return fanSpeed;
}
