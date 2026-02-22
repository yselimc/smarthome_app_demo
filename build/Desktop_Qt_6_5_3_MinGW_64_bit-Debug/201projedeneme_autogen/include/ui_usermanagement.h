/********************************************************************************
** Form generated from reading UI file 'usermanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENT_H
#define UI_USERMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserManagement
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *emailLineEdit;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *nameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *phoneNumberLineEdit;
    QPushButton *addUserButton;
    QComboBox *bloodTypeComboBox;
    QLabel *label_8;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UserManagement)
    {
        if (UserManagement->objectName().isEmpty())
            UserManagement->setObjectName("UserManagement");
        UserManagement->resize(1000, 700);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/images/enterr.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        UserManagement->setWindowIcon(icon);
        UserManagement->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/homebackplan.jpg)  0 0 0 0 stretch stretch;\n"
"background: rgba(0, 0, 0, 0.5);"));
        pushButton = new QPushButton(UserManagement);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1000, 700, 83, 29));
        label = new QLabel(UserManagement);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 381, 71));
        label->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border: 2px solid white;\n"
""));
        label->setScaledContents(false);
        emailLineEdit = new QLineEdit(UserManagement);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(180, 240, 231, 41));
        QFont font;
        font.setPointSize(12);
        emailLineEdit->setFont(font);
        emailLineEdit->setStyleSheet(QString::fromUtf8("border-image: none;"));
        label_5 = new QLabel(UserManagement);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 380, 131, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-image: none;\n"
""));
        label_2 = new QLabel(UserManagement);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 170, 131, 41));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border: 2px solid white;"));
        label_4 = new QLabel(UserManagement);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 310, 131, 41));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-image: none;"));
        nameLineEdit = new QLineEdit(UserManagement);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(180, 170, 231, 41));
        nameLineEdit->setFont(font);
        nameLineEdit->setStyleSheet(QString::fromUtf8("border-image: none;"));
        passwordLineEdit = new QLineEdit(UserManagement);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(180, 450, 231, 41));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border-image: none;"));
        label_6 = new QLabel(UserManagement);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 450, 131, 41));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-image: none;"));
        label_3 = new QLabel(UserManagement);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 240, 131, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-image: none;"));
        phoneNumberLineEdit = new QLineEdit(UserManagement);
        phoneNumberLineEdit->setObjectName("phoneNumberLineEdit");
        phoneNumberLineEdit->setGeometry(QRect(180, 380, 231, 41));
        phoneNumberLineEdit->setFont(font);
        phoneNumberLineEdit->setStyleSheet(QString::fromUtf8("border-image: none;"));
        addUserButton = new QPushButton(UserManagement);
        addUserButton->setObjectName("addUserButton");
        addUserButton->setGeometry(QRect(100, 500, 191, 71));
        addUserButton->setCursor(QCursor(Qt::PointingHandCursor));
        addUserButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/enter2.png)  0 0 0 0 stretch stretch;\n"
"border-radius: 33px;"));
        bloodTypeComboBox = new QComboBox(UserManagement);
        bloodTypeComboBox->setObjectName("bloodTypeComboBox");
        bloodTypeComboBox->setGeometry(QRect(180, 310, 231, 41));
        bloodTypeComboBox->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border: 2px solid white;"));
        label_8 = new QLabel(UserManagement);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 590, 211, 51));
        QFont font2;
        font2.setPointSize(9);
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border: 2px solid white;"));
        label_8->setScaledContents(false);
        pushButton_2 = new QPushButton(UserManagement);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 590, 161, 51));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/loginn.png);\n"
"border-radius: 20px;\n"
""));

        retranslateUi(UserManagement);

        QMetaObject::connectSlotsByName(UserManagement);
    } // setupUi

    void retranslateUi(QDialog *UserManagement)
    {
        UserManagement->setWindowTitle(QCoreApplication::translate("UserManagement", "SmartHouse", nullptr));
        pushButton->setText(QCoreApplication::translate("UserManagement", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("UserManagement", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ffffff;\">WELCOME </span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("UserManagement", "Phone Number", nullptr));
        label_2->setText(QCoreApplication::translate("UserManagement", "Name-Surname", nullptr));
        label_4->setText(QCoreApplication::translate("UserManagement", "Blood Type", nullptr));
        label_6->setText(QCoreApplication::translate("UserManagement", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("UserManagement", "Mail", nullptr));
        addUserButton->setText(QString());
        label_8->setText(QCoreApplication::translate("UserManagement", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#ffffff;\">Do you have an account?</span></p></body></html>", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserManagement: public Ui_UserManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENT_H
