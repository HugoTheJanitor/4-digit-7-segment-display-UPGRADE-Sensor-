#ifndef ARDUINO_STUB_H
#define ARDUINO_STUB_H

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0
#define INPUT_PULLUP 2

#ifndef A1
#define A1 55
#endif
#ifndef A2
#define A2 56
#endif
#ifndef A3
#define A3 57
#endif
#ifndef A4
#define A4 58
#endif

typedef unsigned char byte;

inline void pinMode(int, int) {}
inline void digitalWrite(int, int) {}
inline int digitalRead(int) { return HIGH; }
inline void analogWrite(int, int) {}
inline void delay(unsigned long) {}
inline void delayMicroseconds(unsigned int) {}
inline unsigned long millis() { return 0; }
inline unsigned long pulseIn(int, int) { return 0; }

class SerialStub
{
public:
  void begin(unsigned long) {}
  void print(const char*) {}
  void print(int) {}
  void println(const char*) {}
  void println(int) {}
};

inline SerialStub Serial;

#endif
