/*
===============================================================================
                    STM32-Based Automatic Door Controller
===============================================================================

Project      : STM32-Based Automatic Door Controller
Platform     : STM32F103C8T6 (Blue Pill)
IDE          : Arduino IDE
Language     : C++
Author       : ShivsFoundry
License      : MIT License
Version      : 1.0

-------------------------------------------------------------------------------
Description
-------------------------------------------------------------------------------

This project demonstrates an automatic door control system using the
STM32F103C8T6 (Blue Pill) microcontroller.

The system automatically opens and closes a door using:

• PIR Motion Sensor (Entry Detection)
• IR Sensor (Exit Detection)
• SG90 Servo Motor (Door Actuation)
• SSD1306 OLED Display (System Status)

Features
--------
✓ Automatic Door Opening
✓ Automatic Door Closing
✓ Entry Detection using PIR Sensor
✓ Exit Detection using IR Sensor
✓ Smooth Servo Movement
✓ OLED Status Display
✓ Serial Monitor Debug Messages

Required Libraries
------------------
• Servo.h
• Wire.h
• Adafruit_GFX.h
• Adafruit_SSD1306.h

===============================================================================
*/


//=============================================================================
//                              Library Files
//=============================================================================

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//=============================================================================
//                           Pin Configuration
//=============================================================================

#define PIR_PIN         PA0      // Entry PIR Motion Sensor
#define IR_PIN          PA2      // Exit IR Sensor (Active LOW)
#define SERVO_PIN       PA1      // Servo Motor Signal Pin

#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   64


//=============================================================================
//                           OLED Display Setup
//=============================================================================

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


//=============================================================================
//                           Servo Motor Setup
//=============================================================================

Servo myservo;


//=============================================================================
//                         Door Position Angles
//=============================================================================

const int openAngle  = 90;
const int closeAngle = 0;


//=============================================================================
//                          System Variables
//=============================================================================

unsigned long doorOpenTime = 0;
bool doorIsOpen = false;


//=============================================================================
//                     Smooth Servo Movement Function
//=============================================================================

void smoothServoWrite(int targetAngle)
{
    int current = myservo.read();

    // Rotate servo clockwise
    if (current < targetAngle)
    {
        for (int pos = current; pos <= targetAngle; pos++)
        {
            myservo.write(pos);
            delay(8);
        }
    }

    // Rotate servo anticlockwise
    else
    {
        for (int pos = current; pos >= targetAngle; pos--)
        {
            myservo.write(pos);
            delay(8);
        }
    }
}


//=============================================================================
//                    OLED Center Text with Bold Effect
//=============================================================================

void printCenteredBold(const char *text, int textSize)
{
    display.setTextSize(textSize);

    int16_t x1, y1;
    uint16_t w, h;

    display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

    int x = (SCREEN_WIDTH - w) / 2;
    int y = (SCREEN_HEIGHT - h) / 2;

    display.setTextColor(SSD1306_WHITE);

    // Print text multiple times to create a bold effect
    display.setCursor(x, y);
    display.print(text);

    display.setCursor(x + 1, y);
    display.print(text);

    display.setCursor(x, y + 1);
    display.print(text);

    display.setCursor(x + 1, y + 1);
    display.print(text);
}


//=============================================================================
//                               Setup Function
//=============================================================================

void setup()
{
    // Initialize Serial Monitor
    Serial.begin(9600);

    // Configure Sensor Pins
    pinMode(PIR_PIN, INPUT);
    pinMode(IR_PIN, INPUT_PULLUP);

    // Attach Servo Motor
    myservo.attach(SERVO_PIN);

    // Move Door to Closed Position
    myservo.write(closeAngle);

    // Initialize I²C Communication
    Wire.begin();

    // Initialize OLED Display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED failed to start");

        while (true);
    }

    // Display Startup Screen
    display.clearDisplay();
    printCenteredBold("ShivsFoundry", 2);
    display.display();

    Serial.println("System Ready...");
}


//=============================================================================
//                              Main Program
//=============================================================================

void loop()
{
    // Read Sensor Values
    int pirState = digitalRead(PIR_PIN);
    int irState  = digitalRead(IR_PIN);


    //---------------------------------------------------------------------
    // Entry Detection using PIR Sensor
    //---------------------------------------------------------------------

    if (pirState == HIGH)
    {
        Serial.println("ENTRY: Motion Detected");

        if (!doorIsOpen)
        {
            smoothServoWrite(openAngle);

            display.clearDisplay();
            printCenteredBold("WELCOME TO ShivsFoundry", 2);
            display.display();

            doorIsOpen = true;
            doorOpenTime = millis();
        }
        else
        {
            doorOpenTime = millis();
        }
    }


    //---------------------------------------------------------------------
    // Exit Detection using IR Sensor
    //---------------------------------------------------------------------

    else if (irState == LOW)
    {
        delay(50);

        if (digitalRead(IR_PIN) == LOW)
        {
            Serial.println("EXIT: Motion Detected");

            if (!doorIsOpen)
            {
                smoothServoWrite(openAngle);

                // OLED remains unchanged during exit

                doorIsOpen = true;
                doorOpenTime = millis();
            }
            else
            {
                doorOpenTime = millis();
            }
        }
    }


    //---------------------------------------------------------------------
    // No Motion Detected
    //---------------------------------------------------------------------

    else if (!doorIsOpen)
    {
        display.clearDisplay();

        printCenteredBold("ShivsFoundry", 2);

        display.display();
    }


    //---------------------------------------------------------------------
    // Automatically Close Door after Delay
    //---------------------------------------------------------------------

    if (doorIsOpen && (millis() - doorOpenTime >= 4000))
    {
        smoothServoWrite(closeAngle);

        if (pirState == HIGH)
        {
            Serial.println("ENTRY: Door Closing");
        }
        else if (irState == LOW)
        {
            Serial.println("EXIT: Door Closing");
        }

        display.clearDisplay();

        printCenteredBold("ShivsFoundry", 2);

        display.display();

        doorIsOpen = false;
    }
}


//=============================================================================
//                               End of File
//=============================================================================