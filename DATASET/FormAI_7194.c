//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_PASS 10

int flights = 0;

struct Baggage {
  int weight;
  int flight;
} bags[MAX_BAGS];

struct Passenger {
  int flight;
  int num_bags;
  struct Baggage *bags;
} passengers[MAX_PASS];

void generateFlights() {
  srand(time(NULL));
  flights = rand() % 5 + 1;  // Random number of flights from 1 to 5
  printf("Flights today: %d\n", flights);
}

void generateBags() {
  int bags_per_flight = MAX_BAGS / flights;
  printf("Bags per flight: %d\n", bags_per_flight);
  
  int i, j;
  for (i = 0; i < flights; i++) {
    for (j = 0; j < bags_per_flight; j++) {
      bags[i * bags_per_flight + j].weight = rand() % 30 + 1;  // Random bag weight from 1 to 30
      bags[i * bags_per_flight + j].flight = i + 1;  // Assign bag to corresponding flight
    }
  }
}

void generatePassengers() {
  int i, j;
  for (i = 0; i < MAX_PASS; i++) {
    passengers[i].flight = rand() % flights + 1;  // Assign passenger to random flight
    passengers[i].num_bags = rand() % 3 + 1;  // Random number of bags from 1 to 3
    passengers[i].bags = (struct Baggage *) malloc(sizeof(struct Baggage) * passengers[i].num_bags);
    for (j = 0; j < passengers[i].num_bags; j++) {
      int k = rand() % MAX_BAGS;
      while (bags[k].flight != passengers[i].flight) {  // Make sure bag is in correct flight
        k = rand() % MAX_BAGS;
      }
      passengers[i].bags[j] = bags[k];  // Assign bag to passenger
    }
  }
}

void displayBags() {
  int i;
  printf("\nBags:\n");
  for (i = 0; i < MAX_BAGS; i++) {
    printf("Bag %d - Flight %d - Weight %d\n", i+1, bags[i].flight, bags[i].weight);
  }
}

void displayPassengers() {
  int i, j;
  printf("\nPassengers:\n");
  for (i = 0; i < MAX_PASS; i++) {
    printf("Passenger %d - Flight %d - Number of bags %d\n", i+1, passengers[i].flight, passengers[i].num_bags);
    printf("Bags:");
    for (j = 0; j < passengers[i].num_bags; j++) {
      printf(" %d", passengers[i].bags[j].weight);
    }
    printf("\n\n");
  }
}

int main() {
  generateFlights();
  generateBags();
  generatePassengers();
  displayBags();
  displayPassengers();
  return 0;
}