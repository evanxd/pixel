# Pixel
A game engine for a LED matrix controlled by MAX7219.

## Installation
1. Switch to the `Arduino/libraries` directory in terminal.
2. Run `git clone https://github.com/evanxd/pixel.git`.
3. Restart the Arduino IDE.

## Usage
Import and declare Pixel in your project.
```
#include <Pixel.h>
/**
 * 10 is the Data In pin.
 * 16 is the CS pin.
 * 14 is the Clock pin.
 */
Pixel pixel(10, 16, 14); 
```

Draw a dot on the coordinate (0, 0) of LED matrix.
```
pixel.matrix[0][0] = true;
pixel.render();
```

Clean the (0, 0) dot.
```
pixel.matrix[0][0] = false;
pixel.render();
```
