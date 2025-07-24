//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Initializing variables
  int temperature = 0;
  int humidity = 0;
  int wind_speed = 0;
  
  // Setting current time as seed for random number generator
  srand(time(0));
  
  // Generating random values for temperature, humidity, and wind speed
  temperature = rand() % 40;
  humidity = rand() % 101;
  wind_speed = rand() % 51;
  
  // Displaying the weather simulation
  printf("**********************************************\n");
  printf("           Today's Weather Simulation          \n");
  printf("**********************************************\n\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d %%\n", humidity);
  printf("Wind Speed: %d km/h\n", wind_speed);
  
  // Determining the weather conditions based on the generated values
  if (temperature >= 30 && humidity >= 60 && wind_speed <= 30)
  {
    printf("\nConditions: Hot and Humid with Light Breezes\n");
  }
  else if (temperature <= 10 && humidity <= 50 && wind_speed >= 40)
  {
    printf("\nConditions: Cold and Dry with Strong Winds\n");
  }
  else
  {
    printf("\nConditions: Normal\n");
  }
  
  return 0;
}