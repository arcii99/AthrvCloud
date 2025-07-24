//FormAI DATASET v1.0 Category: Smart home automation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare global variables
int temperature = 70; // in Fahrenheit
int humidity = 50; // in percentage

// Function to adjust the temperature
void adjustTemperature(int degrees) {
  temperature += degrees;
  
  // Check if temperature goes out of limits
  if (temperature < 60) {
    temperature = 60;
    printf("Temperature cannot go below 60 degrees Fahrenheit\n");
  } else if (temperature > 80) {
    temperature = 80;
    printf("Temperature cannot go above 80 degrees Fahrenheit\n");
  } else {
    printf("Temperature set to %d degrees Fahrenheit\n", temperature);
  }
}

// Function to adjust the humidity
void adjustHumidity(int percentage) {
  humidity += percentage;
  
  // Check if humidity goes out of limits
  if (humidity < 30) {
    humidity = 30;
    printf("Humidity cannot go below 30%%\n");
  } else if (humidity > 70) {
    humidity = 70;
    printf("Humidity cannot go above 70%%\n");
  } else {
    printf("Humidity set to %d%%\n", humidity);
  }
}

// Function to turn on/off the lights
void toggleLights(bool state) {
  if (state) {
    printf("Lights turned on\n");
  } else {
    printf("Lights turned off\n");
  }
}

// Main function
int main() {
  
  // Simulate temperature dropping by 5 degrees
  adjustTemperature(-5);
  
  // Simulate increase in humidity by 10%
  adjustHumidity(10);
  
  // Turn on the lights
  toggleLights(true);
  
  // Simulate temperature increase by 10 degrees
  adjustTemperature(10);
  
  // Simulate decrease in humidity by 20%
  adjustHumidity(-20);
  
  // Turn off the lights
  toggleLights(false);
  
  return 0;
}