# CENG201 Smart Home Project

## Description
This project aims to develop a Smart Home Automation System that allows smart home devices 
(e.g. lights, thermostats, curtains) to be managed through a
central system. This system will allow users to remotely control their devices and access 
instant information about events taking place in their homes.

With modern and busy life, homeowners need to manage the devices in their homes from anywhere.
This system was developed for this need. Users will be able to turn their devices on and off, 
set timers, and instantly receive notifications from sensors such as security cameras via their
smartphone, tablet, or computer.

This report focuses on the analysis phase of the project and includes the system's requirements,
design models and preliminary examples of user interfaces. The sections in the report will discuss in detail 
what functions the system will provide, how it will interact with users, and how the general structure of the system is constructed.


## Features

- Being able to control the devices in the room

- Turn devices on and off.

- Monitor the status of devices in real-time.

- Ability to change settings such as brightness, color, temperature, speed.

- Control multiple rooms in a structured manner.

## Requirements
- Qt 5.15 or later
- C++11 or later

## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/yselimc/OOP_Group19
    ```
2. Open the project in Qt Creator.
3. Build and run the project.

## Usage
1. Launch the application.
2. If you do not have an account, create a new account and log in with your e-mail address and password if you have one.
3. Add a room.
4. Add devices to your room.
5. Control your devices from the interface.

## Project Structure

## Project Structure


smarthome_app_demo/
│
├── src/
│   ├── core/                       # Core system components
│   │   ├── acsystem.cpp
│   │   ├── acsystem.h
│   │   ├── curtains.cpp
│   │   ├── curtains.h
│   │   ├── device.cpp
│   │   ├── lights.cpp
│   │   ├── lights.h
│   │   ├── room.cpp
│   │   ├── room.h
│   │   ├── tv.cpp
│   │   ├── tv.h
│   │   ├── user.cpp
│   │   ├── user.h
│   │   ├── homemanagement.cpp
│   │   ├── homemanagement.h
│   │   ├── homemanagement.ui
│   │   ├── login.cpp
│   │   ├── login.h
│   │   ├── login.ui
│   │   ├── usermanagement.cpp
│   │   ├── usermanagement.h
│   │   ├── usermanagementsystem.cpp
│   │   ├── usermanagementsystem.h
│   │   └── usermanagementsystem.ui
│   │
│   ├── main.cpp
│   ├── CMakeLists.txt
│   ├── images.qrc
│   └── img.qrc
│
├── assets/
│   └── images/
│
├── build/
│
└── README.md

## Usage

1. Clone the repository.
2. Configure the build system using CMake.
3. Build and run the project using your preferred compiler.

## Dependencies

- C++17 or later
- CMake 3.10+
- Qt for UI components




