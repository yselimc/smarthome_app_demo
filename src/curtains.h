#ifndef CURTAINS_H
#define CURTAINS_H

#include "Device.h"

class Curtains : public Device {
private:
    int level; // 0-100 (0: closed, 100: fully open)
    static int curtainsCounter; // Perde sayacını takip eder

public:
    Curtains(const QString& name = "Curtains", double consumption = 0.0, int level = 0);

    void setLevel(int newLevel);
    int getLevel() const;
    QString showDetails() const;
};

#endif // CURTAINS_H
