//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Set up random number generation
  srand(time(NULL));
  
  // Define variables
  int num_bags = rand() % 100 + 1; // Random number of bags between 1-100
  int max_weight = 50; // Maximum weight of each bag (in kg)
  int max_capacity = 100; // Maximum capacity of conveyor belt (in kg)
  int bags_on_belt = 0; // Number of bags currently on the conveyor belt
  int total_weight_on_belt = 0; // Total weight of bags currently on the conveyor belt
  
  // Simulation begins
  printf("Welcome to the Airport Baggage Handling Simulation!\n");
  printf("Today, we have %d bags to handle.\n", num_bags);
  
  // Loop through bags and handle each one
  for (int i = 1; i <= num_bags; i++) {
    int bag_weight = rand() % max_weight + 1; // Random weight for current bag
    
    // Check if current bag can be added to conveyor belt
    if ((total_weight_on_belt + bag_weight) > max_capacity) {
      printf("Conveyor belt full. Waiting for bags to be removed...\n");
      
      // Keep checking until there is space on the conveyor belt
      while ((total_weight_on_belt + bag_weight) > max_capacity) {
        // Remove bags from conveyor belt until there is enough space
        int bags_removed = 0;
        int weight_removed = 0;
        while ((total_weight_on_belt - weight_removed + bag_weight) > max_capacity) {
          // Remove one bag from the conveyor belt
          bags_on_belt--;
          weight_removed += rand() % max_weight + 1;
          printf("Bag removed from conveyor belt. ");
          printf("%d bags currently on conveyor belt. ", bags_on_belt);
          printf("Total weight on conveyor belt: %d kg.\n", total_weight_on_belt - weight_removed);
          bags_removed++;
        }
        printf("%d bags removed from conveyor belt to make space for new bag.\n", bags_removed);
      }
    }
    
    // Add bag to conveyor belt
    bags_on_belt++;
    total_weight_on_belt += bag_weight;
    printf("Bag %d added to conveyor belt. ", i);
    printf("%d bags currently on conveyor belt. ", bags_on_belt);
    printf("Total weight on conveyor belt: %d kg.\n", total_weight_on_belt);
  }
  
  printf("All bags have been handled. Have a nice day!\n");
  
  return 0;
}