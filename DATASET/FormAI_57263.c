//FormAI DATASET v1.0 Category: Weather simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Simulate temperature
  int temp = rand() % 101;
  printf("Current temperature: %d degrees Fahrenheit\n", temp);

  // Simulate precipitation
  int precipitation = rand() % 2; // 0 = no precipitation, 1 = precipitation
  if (precipitation) {
    printf("It's currently raining or snowing\n");
  } else {
    printf("No precipitation currently\n");
  }

  // Simulate wind speed and direction
  int wind_speed = rand() % 31;
  char* wind_dir;
  switch(rand() % 8) {
    case 0:
      wind_dir = "North";
      break;
    case 1:
      wind_dir = "Northeast";
      break;
    case 2:
      wind_dir = "East";
      break;
    case 3:
      wind_dir = "Southeast";
      break;
    case 4:
      wind_dir = "South";
      break;
    case 5:
      wind_dir = "Southwest";
      break;
    case 6:
      wind_dir = "West";
      break;
    case 7:
      wind_dir = "Northwest";
      break;
  }
  printf("Wind speed: %d mph, wind direction: %s\n", wind_speed, wind_dir);

  // Simulate humidity
  int humidity = rand() % 101;
  printf("Current humidity: %d%%\n", humidity);

  return 0;
}