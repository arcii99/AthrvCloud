//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAPACITY 100 // maximum capacity of the conveyor belt

int main() {
  int current_capacity = 0; // current capacity of the conveyor belt
  int arrival_time = 0; // time at which the next bag arrives
  int departure_time = 0; // time at which the next bag needs to be unloaded
  
  srand(time(NULL)); // initialize the random number generator
  
  while (1) {
    if (current_capacity >= MAX_CAPACITY) {
      printf("Conveyor belt is full. Waiting for bags to be unloaded.\n");
      sleep(1); // wait for 1 second
      continue; // move to the next iteration of the loop
    }
    
    if (arrival_time <= departure_time) {
      printf("Bag arrived at time %d.\n", arrival_time);
      current_capacity++;
      arrival_time += rand() % 5 + 1; // generate a random arrival time between 1 and 5 seconds
    } else {
      printf("Bag unloaded at time %d.\n", departure_time);
      current_capacity--;
      departure_time += rand() % 10 + 1; // generate a random unloading time between 1 and 10 seconds
    }
  }
  
  return 0;
}