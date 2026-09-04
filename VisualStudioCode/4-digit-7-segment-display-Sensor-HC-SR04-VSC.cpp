#include "Arduino.h"

// HC-SR04 + 4-digit 7-segment display
// Arduino Mega 2560

// Pins for the 4 digits
int digitPins[] = {A1, A2, A3, A4};

// Pins for segments: A, B, C, D, E, F, G, DP
int segmentPins[] = {5, 6, 7, 8, 9, 10, 11, 12};

// Segment patterns for numbers 0-9
// {A, B, C, D, E, F, G, DP}
int numbers[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

// HC-SR04
const int trigPin = 22;
const int echoPin = 24;

// Distance
int distance = 0;

unsigned long previousMillis = 0;

// How often to measure distance
int sensorDelay = 50;

int getDistance();
void displayNumber(int number);

void setup()
{
  // Set digit pins as outputs
  for (int i = 0; i < 4; i++)
  {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }

  // Set segment pins as outputs
  for (int i = 0; i < 8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  // HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  // Continuously refresh the display
  displayNumber(distance);

  // Measure distance every 50 ms
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= sensorDelay)
  {
    previousMillis = currentMillis;
    distance = getDistance();
  }
}

// ========================================
// HC-SR04 distance measurement
// ========================================

int getDistance()
{
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Measure how long ECHO stays HIGH
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Convert time into millimeters
  int distanceMm = duration * 0.343 / 2;

  return distanceMm;
}

// ========================================
// Display number
// ========================================

void displayNumber(int number)
{
  // Limit maximum value to 9999
  if (number > 9999)
  {
    number = 9999;
  }

  // Split number into four digits
  int digits[4];

  digits[0] = number / 1000;
  digits[1] = (number / 100) % 10;
  digits[2] = (number / 10) % 10;
  digits[3] = number % 10;

  // Display each digit one by one
  for (int i = 0; i < 4; i++)
  {
    // Turn all digits off
    for (int j = 0; j < 4; j++)
    {
      digitalWrite(digitPins[j], HIGH);
    }

    // Set segments
    for (int k = 0; k < 8; k++)
    {
      digitalWrite(segmentPins[k], numbers[digits[i]][k]);
    }

    // Turn on current digit
    digitalWrite(digitPins[i], LOW);

    delay(1);

    // Turn current digit off
    digitalWrite(digitPins[i], HIGH);
  }
}
