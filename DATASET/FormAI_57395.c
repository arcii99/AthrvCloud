//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature
float generateTemperature() {
  float temperature = (float) (rand() % 30) + (float)(rand() % 10)/10.0;
  return temperature;
}

// Function to generate random humidity
float generateHumidity() {
  float humidity = (float) (rand() % 50) + (float) (rand() % 50)/100.0;
  return humidity;
}

// Function to generate random wind speed
float generateWindSpeed() {
  float windSpeed = (float) (rand() % 60) + (float) (rand() % 10)/10.0;
  return windSpeed;
}

void displayWeatherInfo(int hour, float temperature, float humidity, float windSpeed) {
  printf("At %d:00 hrs, Temperature is %.1f °C with Humidity %.1f %% and Wind Speed %.1f km/h\n", hour, temperature, humidity, windSpeed);
}

int main() {
  
  // Initializing random number generator
  srand(time(NULL));
  
  // Generating weather data for 24 hours
  for(int hour=0; hour<=23; hour++) {
    
    // Generating random weather attributes
    float temperature = generateTemperature();
    float humidity = generateHumidity();
    float windSpeed = generateWindSpeed();
    
    // Displaying weather information for the hour
    displayWeatherInfo(hour, temperature, humidity, windSpeed);
  }
  
  return 0;
}