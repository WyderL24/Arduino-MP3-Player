
#include <SD.h>       // Include the SD card library
#include <SPI.h>      // Include the SPI library for communication with the SD card
#include <TMRpcm.h>   // Include the TMRpcm library for playing MP3s

#define SD_CS_PIN 4      // Define the pin for the SD card module's Chip Select (CS)
#define SPEAKER_PIN 9    // Define the pin for the speaker output (PWM pin)
#define BUTTON_PIN 2     // Define the pin for the push button

// Create an instance of the TMRpcm class, specifying the speaker pin
TMRpcm tmrpcm;

// Variable to track the state of the button
bool isButtonPressed = false;

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

  // Set the speaker pin to be used by the library
  tmrpcm.speakerPin = SPEAKER_PIN;

  // Set the button pin as an input
  pinMode(BUTTON_PIN, INPUT);

  // Initialize the SD card module
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    while (1); // Stop the program if the SD card fails
  }
  Serial.println("SD card initialized successfully.");
  Serial.println("Ready to play music...");
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(BUTTON_PIN);

  // Check if the button is pressed
  if (buttonState == HIGH && !isButtonPressed) {
    // A button press is detected
    isButtonPressed = true;
    
    // Check if a song is already playing
    if (!tmrpcm.isPlaying()) {
      Serial.println("Button pressed! Playing music...");
      // Play the MP3 file. The '0' argument means it will not loop.
      // The file "track1.mp3" must be on the root of the SD card.
      if (!tmrpcm.play("track1.mp3")) {
        Serial.println("Failed to play track1.mp3!");
      }
    } else {
      Serial.println("Music is already playing.");
    }
  }

  // Check if the button is released
  if (buttonState == LOW && isButtonPressed) {
    // The button has been released, reset the state variable
    isButtonPressed = false;
  }
}
