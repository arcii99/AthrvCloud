//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_LUGGAGE 5
#define MAX_FLIGHTS 3
#define MAX_DEPARTURE_TIME 24

static int luggage_count[MAX_PASSENGERS];

int main()
{
    int passengers[MAX_PASSENGERS];
    int flights[MAX_FLIGHTS] = {123, 456, 789};
    int departure_times[MAX_FLIGHTS] = {10, 14, 18};
    int current_time = 8;
    int i, j, k;

    srand(time(NULL));

    // Initialize passengers with random luggage count
    for (i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i] = i + 1;
        luggage_count[i] = rand() % MAX_LUGGAGE + 1;
    }

    // Simulate baggage handling for each flight
    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d to depart at %d:00\n", flights[i], departure_times[i]);

        // Wait until departure time for the flight
        while (current_time < departure_times[i]) {
            printf("Current time is %d:00\n", current_time);
            current_time++;
        }

        // Handle baggage for each passenger
        for (j = 0; j < MAX_PASSENGERS; j++) {
            if (rand() % 2) {
                printf("Passenger %d has missed the flight.\n", passengers[j]);
                continue;
            }

            printf("Handling baggage for passenger %d with %d pieces of luggage.\n", passengers[j], luggage_count[j]);

            // Simulate checking in each piece of luggage
            for (k = 0; k < luggage_count[j]; k++) {
                printf("Checking in luggage piece %d for passenger %d.\n", k + 1, passengers[j]);
            }
        }

        printf("All baggage has been handled for flight %d.\n", flights[i]);
    }

    return 0;
}