# 4-Digit 7-Segment Display + HC-SR04 Sensor

A beginner-friendly Arduino project that measures distance with an **HC-SR04 ultrasonic sensor** and displays the result on a **4-digit 7-segment display**.

This project is an upgraded version of a 4-digit 7-segment display project, now with real-time distance measurement.

---

## About

The HC-SR04 ultrasonic sensor measures the distance to an object and the Arduino displays the measured value in **millimeters** on the 4-digit 7-segment display.

- **Sensor** → HC-SR04 ultrasonic distance sensor
- **Display** → 4-digit 7-segment display
- **Measurement unit** → millimeters (mm)
- **Maximum displayed value** → 9999
- **Board** → Arduino Mega 2560
- **Serial Monitor** → 9600 baud

This project is part of my learning journey with Arduino and Embedded Systems.

Feel free to use, modify, and learn from the code.

If this project helps you, a ⭐ on the repository is appreciated.

---

## Hardware

### Components

- Arduino Mega 2560
- HC-SR04 ultrasonic sensor
- 4-digit 7-segment display
- Breadboard
- Jumper wires
- USB cable

### Pin Configuration

**4-digit display digit pins:**

- Digit 1 → A1
- Digit 2 → A2
- Digit 3 → A3
- Digit 4 → A4

**7-segment pins:**

- A → Pin 5
- B → Pin 6
- C → Pin 7
- D → Pin 8
- E → Pin 9
- F → Pin 10
- G → Pin 11
- DP → Pin 12

**HC-SR04:**

- TRIG → Pin 22
- ECHO → Pin 24
- VCC → 5V
- GND → GND

See the `Photos/` folder for project photos.

---

## How to Use

### Arduino IDE

1. Open Arduino IDE.
2. Open `ArduinoIDE/4-digit-7-segment-display-Sensor HC-SR04.ino`.
3. Select **Tools → Board → Arduino Mega 2560**.
4. Select **Tools → Port → Your COM port**.
5. Click **Upload**.
6. Open Serial Monitor at **9600 baud** if you also want to see the measured distance there.

### Visual Studio Code

A Visual Studio Code version is also included.

The `VisualStudioCode/` folder contains:

- `Arduino.h` → lightweight Arduino stub used for working with the code in Visual Studio Code
- `4-digit-7-segment-display-Sensor-HC-SR04-VSC.cpp` → Visual Studio Code version of the project

The VSC source uses:

```cpp
#include "Arduino.h"
```

The original Arduino IDE sketch remains separate and unchanged.

---

## How It Works

### HC-SR04 Distance Measurement

The Arduino sends a short ultrasonic trigger pulse from the **TRIG** pin.

The HC-SR04 sends an ultrasonic wave and the **ECHO** pin stays HIGH for the time required for the wave to travel to the object and return.

The measured time is converted to millimeters:

```cpp
int distanceMm = duration * 0.343 / 2;
```

The sensor is read approximately every **50 ms**.

### 4-Digit Display

The display is controlled using **multiplexing**.

Instead of keeping all four digits active at the same time, the Arduino switches between them very quickly. Each digit is enabled for a short period while the correct segments are displayed.

Because this happens rapidly, all four digits appear to be continuously illuminated.

The measured distance is separated into four individual digits and displayed as a number from **0 to 9999**.

---

## Project Structure

```text
4-digit-7-segment-display-UPGRADE-Sensor-/
│
├── ArduinoIDE/
│   └── 4-digit-7-segment-display-Sensor HC-SR04.ino
│
├── VisualStudioCode/
│   ├── Arduino.h
│   └── 4-digit-7-segment-display-Sensor-HC-SR04-VSC.cpp
│
├── Photos/
│   └── ...
│
├── LICENSE
└── README.md
```

---

## What I Learned

- Working with the HC-SR04 ultrasonic sensor
- Measuring pulse duration with `pulseIn()`
- Converting ultrasonic travel time into distance
- Controlling a 4-digit 7-segment display
- Display multiplexing
- Working with arrays for segment patterns
- Using `millis()` for timed sensor measurements
- Serial Monitor output
- Arduino digital input and output
- Keeping Arduino IDE and Visual Studio Code versions of the same project

---

## Troubleshooting

### Display doesn't light

- Check the digit pin connections A1–A4.
- Check segment pins 5–12.
- Verify the display pinout.
- Check GND and power connections.

### Wrong numbers are displayed

- Check the segment wiring order A, B, C, D, E, F, G and DP.
- Make sure the digit pins are connected in the correct order.
- Verify whether your display type matches the logic used by the project.

### HC-SR04 doesn't measure distance

- Check TRIG on pin 22.
- Check ECHO on pin 24.
- Verify 5V and GND connections.
- Make sure there is an object in front of the sensor.

### Code won't upload

- Make sure **Arduino Mega 2560** is selected.
- Check the USB cable.
- Check the selected COM port.
- Try another USB port.

---

## License

This project is licensed under the MIT License.

See `LICENSE` for details.

---

Made while learning Arduino and Embedded Systems.
