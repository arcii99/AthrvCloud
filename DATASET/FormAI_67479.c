//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  int weatherConditions[5] = {1, 2, 3, 4, 5};
  char* weatherDescriptions[5] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy"};
  
  int temperature = rand() % 41 - 20;
  int humidity = rand() % 101;
  int windSpeed = rand() % 101;
  int weatherIndex = rand() % 5;
  
  printf("Today's forecast:\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d %%\n", humidity);
  printf("Wind Speed: %d km/h\n", windSpeed);
  printf("Weather: %s\n", weatherDescriptions[weatherIndex]);
  
  switch(weatherConditions[weatherIndex]) {
    case 1: //Sunny
      printf("It's a beautiful day! Perfect for a picnic.\n");
      break;
    case 2: //Cloudy
      printf("It looks like it might rain later, better bring an umbrella.\n");
      break;
    case 3: //Rainy
      printf("Don't forget your rain boots and a raincoat, it's going to be a wet one!\n");
      break;
    case 4: //Stormy
      printf("Stay safe and indoors, there's a storm coming.\n");
      break;
    case 5: //Snowy
      printf("It's time to break out the warm coat and snow boots, we're in for a snowy day.\n");
      break;
    default:
      printf("Error: invalid weather condition.\n");  
  }
  
  return 0;
}