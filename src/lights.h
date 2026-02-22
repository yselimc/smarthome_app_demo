#ifndef LIGHTS_H
#define LIGHTS_H

#include "Device.h"

class Lights : public Device {
public:
    static int lightCounter;
    Lights(double consumption, const QString& defaultColor = "White", int defaultBrightness = 50);

    void setColor(const QString& newColor);
    void setBrightness(int newBrightness);
    void setStatus(bool status);
    QString getColor() const;        // Getter for color
    int getBrightness() const;       // Getter for brightness
    bool isOn() const;               // Getter for isOn
    void showDetails() const;
    QString getLightInfo() const;    // New method to return formatted string with light details
    bool getStatus() const;

private:
    QString color;
    int brightness;
    bool status;  // Renamed member variable to avoid conflict
    double consumptionPerHour;
};

#endif // LIGHTS_H
