//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 5
#define MAX_BELTS 3

typedef struct {
    char flight_no[10];
    int num_bags;
} Flight;

typedef struct {
    char flight_no[10];
    int baggage_id;
} Baggage;

int main() {
    srand(time(NULL));

    // Initialize flights
    Flight flights[MAX_FLIGHTS];
    strcpy(flights[0].flight_no, "AA1234");
    flights[0].num_bags = rand() % MAX_BAGGAGE + 1;
    strcpy(flights[1].flight_no, "UA5678");
    flights[1].num_bags = rand() % MAX_BAGGAGE + 1;
    strcpy(flights[2].flight_no, "DL9012");
    flights[2].num_bags = rand() % MAX_BAGGAGE + 1;
    strcpy(flights[3].flight_no, "BA3456");
    flights[3].num_bags = rand() % MAX_BAGGAGE + 1;
    strcpy(flights[4].flight_no, "AC7890");
    flights[4].num_bags = rand() % MAX_BAGGAGE + 1;

    // Initialize belts
    int belts[MAX_BELTS] = {0};

    // Start simulation
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        for (int j = 0; j < flights[i].num_bags; j++) {
            // Generate baggage
            Baggage bag;
            strcpy(bag.flight_no, flights[i].flight_no);
            bag.baggage_id = rand() % 10000 + 1;

            // Find an available belt
            int belt_idx = -1;
            for (int k = 0; k < MAX_BELTS; k++) {
                if (belts[k] == 0) {
                    belt_idx = k;
                    break;
                }
            }

            // If no available belt, wait until one opens up
            while (belt_idx == -1) {
                for (int k = 0; k < MAX_BELTS; k++) {
                    if (belts[k] == 0) {
                        belt_idx = k;
                        break;
                    }
                }
            }

            // Assign belt and print
            belts[belt_idx] = bag.baggage_id;
            printf("Baggage %d for flight %s assigned to belt %d\n", bag.baggage_id, bag.flight_no, belt_idx+1);

            // Wait for baggage to be processed
            int process_time = rand() % 5 + 1;
            printf("Processing baggage %d for flight %s...\n", bag.baggage_id, bag.flight_no);
            sleep(process_time);

            // Clear belt and print
            belts[belt_idx] = 0;
            printf("Baggage %d for flight %s cleared from belt %d\n", bag.baggage_id, bag.flight_no, belt_idx+1);
        }
    }

    return 0;
}