//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define FLIGHTS_NUM 3
#define BAGS_NUM 10

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void move_baggage(int flight_idx, int baggage_idx, int final_destination) {
    if(flight_idx == final_destination) {
        printf("Baggage %d arrived to its final destination %d successfully!\n", baggage_idx, final_destination);
        return;
    }

    int next_flight_idx = get_random_number(0, FLIGHTS_NUM - 1);
    printf("Baggage %d is on flight %d from flight %d to flight %d.\n", baggage_idx, next_flight_idx, flight_idx, next_flight_idx);

    move_baggage(next_flight_idx, baggage_idx, final_destination);
}

int main() {
    int baggage[MAX_BAGGAGE] = {0};
    srand(time(NULL));

    printf("Generating %d baggage...\n", MAX_BAGGAGE);
    for(int i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i] = i;
    }

    printf("Simulating baggage transportation...\n");
    for(int i = 0; i < BAGS_NUM; i++) {
        int baggage_idx = get_random_number(0, MAX_BAGGAGE - 1);
        int final_destination = get_random_number(0, FLIGHTS_NUM - 1);

        printf("Moving baggage %d from flight 0 to final destination %d...\n", baggage[baggage_idx], final_destination);
        move_baggage(0, baggage[baggage_idx], final_destination);
        printf("\n");
    }

    printf("All baggage have arrived at their destinations.\n");
    return 0;
}