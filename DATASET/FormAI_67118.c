//FormAI DATASET v1.0 Category: Weather simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator

  int temperature = (rand() % 41) - 20; // generate a random temperature between -20 and 20 degrees Celsius
  int humidity = rand() % 101; // generate a random humidity value between 0 and 100

  printf("Current Temperature: %d°C\n", temperature);
  printf("Current Humidity: %d%%\n", humidity);

  if (temperature <= 0) {
    printf("Brrr! It's freezing out there. Make sure to wear a warm coat.\n");
  } else if (temperature > 0 && temperature <= 15) {
    printf("It's a bit chilly outside. Don't forget to bring a sweater.\n");
  } else if (temperature > 15 && temperature <= 25) {
    printf("It's a lovely day outside! Enjoy the weather.\n");
  } else {
    printf("Wow, it's really hot out there. Drink plenty of water!\n");
  }

  if (humidity < 30) {
    printf("It's quite dry out there. Keep hydrated.\n");
  } else if (humidity >= 30 && humidity < 60) {
    printf("The humidity level is just right. Enjoy the weather.\n");
  } else {
    printf("It's quite humid outside. Make sure to stay cool.\n");
  }

  return 0;
}