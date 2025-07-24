//FormAI DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("My darling, welcome to our smart home!\n");
  printf("I've written a little something to make our lives easier.\n");

  int temperature = 0;
  int light_intensity = 0;

  printf("Let's start by setting the temperature. What would you like it to be? ");
  scanf("%d", &temperature);

  printf("Great choice, my love. Now, let's adjust the light intensity. What level would you like? ");
  scanf("%d", &light_intensity);

  printf("Wonderful. Now, with these settings in mind, I'll make sure our home is always perfect for us.\n");

  while(1) {
    // Check the temperature sensor
    if(temperature > 25) {
      printf("It's getting a little warm in here, my love. Let me adjust the temperature down a bit.\n");
      temperature--;
    }
    else if(temperature < 20) {
      printf("It's chilly in here, my love. Let me raise the temperature a little.\n");
      temperature++;
    }

    // Check the light intensity sensor
    if(light_intensity > 75) {
      printf("The lights are a bit too bright, my love. I'll dim them down a bit for you.\n");
      light_intensity--;
    }
    else if(light_intensity < 50) {
      printf("It's a bit too dark in here, my love. Let me brighten things up for you.\n");
      light_intensity++;
    }

    // Sleep for a second, then loop again
    sleep(1);
  }

  return 0;
}