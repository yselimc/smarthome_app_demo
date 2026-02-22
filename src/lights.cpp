#include "Lights.h"
#include <iostream>

int Lights::lightCounter = 0;

Lights::Lights(double consumption, const QString& defaultColor, int defaultBrightness)
    : Device(), color(defaultColor), brightness(defaultBrightness), status(false) {
    ++lightCounter;
    setName("Light" + QString::number(lightCounter));
    consumptionPerHour = consumption;
}

void Lights::setColor(const QString& newColor) {
    color = newColor;
}

QString Lights::getColor() const {
    return color;
}

void Lights::setBrightness(int newBrightness) {
    if (newBrightness >= 0 && newBrightness <= 100) {
        brightness = newBrightness;
    } else {
        std::cerr << "Brightness must be between 0 and 100.\n";
    }
}

int Lights::getBrightness() const {
    return brightness;
}

bool Lights::isOn() const {
    return status;  // Now returns the status of the light
}
void Lights::setStatus(bool status) {
    this->status = status;  // Durumu ayarlıyoruz
}
bool Lights::getStatus() const {
    return this->status;  // Durum bilgisini döndürüyoruz
}

void Lights::showDetails() const {
    std::cout << "Light: " << getName().toStdString() << ", Status: " << (isOn() ? "On" : "Off")
              << ", Color: " << color.toStdString() << ", Brightness: " << brightness << "%\n";
}

QString Lights::getLightInfo() const {
    return QString("Light: %1\n Brightness: %2\n Color: %3\n Status: %4")
        .arg(getName())
        .arg(brightness)
        .arg(color)
        .arg(isOn() ? "On" : "Off");
}
