//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define NUM_OF_FLIGHTS 10
#define NUM_OF_BAGGAGES 50
#define MAX_BAGGAGE_WEIGHT 30
#define MAX_FLIGHT_DELAY 5

// define struct for Flight
typedef struct Flight {
  char* flight_num;
  int arrival_time;
  int departure_time;
} Flight;

// define struct for Baggage
typedef struct Baggage {
  int weight;
  int flight_index;
} Baggage;

int main() {
  // seed rand function with current time
  srand(time(NULL));

  // create array to hold Flight structs
  Flight flights[NUM_OF_FLIGHTS];

  // fill flight details
  printf("FLIGHT DETAILS\n\n");
  for (int i = 0; i < NUM_OF_FLIGHTS; i++) {
    flights[i].flight_num = (char*)malloc(5*sizeof(char));
    sprintf(flights[i].flight_num, "XX%d", i+1);
    flights[i].arrival_time = rand() % 24;
    flights[i].departure_time = flights[i].arrival_time + (rand() % MAX_FLIGHT_DELAY) + 1;
    printf("Flight %s arriving at %d:00 and departing at %d:00\n", flights[i].flight_num, flights[i].arrival_time, flights[i].departure_time);
  }

  // create array to hold Baggage structs
  Baggage baggages[NUM_OF_BAGGAGES];

  // fill baggage details
  for (int i = 0; i < NUM_OF_BAGGAGES; i++) {
    baggages[i].weight = rand() % MAX_BAGGAGE_WEIGHT + 1; 
    baggages[i].flight_index = rand() % NUM_OF_FLIGHTS;
  }

  // simulate baggage handling system
  printf("\n\nBAGGAGE HANDLING SIMULATION\n\n");
  for (int hour = 0; hour < 24; hour++) {
    printf("Time: %d:00\n", hour);

    // check if flight is arriving or departing
    for (int i = 0; i < NUM_OF_FLIGHTS; i++) {
      if (flights[i].arrival_time == hour) {
        printf("Flight %s has arrived.\n", flights[i].flight_num);

        // unload baggage for the arriving flight
        for (int j = 0; j < NUM_OF_BAGGAGES; j++) {
          if (baggages[j].flight_index == i) {
            printf("\tBaggage %d with weight %d kg has been unloaded.\n", j+1, baggages[j].weight);
          }
        }
      }
      else if (flights[i].departure_time == hour) {
        printf("Flight %s is departing.\n", flights[i].flight_num);

        // load baggage for the departing flight
        int total_weight = 0;
        for (int j = 0; j < NUM_OF_BAGGAGES; j++) {
          if (baggages[j].flight_index == i) {
            total_weight += baggages[j].weight;
            printf("\tBaggage %d with weight %d kg has been loaded.\n", j+1, baggages[j].weight);
          }
        }
        printf("\tTotal baggage weight for flight %s: %d kg\n", flights[i].flight_num, total_weight);
      }
    }
  }

  // free allocated memory
  for (int i = 0; i < NUM_OF_FLIGHTS; i++) {
    free(flights[i].flight_num);
  }

  return 0;
}