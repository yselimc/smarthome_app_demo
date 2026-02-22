#include "Curtains.h"
#include <iostream>

// Sayaç başlangıcı
int Curtains::curtainsCounter = 0;

// Constructor
Curtains::Curtains(const QString& name, double consumption, int level)
    : Device() { // Device varsayılan constructor'ı çağrılır
    ++curtainsCounter; // Sayaç bir artırılır
    this->name = name + QString::number(curtainsCounter); // İsme sayaç eklenir
    this->consumptionPerHour = consumption;
    this->level = level;
}

// Set Level
void Curtains::setLevel(int newLevel) {
    if (newLevel >= 0 && newLevel <= 100) {
        level = newLevel;
    }
}

// Get Level
int Curtains::getLevel() const {
    return level;
}

// Show Details
QString Curtains::showDetails() const {
    return QString("Curtains: %1\nLevel: %2%")
        .arg(name)
        .arg(level);
}
