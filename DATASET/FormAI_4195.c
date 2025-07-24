//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_BAGGAGE 10
#define MAX_FLIGHTS 5

// Function prototypes
void initializeBaggage(int baggage[][3]);
void initializeFlights(int flights[][2]);
void simulateBaggageHandling(int baggage[][3], int flights[][2]);

int main()
{
  // Seed random number generator
  srand(time(NULL));

  // Initialize arrays for baggage and flights
  int baggage[MAX_BAGGAGE][3];
  int flights[MAX_FLIGHTS][2];

  initializeBaggage(baggage);
  initializeFlights(flights);

  simulateBaggageHandling(baggage, flights);

  return 0;
}

void initializeBaggage(int baggage[][3])
{
  // Initialize baggage array with random values
  for (int i = 0; i < MAX_BAGGAGE; i++)
  {
    baggage[i][0] = i + 1; // Baggage ID
    baggage[i][1] = rand() % 501; // Weight (up to 500 kg)
    baggage[i][2] = rand() % MAX_FLIGHTS; // Flight ID (up to 4)
  }
}

void initializeFlights(int flights[][2])
{
  // Initialize flights array with random values
  for (int i = 0; i < MAX_FLIGHTS; i++)
  {
    flights[i][0] = i + 1; // Flight ID
    flights[i][1] = rand() % 10; // Number of baggage (up to 9)
  }
}

void simulateBaggageHandling(int baggage[][3], int flights[][2])
{
  int completed_baggage = 0;
  bool flights_complete = false;

  // Loop until all baggage is processed for all flights
  while (!flights_complete)
  {
    // Loop through all flights
    for (int i = 0; i < MAX_FLIGHTS; i++)
    {
      // Loop through all baggage for this flight
      for (int j = 0; j < flights[i][1]; j++)
      {
        // Check if baggage for this flight is already processed
        if (baggage[completed_baggage][2] == i)
        {
          printf("Baggage with ID %d for flight %d is already processed.\n", baggage[completed_baggage][0], i+1);
          completed_baggage++; // Move to next baggage
        }
        else // Handle baggage for this flight
        {
          printf("Handling baggage with ID %d for flight %d.\n", baggage[completed_baggage][0], i+1);
          completed_baggage++; // Move to next baggage

          // Check if all baggage for this flight is processed
          if (j+1 == flights[i][1])
          {
            printf("All baggage for flight %d has been processed.\n", i+1);
          }
        }
      }
    }

    // Check if all baggage is processed for all flights
    if (completed_baggage == MAX_BAGGAGE)
    {
      printf("All baggage has been processed for all flights.\n");
      flights_complete = true;
    }
  }
}