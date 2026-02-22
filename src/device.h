#ifndef DEVICE_H
#define DEVICE_H

#include <QString> // Use QString for Qt compatibility

class Device {
public:
    // Default constructor
    Device();

    // Virtual destructor
    virtual ~Device();

    // Setter for name
    void setName(const QString& newName);

    // Getter for name
    QString getName() const;

    // Getter for device status
    bool getStatus() const;

    // Getter for consumption per hour
    double getConsumptionPerHour() const;

    // Turn on the device
    virtual void turnOn();

    // Turn off the device
    virtual void turnOff();

protected:
    QString name;                 // Device name
    bool isOn;                    // Device status (on/off)
    double consumptionPerHour;    // Power consumption per hour
};

#endif // DEVICE_H
