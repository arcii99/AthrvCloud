//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mathematical
// Airport Baggage Handling Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000 // maximum number of bags

// Define structs for the flights and bags
typedef struct {
  int flight_num; // flight number
  int num_bags; // number of bags for this flight
} Flight;

typedef struct {
  int bag_id; // bag ID
  int flight_num; // assigned flight number
} Bag;

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Define arrays for flights and bags
  Flight flights[10];
  Bag bags[MAX_BAGS];

  // Assign random number of bags for each flight
  for (int i = 0; i < 10; i++) {
    flights[i].flight_num = i + 1;
    flights[i].num_bags = rand() % 100 + 1;
  }

  // Assign random flight number for each bag
  for (int i = 0; i < MAX_BAGS; i++) {
    bags[i].bag_id = i + 1;
    bags[i].flight_num = rand() % 10 + 1;
  }

  // Simulate baggage handling system
  int num_bags_processed = 0;
  int num_bags_success = 0;
  int num_bags_failure = 0;

  // Loop through each flight
  for (int i = 0; i < 10; i++) {
    printf("Processing flight %d with %d bags\n", flights[i].flight_num, flights[i].num_bags);
    
    // Loop through each bag
    for (int j = 0; j < MAX_BAGS; j++) {
      if (num_bags_processed == flights[i].num_bags) {
        break; // All bags for this flight processed
      }

      // Check if the bag belongs to the current flight
      if (bags[j].flight_num == flights[i].flight_num) {
        printf("Processing bag %d for flight %d\n", bags[j].bag_id, bags[j].flight_num);
        
        // Randomly assign success or failure
        int success = rand() % 2;
        if (success) {
          printf("Bag %d successfully loaded for flight %d\n", bags[j].bag_id, bags[j].flight_num);
          num_bags_success++;
        } else {
          printf("Bag %d failed to load for flight %d\n", bags[j].bag_id, bags[j].flight_num);
          num_bags_failure++;
        }

        num_bags_processed++;
      }
    }
  }

  printf("Baggage handling simulation complete.\n");
  printf("Number of bags successfully loaded: %d\n", num_bags_success);
  printf("Number of bags failed to load: %d\n", num_bags_failure);

  return 0;
}