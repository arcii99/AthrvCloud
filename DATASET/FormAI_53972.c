//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));

  int temperature = rand() % 30; // generate a random temperature between 0 and 30 °C
  int humidity = rand() % 100; // generate a random humidity between 0% and 100%
  int cloudiness = rand() % 100; // generate a random cloudiness between 0% and 100%
  
  printf("Welcome to our cheerful weather simulation!\n");

  if (temperature > 25) {
    printf("Wow, it's a sunny day today! The temperature is %d°C and the humidity is %d%%.\n", temperature, humidity);
  } else if (temperature > 15) {
    printf("It's a nice day outside! The temperature is %d°C and the humidity is %d%%.\n", temperature, humidity);
  } else {
    printf("Brrr, it's chilly outside! The temperature is %d°C and the humidity is %d%%.\n", temperature, humidity);
  }

  if (cloudiness > 75) {
    printf("But it looks like it might rain soon. The cloudiness is at %d%%.\n", cloudiness);
  } else if (cloudiness > 50) {
    printf("There are some clouds in the sky, but it's still a nice day. The cloudiness is at %d%%.\n", cloudiness);
  } else {
    printf("The sky is clear today, it's a good day to go outside! The cloudiness is at %d%%.\n", cloudiness);
  }

  return 0;
}