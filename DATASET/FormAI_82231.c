//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10
#define MAX_PASSENGERS 200

int main() {

    // Initializing simulation data
    int baggage[MAX_BAGGAGE];
    int flights[MAX_FLIGHTS];
    int passengers[MAX_PASSENGERS];
    time_t t;
    srand((unsigned) time(&t));

    // Generating random data for baggage, flights, and passengers
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i] = rand() % 50 + 1;
    }
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = i + 1;
    }
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i] = i + 1;
    }

    // Simulating baggage handling
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d has arrived at the airport.\n", flights[i]);
        for (int j = 0; j < MAX_PASSENGERS; j++) {
            printf("Passenger %d has checked in.\n", passengers[j]);
            int total_baggage = 0;
            for (int k = 0; k < MAX_BAGGAGE; k++) {
                int baggage_weight = baggage[k];
                total_baggage += baggage_weight;
                printf("Passenger %d's baggage %d (weighing %d kg) is being loaded onto the plane.\n",
                       passengers[j], k + 1, baggage_weight);
            }
            printf("Total baggage for Passenger %d weighing %d kg has been loaded onto the plane.\n",
                   passengers[j], total_baggage);
        }
        printf("All passengers for Flight %d have checked in and their baggage has been loaded onto the plane.\n",
               flights[i]);
        printf("Flight %d is ready for takeoff.\n", flights[i]);
    }

    return 0;
}