//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 1000
#define MAX_FLIGHTS 10
#define MAX_LOADERS 5
#define MAX_BELTS 5

int main() {
  srand(time(NULL)); // seed the random number generator

  int num_bags = rand() % MAX_BAGGAGE + 1; // randomly generate the number of bags
  printf("Number of bags: %d\n", num_bags);

  int num_flights = rand() % MAX_FLIGHTS + 1; // randomly generate the number of flights
  printf("Number of flights: %d\n\n", num_flights);

  int total_bags_loaded = 0; // initialize the total number of bags loaded

  // initialize the loaders and belts arrays
  int loaders[MAX_LOADERS] = {0};
  int belts[MAX_BELTS] = {0};

  // begin the simulation
  printf("Simulation starting...\n\n");

  for (int i = 1; i <= num_flights; i++) {
    printf("Flight %d arriving...\n", i);

    int bags_loaded = 0; // initialize the number of bags loaded on this flight

    for (int j = 0; j < MAX_LOADERS; j++) {
      if (loaders[j] == 0) { // if the loader is available
        printf("Loader %d is loading baggage...\n", j+1);

        // simulate loading bags onto the loader
        int bags_on_loader = rand() % 4 + 1;
        printf("Loader %d is loading %d bags.\n", j+1, bags_on_loader);

        // move the bags from the loader to the belts
        for (int k = 0; k < MAX_BELTS; k++) {
          if (belts[k] == 0) { // if the belt is available
            printf("Belt %d is moving bags...\n", k+1);

            // simulate moving bags from the loader to the belt
            int bags_on_belt = rand() % 3 + 1;
            printf("Belt %d is receiving %d bags.\n", k+1, bags_on_belt);

            // update the number of bags loaded and the total number of bags loaded
            bags_loaded += bags_on_belt;
            total_bags_loaded += bags_on_belt;

            // mark the loader and belt as busy
            loaders[j] = 1;
            belts[k] = 1;

            // break out of the loop once the bags have been moved
            break;
          }
        }

        // break out of the loop once the bags have been loaded onto the loader
        break;
      }
    }

    printf("Flight %d loaded with %d bags.\n\n", i, bags_loaded);
  }

  // output the results
  printf("Simulation complete.\nTotal number of bags loaded: %d\n", total_bags_loaded);

  return 0;
}