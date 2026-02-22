#ifndef USER_H
#define USER_H
#include <QDialog>
#include "User.h"
#include <vector>
#include <QString>
#include "home.h"

class User {
private:
    std::string name;
    std::string email;
    std::string bloodType;
    std::string phoneNumber;  // Telefon numarası int türünde
    std::string password;


public:
    // Constructor
    User(const std::string& name, const std::string& email, const std::string& bloodType,
         const std::string& phoneNumber, const std::string& password);
    // Setter metodları
    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
    void setPhoneNumber(const std::string& newPhoneNumber); // Telefon numarası string olarak ayarlanacak
    Home home;
    std::string getName() const;
    std::string getEmail() const;
    std::string getBloodType() const;
    std::string getPhoneNumber() const; // Telefon numarası string dönecek
    std::string getPassword() const;
    Home& getHome();
};

#endif // USER_H
