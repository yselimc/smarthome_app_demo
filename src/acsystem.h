#ifndef ACSYSTEM_H
#define ACSYSTEM_H

#include "Device.h"

class ACSystem : public Device {
private:
    double temperature;
    int fanSpeed; // 1-5 scale
    static int acCounter; // Sayaç ekledik

public:
    ACSystem(const QString& name = "ACSystem", double consumption = 0, double temperature = 0.0, int fanSpeed = 0);

    void setTemperature(double newTemperature);
    void setFanSpeed(int newSpeed);
    double getTemperature() const;  // Getter for temperature
    int getFanSpeed() const;       // Getter for fanSpeed
    void setStatus(bool status);   // Set status (turn AC on/off)
    bool getStatus() const;        // Get status (is AC on/off)
    QString showDetails() const;   // showDetails fonksiyonu QString döndürecek
};

#endif // ACSYSTEM_H
