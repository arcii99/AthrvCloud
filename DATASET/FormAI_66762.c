//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAG_WEIGHT 50
#define MAX_BAGS_PER_FLIGHT 20
#define MAX_FLIGHTS_PER_DAY 10
#define MAX_CAPACITY_ALLOCATED 5000

typedef struct Baggage_t {
  int airline_id;
  int bag_id;
  float weight;
} Baggage;

typedef struct Flight_t {
  int flight_id;
  int bags_checked_in;
  Baggage* bag_list;
} Flight;

// Helper function to generate random baggage
Baggage* generate_baggage(int airline) {
  Baggage* baggage = malloc(sizeof(Baggage));
  baggage->airline_id = airline;
  baggage->bag_id = rand();
  baggage->weight = (float) (rand() % MAX_BAG_WEIGHT + 1);

  return baggage;
}

// Helper function to generate random flights
Flight* generate_flight(int id) {
  Flight* flight = malloc(sizeof(Flight));
  flight->flight_id = id;
  flight->bags_checked_in = rand() % MAX_BAGS_PER_FLIGHT + 1;

  flight->bag_list = malloc(sizeof(Baggage) * flight->bags_checked_in);
  for (int i = 0; i < flight->bags_checked_in; i++) {
    flight->bag_list[i] = *generate_baggage(id);
  }

  return flight;
}

int main() {
  // Create an array to store flights for the day
  Flight* flight_list[MAX_FLIGHTS_PER_DAY];
  int flights_allocated = 0;

  srand(time(NULL)); // Seed the random number generator with current time

  // Generate random flights and add them to the flight list
  for (int i = 0; i < MAX_FLIGHTS_PER_DAY; i++) {
    flight_list[i] = generate_flight(i+1);
    flights_allocated++;
  }

  // Calculate total baggage weight for the day
  float total_weight = 0;
  for (int i = 0; i < flights_allocated; i++) {
    Flight flight = *flight_list[i];
    for (int j = 0; j < flight.bags_checked_in; j++) {
      Baggage baggage = flight.bag_list[j];
      total_weight += baggage.weight;
    }
  }

  // Check if baggage weight exceeds maximum capacity allocated
  if (total_weight > MAX_CAPACITY_ALLOCATED) {
    printf("WARNING: Baggage weight for the day exceeds maximum capacity allocated!\n");
  } else {
    printf("Baggage weight for the day is within maximum capacity allocated.\n");
  }

  // Free allocated memory
  for (int i = 0; i < flights_allocated; i++) {
    if (flight_list[i]) {
      free(flight_list[i]->bag_list);
      free(flight_list[i]);
    }
  }

  return 0;
}