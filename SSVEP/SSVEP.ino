/*
  Simple LED Toggling Circuit for SSVEP Stimulation Testing

  ** How to Use:
  *     1. Connect Some LEDs(No Matter What the Number is!) to an Arduino Board of Any Kind
  *     2. Place the LEDs Far Enough for Less Stimulation Interference
  *     2. Read the Notes Below for Frequency Selection
  *     3. Specify the Pins and the Desired Stimulation Frequency of them in Hz in the Code Below
  *     4. Compile/Run the Code and Enjoy
    

  Note that:
        1. The Recommended Frequency Range is About [5~100]Hz
        2. Lower Frequencies of [5~15]Hz are Often Used for SSVEP Experiments That Involve Simple Visual Tasks
        3. Higher Frequencies of [20~40] Hz May Be Used for More Cmplex Tasks.
*/

// Define the LED pins and LED Freqs in Below
const int LEDPin[] = {8, 9, 10, 11};
const int Freq[] = {9, 13, 17, 21};

// Number of LEDs to Toggle
const int LEDNum = sizeof(LEDPin) / sizeof(LEDPin[0]);

// Define the blink frequency in milliseconds
unsigned long BlinkInterval[LEDNum];

// Variables to Store the Current Time and the Last Time the LED Was Toggled
unsigned long CurrentMacros[LEDNum];
unsigned long PreviousMacros[LEDNum];

void setup() {
  for (int i = 0; i < LEDNum; i++) {
    // Calculate the Toggling Time in Micro Seconds
    BlinkInterval[i] = 1000000 / (2 * Freq[i]);

    // Initialize the LED pin as an OUTPUT
    pinMode(LEDPin[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < LEDNum; i++) {
    // Get the current time
    CurrentMacros[i] = micros();

    // Check if it's time to toggle the LED
    if (CurrentMacros[i] - PreviousMacros[i] >= BlinkInterval[i]) {
      // Save the last time the LED was toggled
      PreviousMacros[i] = CurrentMacros[i];

      // Change LED State
      digitalWrite(LEDPin[i], !digitalRead(LEDPin[i]));
    }
  }
}
