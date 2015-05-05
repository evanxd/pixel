# Pixel
A game engine for LED matrix.

## Installation
1. Switch to the `Arduino/libraries` directory in terminal.
2. Run `git clone https://github.com/evanxd/pixel.git`.
3. Restart the Arduino IDE.

## Usage
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
