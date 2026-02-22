/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label_6;
    QPushButton *nextButton;
    QPushButton *backButton;
    QLabel *label_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(961, 700);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/images/enterrr.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setWindowOpacity(1.000000000000000);
        Login->setStyleSheet(QString::fromUtf8("border-image:url(:/image/images/homebackplan.jpg)  0 0 0 0 stretch stretch;\n"
"background: rgba(0, 0, 0, 0.75);"));
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 160, 251, 261));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/avatar.jpg);\n"
"border: 20px solid white;\n"
"border-radius: 125px;"));
        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 450, 131, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-image: none;"));
        emailLineEdit = new QLineEdit(Login);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(170, 450, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        emailLineEdit->setFont(font1);
        emailLineEdit->setStyleSheet(QString::fromUtf8("border-image: none;"));
        passwordLineEdit = new QLineEdit(Login);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(170, 520, 231, 41));
        passwordLineEdit->setFont(font1);
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border-image: none;"));
        label_6 = new QLabel(Login);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 520, 131, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-image: none;"));
        nextButton = new QPushButton(Login);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(290, 600, 71, 71));
        nextButton->setCursor(QCursor(Qt::PointingHandCursor));
        nextButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/sagbuton.jpeg) 0 0 0 0 stretch stretch;\n"
"border-radius: 33px;"));
        backButton = new QPushButton(Login);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 600, 71, 71));
        backButton->setCursor(QCursor(Qt::PointingHandCursor));
        backButton->setStyleSheet(QString::fromUtf8("border-image:url(:/image/images/solbutonfinal.jpg) 0 0 0 0 stretch stretch;\n"
"border-radius: 33px;"));
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 381, 71));
        label_2->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border: 2px solid white;\n"
""));
        label_2->setScaledContents(false);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "SmartHouse", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("Login", "Mail", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "Password", nullptr));
        nextButton->setText(QString());
        backButton->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ffffff;\">WELCOME </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
