#ifndef TV_H
#define TV_H

#include "Device.h"

class TV : public Device {
private:
    int channel;
    int volume; // 0-100
    bool status;
    static int tvCounter;
    double consumption; // TV'ye özel tüketim değeri

public:
    TV(const QString& name = "TV", double consumption = 0.0, int channel = 0, int volume = 0);

    void setChannel(int newChannel);
    int getChannel() const; // Yeni getter metodu
    void setVolume(int newVolume);
    int getVolume() const;  // Yeni getter metodu
    void setStatus(bool status);
    bool getStatus() const;
    QString showDetails() const;
};

#endif // TV_H
