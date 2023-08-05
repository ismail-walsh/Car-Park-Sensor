# Arduino Park Sensor System Readme

## Introduction

The Arduino Park Sensor System is a project designed to indicate the number of available parking spaces in a parking lot. It uses a 2-digit 7-segment display to show the count of available parking spaces and three RGB LEDs to display different colors based on the count. Additionally, it includes a buzzer to provide audible feedback.

## Components

To build this project, you will need the following components:

- Arduino board (e.g., Arduino Uno)
- 2-digit 7-segment display
- Three RGB LEDs (common anode)
- Buzzer
- Resistors and wiring components
- Pushbuttons (two for controlling the count)

## Wiring

The components need to be wired as follows:

- 2-digit 7-segment display:
  - Connect common cathode pin (COM) to GND
  - Connect each segment pin to the corresponding Arduino pins (dig1 and dig2)
- RGB LEDs:
  - Connect the common anode of each RGB LED to 5V
  - Connect each color pin (green, red, and blue) to the corresponding Arduino pins
- Buzzer:
  - Connect the positive terminal of the buzzer to a digital pin (buzzer)
- Pushbuttons:
  - Connect one terminal of each pushbutton to 5V
  - Connect the other terminal of each pushbutton to the corresponding Arduino pins (buttonPin and buttonPin2)

## Code Overview

The Arduino sketch provided controls the functionality of the Park Sensor System. Here are the main components:

### Definitions and Constants

The sketch defines various pins used to control the 2-digit 7-segment display, RGB LEDs, and pushbuttons. It also defines constants for different segments and numbers to be displayed.

### Function Setup

The setup function is called once when the Arduino starts. It sets the pin modes for the LEDs, buzzer, and pushbuttons. It also initializes the display to show the number 0.

### Function putByte

The putByte function is responsible for displaying a specific number on the 2-digit 7-segment display. It shifts the corresponding byte pattern to the display.

### Function playTone

The playTone function generates a sound on the buzzer with a specified tone and duration. It is used for audible feedback when buttons are pressed.

### Function buttonCheck and buttonCheck2

These functions check the status of the two pushbuttons and debounce the input. They return 1 when a button is pressed and 0 otherwise.

### Function loop

The loop function is the main part of the code, where the system operates continuously. It monitors the pushbutton inputs and updates the display and LED colors based on the count.

## Usage

1. Connect all the components correctly as per the wiring instructions provided above.
2. Upload the provided Arduino sketch to your Arduino board.
3. Power up the system and observe the 2-digit display and the RGB LEDs.
4. Press the first pushbutton to increment the count of available parking spaces.
5. Press the second pushbutton to decrement the count of available parking spaces.
6. When the count reaches the maximum (99), the RGB LEDs will turn red, indicating that the parking lot is full.
7. If you press the second pushbutton while the count is zero, an error alarm will sound, and the count will reset to zero.

Remember that this project is a simple demonstration and can be expanded upon for more sophisticated applications.

## Troubleshooting

If you encounter any issues, make sure to check the wiring connections first. Verify that the components are correctly connected and that there are no loose connections. Additionally, check the power supply and ensure it provides enough current for all components.

If you have any questions or need further assistance, feel free to ask for support or refer to the Arduino community for help.

## License

This project and code are provided as-is without any warranty. You are free to use and modify the code for personal and educational purposes. However, please note that any commercial use or distribution of this project may require proper attribution and compliance with licensing terms.

---

Note: The provided readme file contains instructions, explanations, and troubleshooting for the Arduino Park Sensor System project. Please feel free to customize the content as needed and add any additional details or sections depending on the target audience and purpose of the project.
