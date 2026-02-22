#include "Device.h"
#include <iostream>

// Default constructor
Device::Device() : name("Unnamed Device"), isOn(false), consumptionPerHour(0.0) {}

// Virtual destructor
Device::~Device() {}

// Setter for name
void Device::setName(const QString& newName) {
    name = newName;
}

// Getter for name
QString Device::getName() const {
    return name;
}

bool Device::getStatus() const {
    return isOn;
}

double Device::getConsumptionPerHour() const {
    return consumptionPerHour;
}

// Turn on the device
void Device::turnOn() {
    isOn = true;

}

// Turn off the device
void Device::turnOff() {
    isOn = false;

}
