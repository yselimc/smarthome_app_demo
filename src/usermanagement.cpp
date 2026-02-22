#include "usermanagement.h"
#include "ui_usermanagement.h"
#include <QRegularExpression>

std::vector<User> UserManagement::users;

UserManagement::UserManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);
    ui->label_2->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");
    ui->label_3->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");
    ui->label_4->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");
    ui->label_5->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");
    ui->label_6->setStyleSheet("color: white; font: bold 9pt Segoe; border-image: none;border: 2px solid white;");

    ui->bloodTypeComboBox->addItem("A+");
    ui->bloodTypeComboBox->addItem("A-");
    ui->bloodTypeComboBox->addItem("B+");
    ui->bloodTypeComboBox->addItem("B-");
    ui->bloodTypeComboBox->addItem("AB+");
    ui->bloodTypeComboBox->addItem("AB-");
    ui->bloodTypeComboBox->addItem("0+");
    ui->bloodTypeComboBox->addItem("0-");

    // QComboBox için stil
    ui->bloodTypeComboBox->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");

    // QLineEdit'ler için stil
    ui->nameLineEdit->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");
    ui->emailLineEdit->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");
    ui->phoneNumberLineEdit->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");
    ui->passwordLineEdit->setStyleSheet("color: white; font: bold 9pt Segoe; border: 2px solid white; border-image: none;");

   // ui->phoneNumberLineEdit->setInputMask("0000000000");  // Bu mask, yalnızca 10 haneli sayıları kabul eder
    ui->phoneNumberLineEdit->setMaxLength(10);
}

UserManagement::~UserManagement()
{
    delete ui;
}
const std::vector<User>& UserManagement::getUsers() const {
    return users; // Private olan vektörü döndürüyoruz
}


void UserManagement::on_addUserButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString bloodType = ui->bloodTypeComboBox->currentText();
    QString phoneNumber = ui->phoneNumberLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Email regex
    QRegularExpression emailRegex("\\b\\S+@\\S+\\.com\\b");
    QRegularExpressionMatch emailMatch = emailRegex.match(email);

    // Gerekli alanların boş olup olmadığını kontrol et
    if (name.isEmpty() || email.isEmpty() || bloodType.isEmpty() ||
        phoneNumber.isEmpty() || password.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Missing Information");
        msgBox.setText("All fields must be filled out.");
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #e0e0e0; color: black; }"
            "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
            "QMessageBox QPushButton:hover { background-color: #45a049; }"
            );
        msgBox.exec();
        return;
    }

    // Geçersiz email kontrolü
    if (!emailMatch.hasMatch()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Invalid Email");
        msgBox.setText("Please enter a valid email address.");
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #e0e0e0; color: black; }"
            "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
            "QMessageBox QPushButton:hover { background-color: #45a049; }"
            );
        msgBox.exec();
        return;
    }

    // Şifre uzunluğu kontrolü
    if (password.length() < 8) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Weak Password");
        msgBox.setText("Password must be at least 8 characters long.");
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #e0e0e0; color: black; }"
            "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
            "QMessageBox QPushButton:hover { background-color: #45a049; }"
            );
        msgBox.exec();
        return;
    }

    // Telefon numarası kontrolü (10 haneli)
    if (phoneNumber.length() != 10) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Invalid Number");
        msgBox.setText("Phone number must be exactly 10 digits.");
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #e0e0e0; color: black; }"
            "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
            "QMessageBox QPushButton:hover { background-color: #45a049; }"
            );
        msgBox.exec();
        return;
    }

    // Kullanıcı var mı kontrolü
    bool userExists = false;
    for (const auto& user : users) {
        if (user.getEmail() == email.toStdString() ||
            user.getPhoneNumber() == phoneNumber.toStdString())
        {
            userExists = true;
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("User Exists");
            msgBox.setText("A user with the same information already exists. Please use different details.");
            msgBox.setStyleSheet(
                "QMessageBox { background-color: #e0e0e0; color: black; }"
                "QMessageBox QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 5px; }"
                "QMessageBox QPushButton:hover { background-color: #45a049; }"
                );
            msgBox.exec();
            break;  // Kullanıcı bulunduysa döngüyü sonlandır
        }
    }

    // Eğer kullanıcı yoksa, yeni bir kullanıcı ekle
    if (!userExists) {
        User newUser(name.toStdString(), email.toStdString(), bloodType.toStdString(), phoneNumber.toStdString(), password.toStdString());
        users.push_back(newUser);  // Kullanıcıyı ekle
        this->hide();
        HomeManagement home;
        home.loginUser(email.toStdString(), password.toStdString());
        home.setModal(true);
        home.exec();
    }

}


void UserManagement::on_phoneNumberLineEdit_textEdited(const QString &arg1)
{
    QString filteredText;
    for (const QChar& ch : arg1) {
        if (ch.isDigit()) {  // Yalnızca rakamları kabul et
            filteredText += ch;
        }
    }

    // Eğer girilen metnin uzunluğu 10'u geçerse, sadece ilk 10 karakteri al
    if (filteredText.length() > 10) {
        filteredText = filteredText.left(10);
    }

    // Güncellenen metni LineEdit'e ayarla
    ui->phoneNumberLineEdit->setText(filteredText);

    // İmleci metnin sonuna yerleştir
    ui->phoneNumberLineEdit->setCursorPosition(filteredText.length());
}



void UserManagement::on_pushButton_2_clicked()
{
    this->hide();
    Login login;
    login.setModal(true);
    login.exec();
}

