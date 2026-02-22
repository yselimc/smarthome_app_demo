/********************************************************************************
** Form generated from reading UI file 'homemanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEMANAGEMENT_H
#define UI_HOMEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HomeManagement
{
public:
    QPushButton *pushButton;
    QListWidget *roomListWidget;
    QLabel *label;
    QPushButton *addRoomButton;
    QPushButton *removeRoomButton;
    QPushButton *editRoomButton;
    QListWidget *roomListWidget_2;
    QLabel *label_2;
    QPushButton *addDeviceButton;
    QListWidget *SelectedListWidget;
    QPushButton *removeDeviceButton;
    QLabel *SelectedRoomTable;
    QLabel *infoLabel;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *HomeManagement)
    {
        if (HomeManagement->objectName().isEmpty())
            HomeManagement->setObjectName("HomeManagement");
        HomeManagement->resize(1000, 700);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/images/enterr.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HomeManagement->setWindowIcon(icon);
        HomeManagement->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/roomback3.jpeg)  0 0 0 0 stretch stretch;\n"
"background: rgba(0, 0, 0, 0.5);"));
        pushButton = new QPushButton(HomeManagement);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(450, 600, 91, 91));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/exitbutton.jpg)  0 0 0 0 stretch stretch;\n"
"border-radius: 45px;"));
        roomListWidget = new QListWidget(HomeManagement);
        roomListWidget->setObjectName("roomListWidget");
        roomListWidget->setGeometry(QRect(70, 130, 231, 191));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 127));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        roomListWidget->setPalette(palette);
        QFont font;
        font.setPointSize(13);
        roomListWidget->setFont(font);
        roomListWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/beyaz.jpg);"));
        roomListWidget->setFrameShape(QFrame::Shape::StyledPanel);
        label = new QLabel(HomeManagement);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 231, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/yaziback.jpg);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addRoomButton = new QPushButton(HomeManagement);
        addRoomButton->setObjectName("addRoomButton");
        addRoomButton->setGeometry(QRect(250, 330, 51, 51));
        addRoomButton->setFont(font1);
        addRoomButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addRoomButton->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-image: url(:/image/images/add.jpg);\n"
""));
        removeRoomButton = new QPushButton(HomeManagement);
        removeRoomButton->setObjectName("removeRoomButton");
        removeRoomButton->setGeometry(QRect(70, 330, 51, 51));
        removeRoomButton->setFont(font1);
        removeRoomButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        removeRoomButton->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-image: url(:/image/images/del.png);"));
        editRoomButton = new QPushButton(HomeManagement);
        editRoomButton->setObjectName("editRoomButton");
        editRoomButton->setGeometry(QRect(160, 330, 51, 51));
        editRoomButton->setFont(font1);
        editRoomButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        editRoomButton->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-image: url(:/image/images/edit1.png);"));
        roomListWidget_2 = new QListWidget(HomeManagement);
        QFont font2;
        font2.setBold(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(roomListWidget_2);
        __qlistwidgetitem->setFont(font2);
        new QListWidgetItem(roomListWidget_2);
        new QListWidgetItem(roomListWidget_2);
        new QListWidgetItem(roomListWidget_2);
        roomListWidget_2->setObjectName("roomListWidget_2");
        roomListWidget_2->setGeometry(QRect(70, 470, 231, 101));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush5(QColor(0, 0, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        roomListWidget_2->setPalette(palette1);
        roomListWidget_2->setFont(font);
        roomListWidget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/beyaz.jpg);"));
        label_2 = new QLabel(HomeManagement);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 430, 231, 41));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label_2->setFont(font3);
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/yaziback.jpg);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addDeviceButton = new QPushButton(HomeManagement);
        addDeviceButton->setObjectName("addDeviceButton");
        addDeviceButton->setGeometry(QRect(250, 580, 51, 51));
        addDeviceButton->setFont(font1);
        addDeviceButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addDeviceButton->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-image: url(:/image/images/add.jpg);"));
        SelectedListWidget = new QListWidget(HomeManagement);
        SelectedListWidget->setObjectName("SelectedListWidget");
        SelectedListWidget->setGeometry(QRect(660, 130, 231, 221));
        SelectedListWidget->setFont(font);
        SelectedListWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/beyaz.jpg);"));
        removeDeviceButton = new QPushButton(HomeManagement);
        removeDeviceButton->setObjectName("removeDeviceButton");
        removeDeviceButton->setGeometry(QRect(900, 320, 51, 51));
        removeDeviceButton->setFont(font1);
        removeDeviceButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        removeDeviceButton->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"border-image: url(:/image/images/del.png);"));
        SelectedRoomTable = new QLabel(HomeManagement);
        SelectedRoomTable->setObjectName("SelectedRoomTable");
        SelectedRoomTable->setGeometry(QRect(660, 90, 231, 41));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        SelectedRoomTable->setFont(font4);
        SelectedRoomTable->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        SelectedRoomTable->setStyleSheet(QString::fromUtf8("border-image:url(:/image/images/yaziback.jpg);"));
        SelectedRoomTable->setAlignment(Qt::AlignmentFlag::AlignCenter);
        infoLabel = new QLabel(HomeManagement);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setGeometry(QRect(660, 440, 231, 211));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        infoLabel->setFont(font5);
        infoLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        infoLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/backgroundgreyyy.jpg);"));
        infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(HomeManagement);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(660, 400, 231, 41));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        label_3->setFont(font6);
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/image/images/yaziback.jpg);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(HomeManagement);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 0, 381, 71));
        label_4->setStyleSheet(QString::fromUtf8("border-image: none;\n"
"border: 2px solid white;\n"
""));
        label_4->setScaledContents(false);

        retranslateUi(HomeManagement);

        QMetaObject::connectSlotsByName(HomeManagement);
    } // setupUi

    void retranslateUi(QDialog *HomeManagement)
    {
        HomeManagement->setWindowTitle(QCoreApplication::translate("HomeManagement", "SmartHouse", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("HomeManagement", "ROOMS", nullptr));
        addRoomButton->setText(QString());
        removeRoomButton->setText(QString());
        editRoomButton->setText(QString());

        const bool __sortingEnabled = roomListWidget_2->isSortingEnabled();
        roomListWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = roomListWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("HomeManagement", "Light", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = roomListWidget_2->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("HomeManagement", "TV", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = roomListWidget_2->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("HomeManagement", "ACSystem", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = roomListWidget_2->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("HomeManagement", "Curtain", nullptr));
        roomListWidget_2->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("HomeManagement", "DEVICES", nullptr));
        addDeviceButton->setText(QString());
        removeDeviceButton->setText(QString());
        SelectedRoomTable->setText(QString());
        infoLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("HomeManagement", "DEVICES INFO", nullptr));
        label_4->setText(QCoreApplication::translate("HomeManagement", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ffffff;\">WELCOME </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeManagement: public Ui_HomeManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEMANAGEMENT_H
