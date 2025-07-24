//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the intergalactic rollercoaster ride!\n");
  printf("Fasten your seatbelts and get ready to travel through the Solar System!\n");

  int sun_x = 0; // position of the Sun on x-axis
  int sun_y = 0; // position of the Sun on y-axis
  int earth_x = 100; // position of the Earth on x-axis
  int earth_y = 0; // position of the Earth on y-axis
  double distance_to_sun = 100; // distance of the Earth from the Sun
  double earth_speed = 0.1; // how fast the Earth is moving

  while (1) { // infinite loop for continuous motion
    // calculate new position of the Earth based on its speed
    earth_x += earth_speed;
    distance_to_sun = earth_x - sun_x;
    earth_y = (int) (sqrt(10000 - (distance_to_sun * distance_to_sun)) + 0.5);

    // print current position of the Earth
    printf("\rEarth: [%d, %d]", earth_x, earth_y);
    fflush(stdout);

    // wait for a short while to make the motion visible
    for (int i = 0; i < 10000000; i++);

    // clear the previous output so that the new one can be printed
    printf("\r            ");
    fflush(stdout);
  }

  return 0;
}