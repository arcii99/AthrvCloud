//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
  // Set the seed for the random number generator
  srand(time(NULL));

  // Declare variables to store the current temperature, humidity, wind speed, and precipitation rate
  float temperature = 0.0, humidity = 0.0, wind_speed = 0.0, precip_rate = 0.0;

  // Generate the initial weather data
  temperature = (rand() % 40) - 20;     // Generate a random temperature between -20C and 20C
  humidity = (rand() % 100) / 100.0;   // Generate a random humidity between 0 and 1
  wind_speed = (rand() % 200) / 10.0;  // Generate a random wind speed between 0 and 20 m/s
  precip_rate = (rand() % 50) / 100.0; // Generate a random precipitation rate between 0 and 0.5 mm/hour

  printf("Welcome to the CyberWeather Simulator!\n\n");

  // Simulate the weather for the next 24 hours
  for (int i = 0; i < 24; i++) 
  {
    printf("Hour %d: Temperature = %.1fC, Humidity = %.2f, Wind Speed = %.2fm/s, Precipitation Rate = %.2fmm/hour\n", i+1, temperature, humidity, wind_speed, precip_rate);

    // Adjustment variables that affect the next hour's weather 
    float temp_adj = ((rand() % 20) - 10) / 10.0; // Adjust the temperature by +/- 1.0C
    float humid_adj = ((rand() % 20) - 10) / 100.0; // Adjust the humidity by +/- 0.1
    float wind_adj = ((rand() % 20) - 10) / 10.0; // Adjust the wind speed by +/- 1.0 m/s
    float precip_adj = ((rand() % 20) - 10) / 100.0; // Adjust the precipitation rate by +/- 0.1 mm/hour

    // Update the weather data for the next hour
    temperature += temp_adj;
    humidity += humid_adj;
    wind_speed += wind_adj;
    precip_rate += precip_adj;

    // Check for extreme weather conditions and print warnings
    if (temperature < -10 || temperature > 30) 
    {
      printf("*** WARNING: EXTREME TEMPERATURE! SEEK SHELTER IMMEDIATELY! ***\n");
    }
    if (humidity < 0.2 || humidity > 0.8) 
    {
      printf("*** WARNING: EXTREME HUMIDITY! AVOID OVEREXERTION! ***\n");
    }
    if (wind_speed > 15) 
    {
      printf("*** WARNING: HIGH WIND SPEEDS! SECURE ALL LOOSE OBJECTS! ***\n");
    }
    if (precip_rate > 0.3) 
    {
      printf("*** WARNING: HEAVY PRECIPITATION! WATCH OUT FOR FLASH FLOODS! ***\n");
    }

    // Delay the program by one second to simulate the passage of time
    sleep(1);
  }

  printf("\nThanks for using the CyberWeather Simulator! Stay safe out there.\n");

  return 0;
}