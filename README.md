# Arduino-MP3-Player

/*
 * **Project: Simple Arduino MP3 Player with Push Button**
 * Description: This project plays an MP3 file from an SD card when a button is pressed.
 * It's a great beginner project for creating a simple, custom music player.
 *
 * **Components Needed:**
 * 1. Arduino Uno or similar board
 * 2. SD Card Reader Module
 * 3. SD Card (pre-formatted with a single MP3 file named "track1.mp3")
 * 4. Push Button
 * 5. 10k ohm Resistor (for the button pull-down circuit)
 * 6. Speaker (an 8 ohm speaker works well)
 * 7. Breadboard and Jumper Wires
 *
 * **Libraries Required:**
 * 1. SD.h (Built-in to Arduino IDE)
 * 2. TMRpcm.h (You need to install this library via the Library Manager in the Arduino IDE.
 * Search for "TMRpcm" and install it.)
 *
 * **TMRpcm Library Notes:**
 * This library uses a PWM pin to output audio. It's a simple, low-cost solution.
 * The output quality is not CD quality, but it is perfect for a small gift project.
 * Pin 9 is used as the default audio output on most Arduino boards.
 *
 * **Wiring Diagram:**
 *
 * **SD Card Module to Arduino:**
 * VCC -> 5V
 * GND -> GND
 * MOSI -> Pin 11
 * MISO -> Pin 12
 * SCK -> Pin 13
 * CS -> Pin 4 (This is the chip select pin, you can change it if you want)
 *
 * **Push Button to Arduino:**
 * One leg of the button -> 5V
 * Other leg of the button -> Pin 2
 * A 10k ohm resistor from the button leg connected to Pin 2 -> GND (This is a pull-down resistor)
 *
 * **Speaker to Arduino:**
 * Speaker positive (+) -> Pin 9
 * Speaker negative (-) -> GND
 *
 * **How it Works:**
 * - The code initializes the SD card and sets up the audio output.
 * - The 'loop' function constantly checks if the button on Pin 2 is pressed.
 * - A simple debouncing mechanism (using the `isButtonPressed` variable) prevents the music from restarting multiple times with a single press.
 * - When the button is pressed, the code checks if the music is already playing. If it's not, it plays the "track1.mp3" file.
 * - You MUST have an MP3 file named "track1.mp3" on the root directory of your SD card.
 *
 */
