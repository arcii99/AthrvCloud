//FormAI DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed random number generator
  srand(time(0));

  // Generate random temperature
  int temp = rand() % 100;

  // Generate random precipitation
  int precip = rand() % 10;

  // Generate random wind speed
  int wind = rand() % 50;

  // Check temperature and precipitation levels
  if (temp > 80 && precip < 2) {
    printf("The sun beats down mercilessly as the world bakes in the heat.\n");
  } else if (temp < 40 && precip > 6) {
    printf("The snow falls in a hypnotic dance, covering the world in a pristine white blanket.\n");
  } else {
    // Randomly generate cloud cover
    int clouds = rand() % 10;
  
    // Check wind speed and cloud cover
    if (wind > 30 && clouds > 5) {
      printf("The wind whips through the world, driving the clouds across the sky in a frenzied chase.\n");
    } else if (wind < 10 && clouds < 3) {
      printf("The world is still and quiet, as if holding its breath in anticipation.\n");
    } else {
      printf("The world is an ever-changing canvas, painted in hues of %d degrees, %d mm of precipitation, and %d km/h of wind.\n", temp, precip, wind);
    }
  }

  return 0;
}