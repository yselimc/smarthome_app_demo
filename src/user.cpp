#include "User.h"
//constructor
User::User(const std::string& name, const std::string& email, const std::string& bloodType,
           const std::string& phoneNumber, const std::string& password)
    : name(name), email(email), bloodType(bloodType), phoneNumber(phoneNumber), password(password), home() {}

// Getter metodları
std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getBloodType() const {
    return bloodType;
}

std::string User::getPhoneNumber() const {
    return phoneNumber; // Telefon numarasını string döndürüyoruz
}
std::string User::getPassword() const {
    return password;
}

// Setter metodları
void User::setName(const std::string& newName) {
    name = newName;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void User::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber; // Telefon numarasını string olarak ayarlıyoruz
}


Home& User::getHome() {
    return home;
}
