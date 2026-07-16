# STM32-BASED-AUTOMATIC-DOOR-CONTROLLER-
An STM32F103C8T6-based automatic door controller using PIR and IR sensors, SG90 servo motor, and OLED display for intelligent, hands-free access automation.
# 🚪 STM32-Based Automatic Door Controller

<p align="center">

![Platform](https://img.shields.io/badge/Platform-STM32F103C8T6-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge)
![IDE](https://img.shields.io/badge/IDE-Arduino_IDE-00979D?style=for-the-badge)
![Board](https://img.shields.io/badge/Board-STM32_Blue_Pill-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)

</p>

---

# 📖 Project Overview

The **STM32-Based Automatic Door Controller** is a smart embedded systems project developed using the **STM32F103C8T6 (Blue Pill)** microcontroller. The system automatically opens and closes a door by detecting people entering and exiting through a combination of **PIR Motion Sensor**, **IR Sensor**, **SG90 Servo Motor**, and a **128×64 OLED Display**.

This project demonstrates how multiple sensors and actuators can work together to create an intelligent automation system. It continuously monitors the surrounding environment, processes sensor inputs in real time, controls the servo motor to operate the door, and displays system status on the OLED screen. The project serves as an excellent example of embedded system design, sensor interfacing, real-time control, and automation using STM32.

Designed primarily for engineering students, hobbyists, and beginners, this repository contains complete documentation, hardware connection details, software requirements, source code, and implementation steps required to recreate the project successfully.

---

# 📑 Table of Contents

- 📖 Project Overview
- 🎯 Project Objectives
- ✨ Features
- 🛠 Technologies Used
- 📚 Skills Demonstrated
- 📦 Hardware Components
- 🏠 Real-Life Component Representation
- 💻 Software Requirements
- 📖 Required Libraries
- 📂 Repository Structure
- 🔌 Hardware Connections
- 🏗 Hardware Assembly Guide
- 🚀 Uploading the Program
- ⚙ Working Principle
- 🔄 System Workflow
- 🧪 Testing Procedure
- ⚠ Troubleshooting
- 🌍 Applications
- ✅ Advantages
- ⚠ Limitations
- 🔮 Future Scope
- 🤝 Contributing
- 📜 License

---

# 🎯 Project Objectives

The primary objectives of this project are:

- Design an automatic door control system using the STM32F103C8T6 microcontroller.
- Detect people approaching the entrance using a PIR motion sensor.
- Detect people leaving the area using an IR sensor.
- Automatically control the door through a servo motor.
- Display system status and user messages on a 128×64 OLED display.
- Demonstrate sensor interfacing and actuator control using embedded programming.
- Develop a reliable, modular, and beginner-friendly automation project.

---

# ✨ Features

- 🚪 Automatic door opening and closing.
- 👤 PIR-based entry detection.
- 🚶 IR-based exit detection.
- ⚙ Smooth servo motor operation.
- 📺 OLED display for system status and welcome messages.
- ⏱ Automatic door closing after a preset delay.
- 🔄 Continuous real-time monitoring of sensors.
- 💻 Compatible with Arduino IDE using the STM32 Arduino Core.
- 📚 Clean and modular source code for easy understanding.
- 🎓 Ideal for embedded systems learning and academic projects.

---

# 🛠 Technologies Used

| Category | Technology |
|-----------|------------|
| Microcontroller | STM32F103C8T6 (Blue Pill) |
| Programming Language | C++ |
| Development Environment | Arduino IDE |
| Communication Protocol | I²C |
| Display Module | SSD1306 OLED (128×64) |
| Motion Detection | PIR Motion Sensor |
| Exit Detection | IR Sensor |
| Actuator | SG90 Servo Motor |

---

# 📚 Skills Demonstrated

This project demonstrates practical experience in:

- Embedded Systems Programming
- STM32 Development
- Sensor Interfacing
- Servo Motor Control
- OLED Display Programming
- I²C Communication
- Real-Time Embedded Applications
- Digital Input Processing
- Hardware Integration
- Automation System Design
- System Debugging
- Embedded Project Documentation

---

# 📦 Hardware Components

| Component | Quantity | Purpose |
|-----------|:--------:|---------|
| STM32F103C8T6 (Blue Pill) | 1 | Main Controller |
| PIR Motion Sensor | 1 | Detects a person approaching the door |
| IR Sensor Module | 1 | Detects a person leaving the door |
| SG90 Servo Motor | 1 | Opens and closes the door |
| SSD1306 OLED Display | 1 | Displays system messages |
| Breadboard | 1 | Circuit Assembly |
| Jumper Wires | As Required | Electrical Connections |
| USB Cable | 1 | Programming and Power Supply |

---

# 🏠 Real-Life Component Representation

| Component | Represents in a Real System |
|-----------|-----------------------------|
| STM32 Blue Pill | Central Door Controller |
| PIR Motion Sensor | Entry Detection Sensor |
| IR Sensor | Exit Detection Sensor |
| SG90 Servo Motor | Automatic Door Mechanism |
| OLED Display | Information Display Panel |
| USB Power | Building Power Supply |

---

# 💻 Software Requirements

Install the following software before building the project:

- Arduino IDE (Latest Version)
- STM32 Arduino Core
- USB-to-Serial Driver (if required)
- STM32 Board Package
- Serial Monitor (9600 Baud Rate)

---

# 📖 Required Libraries

Install the following libraries before compiling the program:

```cpp
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
```

These libraries are used for:

- Servo motor control
- I²C communication
- OLED graphics rendering
- SSD1306 OLED display support
# 🔌 Hardware Connections

Connect all components exactly as described below to ensure proper operation of the automatic door controller.

| STM32 Blue Pill Pin | Connected Component | Description |
|---------------------|---------------------|-------------|
| 5V | PIR Motion Sensor (VCC) | Power Supply |
| GND | PIR Motion Sensor (GND) | Common Ground |
| PA0 | PIR Motion Sensor (OUT) | Motion Detection Input |
| 5V | IR Sensor (VCC) | Power Supply |
| GND | IR Sensor (GND) | Common Ground |
| PA1 | IR Sensor (OUT) | Exit Detection Input |
| 5V | SG90 Servo (VCC) | Servo Power |
| GND | SG90 Servo (GND) | Servo Ground |
| PA8 | SG90 Servo (Signal) | Servo Control Signal |
| 3.3V | OLED Display (VCC) | OLED Power |
| GND | OLED Display (GND) | Common Ground |
| PB7 | OLED SDA | I²C Data Line |
| PB6 | OLED SCL | I²C Clock Line |

> **Note:** Ensure that all components share a common ground (GND). Incorrect power or signal connections may prevent the system from functioning correctly.

---

# 🏗 Hardware Assembly Guide

Follow these steps to assemble the hardware correctly.

### Step 1: Prepare the Development Board

- Place the STM32F103C8T6 (Blue Pill) on a breadboard.
- Ensure both rows of header pins are properly seated.
- Keep sufficient space around the board for wiring the remaining components.

---

### Step 2: Connect the Power Rails

- Connect the **5V** supply to the positive rail of the breadboard.
- Connect **GND** to the negative rail.
- If using the OLED module with **3.3V**, connect it to the STM32's **3.3V** output.
- Verify that every module shares the same ground connection.

---

### Step 3: Connect the PIR Motion Sensor

The PIR sensor detects a person approaching the entrance.

Connections:

- VCC → 5V
- GND → GND
- OUT → PA0

After powering the circuit, allow the PIR sensor a few seconds to stabilize before testing.

---

### Step 4: Connect the IR Sensor

The IR sensor detects a person leaving the controlled area.

Connections:

- VCC → 5V
- GND → GND
- OUT → PA1

Adjust the sensitivity of the IR sensor if required to achieve reliable detection.

---

### Step 5: Connect the Servo Motor

The SG90 servo motor performs the door opening and closing action.

Connections:

- Signal → PA8
- VCC → 5V
- GND → GND

Ensure the servo arm is mounted correctly before powering the system.

---

### Step 6: Connect the OLED Display

The OLED display provides system status messages and user feedback.

Connections:

- VCC → 3.3V
- GND → GND
- SDA → PB7
- SCL → PB6

The display communicates with the STM32 using the I²C protocol.

---

# 🚀 Uploading the Program

## Step 1

Install the latest version of **Arduino IDE**.

---

## Step 2

Install the **STM32 Arduino Core** using the Board Manager.

---

## Step 3

Select the correct board:

```
STM32F103C8T6 (Blue Pill)
```

---

## Step 4

Select the appropriate upload method according to your hardware setup.

---

## Step 5

Open the project source code contained in this repository.

---

## Step 6

Verify that all required libraries are installed successfully.

---

## Step 7

Compile the project.

Resolve any missing library or board package errors before proceeding.

---

## Step 8

Upload the program to the STM32 development board.

---

## Step 9

Once uploading is complete, reset the board if required.

The automatic door controller is now ready for operation.

---

# ⚙ Working Principle

The STM32 continuously monitors both the PIR motion sensor and the IR sensor.

When the PIR sensor detects an approaching person, the controller interprets this as an entry request. The servo motor rotates to open the door, while the OLED display presents an appropriate welcome message. After a predefined delay, the servo returns to its original position, closing the door automatically.

Similarly, when the IR sensor detects a person leaving the monitored area, the controller opens the door to allow exit and then closes it after the configured delay.

Throughout operation, the OLED display provides real-time visual feedback, indicating the current state of the system. This combination of sensors, display, and servo motor creates a simple yet effective automatic access control system.

---

# 🔄 System Workflow

The controller performs the following sequence continuously:

1. Initialize all peripherals.
2. Initialize the OLED display.
3. Configure the PIR and IR sensors.
4. Move the servo to the default closed position.
5. Continuously monitor the PIR sensor.
6. Open the door when motion is detected.
7. Display the corresponding status message.
8. Wait for the configured delay.
9. Close the door automatically.
10. Monitor the IR sensor for exit detection.
11. Repeat the entire process continuously.

This workflow allows the system to respond to both entry and exit events while maintaining smooth and reliable door operation.

# 🧪 Testing Procedure

After uploading the program successfully, verify each hardware module individually to ensure the entire system operates as expected.

---

## Initial Power-On Test

1. Power the STM32 Blue Pill board.
2. Wait for the OLED display to initialize.
3. Verify that the servo motor moves to its default (closed) position.
4. Ensure no error messages are displayed.

---

## PIR Motion Sensor Test

1. Stand in front of the PIR sensor.
2. Wait for the sensor to detect movement.
3. Observe the following actions:
   - The servo motor rotates to open the door.
   - The OLED displays the welcome message.
   - After the programmed delay, the servo returns to its initial position.

---

## IR Sensor Test

1. Pass your hand or an object in front of the IR sensor.
2. Verify that:
   - The controller detects the exit event.
   - The servo opens the door.
   - The OLED updates its status.
   - The door closes automatically after the programmed delay.

---

## Servo Motor Test

Confirm that the servo:

- Opens smoothly.
- Stops at the correct angle.
- Returns completely to the closed position.
- Does not vibrate continuously while idle.

---

## OLED Display Test

Verify that the OLED display:

- Powers on correctly.
- Displays the startup message.
- Updates the system status correctly.
- Remains stable without flickering.

---

## Continuous Operation Test

Allow the controller to run continuously for several minutes.

Verify that:

- Multiple entry detections work correctly.
- Multiple exit detections work correctly.
- The servo responds consistently.
- The OLED updates without interruption.
- No unexpected resets occur.

---

# ⚠ Troubleshooting

If the project does not operate as expected, review the following checks before modifying the program.

| Problem | Possible Cause | Recommended Solution |
|---------|----------------|----------------------|
| Servo motor does not rotate | Incorrect signal connection or insufficient power | Verify the servo signal pin, power supply, and ground connection |
| PIR sensor does not detect movement | Sensor not stabilized or incorrect wiring | Wait for sensor initialization and verify wiring |
| IR sensor does not respond | Incorrect alignment or sensitivity | Adjust the sensor position and sensitivity |
| OLED display remains blank | Incorrect I²C wiring or missing library | Verify SDA/SCL connections and installed libraries |
| Program fails to upload | Incorrect board configuration | Verify the selected STM32 board and upload method |
| Servo behaves unexpectedly | Loose wiring or unstable supply voltage | Check all electrical connections and ensure a stable power source |

---

# 🌍 Applications

The STM32-Based Automatic Door Controller can be adapted for numerous automation and access-control applications.

- Smart Home Entrance Systems
- Office Door Automation
- Shopping Mall Entrance Doors
- Hospital Automatic Doors
- Hotel Reception Areas
- Educational Demonstrations
- Embedded Systems Laboratories
- Engineering Mini Projects
- Industrial Automation Training
- IoT Prototype Development

---

# ✅ Advantages

- Low-cost implementation.
- Simple hardware architecture.
- Modular and easy-to-understand software.
- Reliable automatic door operation.
- Beginner-friendly implementation.
- Low power consumption.
- Expandable hardware design.
- Easy maintenance and troubleshooting.
- Suitable for academic demonstrations.
- Excellent project for learning STM32 programming.

---

# ⚠ Limitations

Although the project performs reliably, a few practical limitations should be considered.

- Designed as a prototype rather than a commercial product.
- Detection range depends on sensor placement.
- Environmental conditions may affect sensor accuracy.
- Does not include obstacle detection during door movement.
- No authentication or access control mechanism.
- No wireless monitoring or remote control functionality.

---

# 🔮 Future Scope

The project can be extended with several advanced features to create a more intelligent automation system.

- RFID-Based Access Control
- Fingerprint Authentication
- Face Recognition
- Wi-Fi Monitoring
- Bluetooth Mobile Application
- IoT Integration
- Voice Assistant Support
- Automatic Visitor Counter
- Cloud-Based Monitoring
- Mobile Notifications
- Camera-Based Security
- Emergency Fire Alarm Integration
- Smart Lock Integration
- Battery Backup System
- Energy Monitoring

---

# 🤝 Contributing

Contributions are welcome and greatly appreciated. Whether you would like to improve the documentation, optimize the software, enhance hardware compatibility, or add new features, your support helps make this project better for everyone.

Please read the **CONTRIBUTING.md** file before submitting issues or pull requests.

---

# 📜 License

This project is licensed under the **MIT License**.

You are free to use, modify, distribute, and build upon this project while retaining the original license and copyright notice.

For complete details, refer to the **LICENSE** file included in this repository.

---

# 👨‍💻 Author

**ShivsFoundry**

Embedded Systems • STM32 • Arduino • IoT • Robotics • Electronics

Passionate about designing practical embedded systems and developing beginner-friendly open-source projects that make learning electronics and microcontroller programming more accessible.

---

# ⭐ Support

If you found this project useful or learned something from it, consider supporting the project by giving it a **⭐ Star** on GitHub.

Your support motivates the development of more high-quality open-source embedded systems projects and helps others discover this repository.

---

## 📬 Feedback

Suggestions, feature requests, and constructive feedback are always welcome.

If you discover a bug or have an idea for improvement, feel free to open an Issue or submit a Pull Request. Every contribution, no matter how small, is appreciated.

---

## 🙏 Acknowledgements

Special thanks to the open-source community, the Arduino ecosystem, the STM32 development community, and everyone who contributes educational resources that make embedded systems learning more accessible.

Their tools, libraries, and documentation have played an important role in the development and learning process behind this project.

---

<p align="center">

**⭐ If you found this repository helpful, don't forget to star it! ⭐**

Made with ❤️ by **ShivsFoundry**

</p>


The repository is organized to separate the project source code from the documentation. The main Arduino program is stored inside the **Source_Code** directory, while the repository root contains the project documentation and GitHub community files. This structure keeps the project clean, organized, and easy to navigate for both beginners and contributors.
