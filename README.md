# CENG201 Smart Home Project

## Description

A Qt/C++ desktop application for managing smart home devices through a central interface.
Users can register, log in, create rooms, and control Lights, a TV, Curtains, and an
AC system from a single GUI.

## Features

- User registration and login with email/password authentication
- Add, rename, and remove rooms
- Add and remove devices per room: Lights, TV, Curtains, ACSystem
- Control device-specific settings:
  - Lights: toggle on/off, set color and brightness (0–100)
  - TV: toggle on/off, set channel and volume (0–100)
  - Curtains: set open/close level (0–100)
  - ACSystem: set temperature and fan speed (1–5)
- Real-time status display for all devices

## Requirements

- CMake 3.5 or later
- C++17 or later
- Qt 5 or Qt 6 (Widgets module)

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yselimc/OOP_Group19
   cd OOP_Group19
   ```
2. **Qt Creator:** Open `src/CMakeLists.txt` directly in Qt Creator, then configure and build.
3. **Command line:**
   ```sh
   mkdir build && cd build
   cmake ../src
   cmake --build .
   ```
   The compiled executable is named `201projedeneme`.

## Usage

1. Launch the application (`201projedeneme`).
2. To create an account, fill in: name, email (must contain `@` and end in `.com`),
   phone number (exactly 10 digits), blood type (dropdown), and password (minimum 8 characters).
3. Log in with your email and password.
4. Add one or more rooms from the home management screen.
5. Select a room, then add devices (Lights, TV, Curtains, ACSystem).
6. Click a device to view and adjust its controls.

## Project Structure

```
smarthome_app_demo/
├── src/                          # All source files
│   ├── main.cpp
│   ├── CMakeLists.txt
│   ├── device.h / device.cpp
│   ├── lights.h / lights.cpp
│   ├── tv.h / tv.cpp
│   ├── curtains.h / curtains.cpp
│   ├── acsystem.h / acsystem.cpp
│   ├── room.h / room.cpp
│   ├── home.h / home.cpp
│   ├── user.h / user.cpp
│   ├── usermanagement.h / .cpp / .ui
│   ├── usermanagementsystem.h / .cpp / .ui
│   ├── homemanagement.h / .cpp / .ui
│   ├── login.h / login.cpp / login.ui
│   ├── images.qrc
│   └── img.qrc
├── images/                       # UI image assets
├── build/                        # CMake build output
├── html/                         # Doxygen HTML documentation
├── latex/                        # Doxygen LaTeX documentation
├── UML.jpg                       # UML class diagram
├── UML2.jpg                      # Additional UML diagram
└── README.md
```

## Contributing

Pull requests are welcome. Please open an issue first to discuss proposed changes.

## License

This project is for academic use (CENG201 course project).
