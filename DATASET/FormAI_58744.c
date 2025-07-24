//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

typedef struct {
    int flight_number;
    int baggage_count;
} Flight;

typedef struct {
    int bag_id;
    int flight_number;
} Bag;

int generate_random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));

    Flight flights[MAX_FLIGHTS];
    Bag bags[MAX_BAGS];
    int num_flights = generate_random_int(1, MAX_FLIGHTS);
    int num_bags = 0;

    printf("Simulating baggage handling for %d flights...\n\n", num_flights);

    for (int i = 0; i < num_flights; i++) {
        Flight flight = {i+1, generate_random_int(1, 50)};
        flights[i] = flight;
        printf("Flight %d has %d bags\n", flight.flight_number, flight.baggage_count);

        for (int j = 0; j < flight.baggage_count; j++) {
            Bag bag = {num_bags+1, flight.flight_number};
            bags[num_bags] = bag;
            num_bags++;
        }
    }

    printf("\nTotal number of bags: %d\n", num_bags);

    printf("\nSorting bags by flight...\n");
    for (int i = 0; i < num_flights; i++) {
        printf("\nFlight %d:\n", flights[i].flight_number);
        for (int j = 0; j < num_bags; j++) {
            if (bags[j].flight_number == flights[i].flight_number) {
                printf("Bag %d\n", bags[j].bag_id);
            }
        }
    }

    printf("\nSimulating loading...\n");

    for (int i = 0; i < num_flights; i++) {
        printf("\nLoading bags for flight %d...\n", flights[i].flight_number);
        for (int j = 0; j < num_bags; j++) {
            if (bags[j].flight_number == flights[i].flight_number) {
                printf("Loading bag %d...\n", bags[j].bag_id);
            }
        }
        printf("All bags for flight %d loaded successfully!\n", flights[i].flight_number);
    }

    printf("\nBaggage handling complete!\n");

    return 0;
}