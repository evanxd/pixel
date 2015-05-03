#ifndef _Pixel_H_
#define _Pixel_H_

#define MAX7219_REG_NOOP         0x00
#define MAX7219_REG_DIGIT0       0x01
#define MAX7219_REG_DIGIT1       0x02
#define MAX7219_REG_DIGIT2       0x03
#define MAX7219_REG_DIGIT3       0x04
#define MAX7219_REG_DIGIT4       0x05
#define MAX7219_REG_DIGIT5       0x06
#define MAX7219_REG_DIGIT6       0x07
#define MAX7219_REG_DIGIT7       0x08
#define MAX7219_REG_DECODE_MODE  0x09
#define MAX7219_REG_INTENTSITY   0x0a
#define MAX7219_REG_SCAN_LIMIT   0x0b
#define MAX7219_REG_SHUTDOWN     0x0c
#define MAX7219_REG_DISPLAY_TEST 0x0f

class Pixel
{
  private:
    byte dataPin;
    byte loadPin;
    byte clockPin;
    byte matrix[][];

  public:
    Pixel(byte dataPin, byte loadPin, byte clockPin, byte* matrix);
    void setIntensity(int intensity);
    void render();
};

#endif