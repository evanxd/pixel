#include "Arduino.h"
#include "Pixel.h"

Pixel::Pixel(byte _dataPin, byte _loadPin, byte _clockPin)
{
  dataPin = _dataPin;
  loadPin = _loadPin;
  clockPin = _clockPin;
  for (int i = 0; i < MATRIX_WIDTH; i++) {
    for (int j = 0; j < MATRIX_HEIGHT; j++) {
      matrix[i][j] = false;
    }
  }
  pinMode(dataPin, OUTPUT);
  pinMode(loadPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  // Initialize MAX7219 chip.
  sendCommand(MAX7219_REG_DECODE_MODE, 0x00);
  sendCommand(MAX7219_REG_SCAN_LIMIT, 0x07);
  sendCommand(MAX7219_REG_SHUTDOWN, 0x01);
  sendCommand(MAX7219_REG_DISPLAY_TEST, 0x00);
  setIntensity(1);
  // Turn all LEDs off.
  for (int i = 0; i <= 8; i++) {
    sendCommand(i, 0);
  }
}

void Pixel::setIntensity(int intensity)
{
  sendCommand(MAX7219_REG_INTENTSITY, intensity);
}

void Pixel::render()
{

}

void Pixel::drawDot(int x, int y)
{
  matrix[x][y] = true;
  y = 0;
  for (int i = 0; i < MATRIX_HEIGHT; i++) {
    if (matrix[x][i]) {
      y += (1 << i);
    }
  }
  x = x + 1;
  sendCommand(x, y);
}

void Pixel::sendCommand(byte key, byte value)
{    
  digitalWrite(loadPin, LOW);
  sendData(key);
  sendData(value);
  digitalWrite(loadPin, LOW);
  digitalWrite(loadPin, HIGH);
}

void Pixel::sendData(byte data)
{
  byte mask;
  for (int i = 8; i > 0; i--) {
    mask = 0x01 << (i - 1);
    digitalWrite(clockPin, LOW);
    if (data & mask) {
      digitalWrite(dataPin, HIGH);
    } else {
      digitalWrite(dataPin, LOW);
    }
    digitalWrite(clockPin, HIGH);
  }
}
