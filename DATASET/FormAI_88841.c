//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 200
#define MAX_FLIGHTS 10

typedef struct {
    int flight_number;
    int baggage_count;
} Flight;

typedef struct {
    int id;
    int weight;
    int destination_flight;
} Baggage;

int main() {
    srand(time(NULL));
    
    Flight flights[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flight_number = i + 1;
        flights[i].baggage_count = rand() % MAX_BAGGAGE + 1;
    }
    
    Baggage baggage[MAX_BAGGAGE];
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i].id = i + 1;
        baggage[i].weight = rand() % 100 + 1;
        baggage[i].destination_flight = rand() % MAX_FLIGHTS + 1;
    }
    
    printf("Initial stats:\n\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d has %d baggage(s) to be handled\n", flights[i].flight_number, flights[i].baggage_count);
    }
    
    printf("\nPress enter to start the baggage handling simulation.\n");
    getchar();
    
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        int handled_baggage = 0;
        printf("Handling baggage for flight %d...\n", flights[i].flight_number);
        while (handled_baggage < flights[i].baggage_count) {
            for (int j = 0; j < MAX_BAGGAGE; j++) {
                if (baggage[j].destination_flight == flights[i].flight_number) {
                    printf("Handling baggage %d (weight: %d) for flight %d\n", baggage[j].id, baggage[j].weight, flights[i].flight_number);
                    handled_baggage++;
                    baggage[j].destination_flight = -1; // set the destination flight to an invalid value to indicate that it has been handled
                    if (handled_baggage == flights[i].baggage_count) {
                        break;
                    }
                }
            }
        }
        printf("All baggage for flight %d have been handled successfully.\n\n", flights[i].flight_number);
    }
    
    printf("Baggage handling simulation completed.\n");
    return 0;
}