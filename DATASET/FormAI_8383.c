//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_TEMP 40
#define MIN_TEMP -40
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

int main(){

  srand(time(NULL)); // to initialize random seed

  int temperature = rand() % (MAX_TEMP - MIN_TEMP) + MIN_TEMP; //random temperature
  int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY) + MIN_HUMIDITY; //random humidity

  printf("Welcome to the Weather Simulation Program\n\n");
  printf("Today's weather is:\n");
  printf("Temperature: %d C\n", temperature);
  printf("Humidity: %d %%\n", humidity);

  if (temperature > 30) {
    printf("It's extremely hot today, be sure to drink plenty of water and stay cool.\n");
  } else if (temperature > 20) {
    printf("It's warm today, enjoy the sunshine.\n");
  } else if (temperature > 0) {
    printf("It's a little chilly today, wear a coat.\n");
  } else {
    printf("It's freezing outside, make sure you bundle up.\n");
  }

  if (humidity > 80) {
    printf("It's very humid outside, you might want to stay indoors.\n");
  } else if (humidity > 60) {
    printf("It's a little humid outside, but nothing too bad.\n");
  } else {
    printf("The air is dry today, enjoy the weather.\n");
  }

  return 0;
}