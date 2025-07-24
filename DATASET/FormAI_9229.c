//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
  int north_south = GREEN, east_west = RED;
  
  srand(time(NULL)); // Seed random number generator
  
  while (1) {
    // Simulate traffic flow with random numbers
    int ns_cars = rand() % 100;
    int ew_cars = rand() % 100;
    
    // Calculate the average traffic flow
    int avg = (ns_cars + ew_cars) / 2;
    
    // Adjust timing based on traffic flow
    if (avg > 80) {
      north_south = GREEN;
      east_west = RED;
    } else if (avg > 60) {
      north_south = YELLOW;
      east_west = RED;
    } else if (avg > 40) {
      north_south = YELLOW;
      east_west = YELLOW;
    } else {
      north_south = RED;
      east_west = GREEN;
    }
    
    // Print current state of traffic lights
    printf("North/South: ");
    if (north_south == RED) {
      printf("RED  ");
    } else if (north_south == YELLOW) {
      printf("YELLOW");
    } else {
      printf("GREEN");
    }
    
    printf("\tEast/West: ");
    if (east_west == RED) {
      printf("RED  ");
    } else if (east_west == YELLOW) {
      printf("YELLOW");
    } else {
      printf("GREEN");
    }
    
    printf("\tNorth/South Flow: %d cars/min\tEast/West Flow: %d cars/min\n", ns_cars, ew_cars);
    
    // Delay for 1 second before updating the lights
    sleep(1);
  }
  
  return 0;
}