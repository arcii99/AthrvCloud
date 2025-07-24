//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program simulates a traffic light controller system with statistical
 * analysis of the performed actions. It's a three-way intersection with two
 * traffic lights for each direction, one for each side of the road. Each
 * traffic light works on a fixed cycle, with green light for 15 seconds, then
 * yellow for 2 seconds, then red for 18 seconds.
 */

// Functions declarations
void display_statistics(void);

// Variables for statistical analysis
int north_south_cars = 0, east_west_cars = 0;
int north_south_red = 0, east_west_red = 0;

int main(void) {
  // Seed the random generator
  srand(time(NULL));

  // Initialize traffic lights states
  int north_south_state = 0, east_west_state = 0;

  // Start the simulation loop
  for (int i = 0; i < 100; i++) {
    // Check if any car arrived on the north-south direction
    if (rand() % 2 == 0) {
      north_south_cars++;
      if (east_west_state == 2) {
        east_west_red++;
        printf("Car on north-south direction stopped at red light.\n");
      } else {
        printf("Car on north-south direction passed free light.\n");
      }
    }

    // Check if any car arrived on the east-west direction
    if (rand() % 2 == 0) {
      east_west_cars++;
      if (north_south_state == 2) {
        north_south_red++;
        printf("Car on east-west direction stopped at red light.\n");
      } else {
        printf("Car on east-west direction passed free light.\n");
      }
    }

    // Toggle the north-south traffic light
    if (north_south_state == 0 && east_west_state == 2) {
      north_south_state = 1;
      east_west_state = 1;
      printf("North-south traffic light turned green. East-west turned red.\n");
    } else if (north_south_state == 1) {
      north_south_state = 2;
      printf("North-south traffic light turned yellow.\n");
    } else if (north_south_state == 2) {
      north_south_state = 0;
      printf("North-south traffic light turned red.\n");
    }

    // Toggle the east-west traffic light
    if (north_south_state == 2 && east_west_state == 0) {
      east_west_state = 1;
      north_south_state = 1;
      printf("East-west traffic light turned green. North-south turned red.\n");
    } else if (east_west_state == 1) {
      east_west_state = 2;
      printf("East-west traffic light turned yellow.\n");
    } else if (east_west_state == 2) {
      east_west_state = 0;
      printf("East-west traffic light turned red.\n");
    }

    // Wait for the traffic light cycle to finish
    printf("Waiting for 18 seconds...\n");
    for (int j = 0; j < 18; j++) {
      printf("%i ", j + 1);
      fflush(stdout);
      sleep(1);
    }
    printf("\n");

    // Wait for the traffic light yellow phase
    printf("Waiting for 2 seconds...\n");
    for (int j = 0; j < 2; j++) {
      printf("%i ", j + 1);
      fflush(stdout);
      sleep(1);
    }
    printf("\n\n");
  }

  // Display the statistical analysis
  display_statistics();

  return 0;
}

void display_statistics(void) {
  printf("Simulation ended. Here are the statistics:\n");
  printf("Percentage of time north-south green: %.2f%%\n",
         (float) 50 / 70 * 100);
  printf("Percentage of time east-west green: %.2f%%\n", (float) 20 / 70 * 100);
  printf("Number of cars passing on north-south direction: %i\n",
         north_south_cars);
  printf("Number of cars stopping on north-south red light: %i\n",
         north_south_red);
  printf("Percentage of stopped cars on north-south red light: %.2f%%\n",
         (float) north_south_red / north_south_cars * 100);
  printf("Number of cars passing on east-west direction: %i\n", east_west_cars);
  printf("Number of cars stopping on east-west red light: %i\n",
         east_west_red);
  printf("Percentage of stopped cars on east-west red light: %.2f%%\n",
         (float) east_west_red / east_west_cars * 100);
}