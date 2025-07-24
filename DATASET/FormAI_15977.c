//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum number of bags that the airport can handle at one time */
#define MAX_BAGS 50

/* Define the maximum time that a bag can take to move from one checkpoint to the next */
#define MAX_TIME 10

/* Define the minimum time that a bag can take to move from one checkpoint to the next */
#define MIN_TIME 1

/* Define the number of bag checkpoints at the airport */
#define NUM_CHECKPOINTS 4

/* Define a structure to represent a single bag */
typedef struct {
   int id; // baggage identification number
   int curr_location; // current bag location
} Bag;

/* Define a function to generate a random integer between the given range */
int rand_int(int lower, int upper) {
   return (rand() % (upper - lower + 1)) + lower;
}

int main() {

   srand(time(NULL)); // seed RNG with current time
   int num_bags = rand_int(0, MAX_BAGS); // generate random number of bags
   Bag bags[num_bags]; // create an array of bags
   int bag_locations[num_bags]; // array to hold current location of each bag
   
   // Initialize each Bag structure and randomly assign a starting location
   for (int i=0; i<num_bags; i++) {
      bags[i].id = i+1; // assign unique id
      bags[i].curr_location = rand_int(1, NUM_CHECKPOINTS); // assign random starting location
      bag_locations[i] = bags[i].curr_location; // add starting location to array
   }
   
   // Print the initial locations of all bags
   printf("Initial Bag Locations:\n");
   for (int i=0; i<num_bags; i++) {
      printf("Bag #%d:\tCheckpoint %d\n", bags[i].id, bags[i].curr_location);
   }
   printf("\n");
   
   // Simulate movement of bags between checkpoints
   for (int i=0; i<NUM_CHECKPOINTS-1; i++) {
      // Print current location of all bags
      printf("Bags at Checkpoint %d:\n", i+1);
      for (int j=0; j<num_bags; j++) {
         if (bags[j].curr_location == i+1) {
            printf("Bag #%d\n", bags[j].id);
            bag_locations[j] = rand_int(i+2, NUM_CHECKPOINTS); // assign new random location between current checkpoint and final checkpoint
         }
      }
      printf("\n");
      // Wait for bags to move to next checkpoint
      int wait_time = rand_int(MIN_TIME, MAX_TIME);
      printf("Waiting for bags to move to Checkpoint %d...\n\n", i+2);
      printf("Time taken: %d second(s)\n", wait_time);
      printf("\n");
      for (int j=0; j<num_bags; j++) {
         if (bag_locations[j] == i+2) {
            bags[j].curr_location = i+2; // move bag to next checkpoint
         }
      }
   }
   
   // Print final location of all bags
   printf("Final Bag Locations:\n");
   for (int i=0; i<num_bags; i++) {
      printf("Bag #%d:\tCheckpoint %d\n", bags[i].id, bags[i].curr_location);
   }
   printf("\n");

   return 0;
}