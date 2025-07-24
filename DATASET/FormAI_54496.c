//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MIN_WEIGHT 10
#define MAX_WEIGHT 50

int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void handle_baggage(int baggage[][MAX_BAGS]) {
    int i, j, total_bags = 0, total_weight = 0;
    for(i = 0; i < MAX_FLIGHTS; i++) {
        int bags_on_flight = 0, weight_on_flight = 0;
        printf("Flight %d:\n", i + 1);
        for(j = 0; j < MAX_BAGS; j++) {
            if(baggage[i][j]) {
                bags_on_flight++;
                weight_on_flight += baggage[i][j];
                baggage[i][j] = 0;
            }
        }
        printf("Bags on flight: %d\n", bags_on_flight);
        printf("Total weight on flight: %d kg\n", weight_on_flight);
        total_bags += bags_on_flight;
        total_weight += weight_on_flight;
    }
    printf("Total bags handled: %d\n", total_bags);
    printf("Total weight handled: %d kg\n", total_weight);
}

int main() {
    int baggage[MAX_FLIGHTS][MAX_BAGS] = {0};
    srand(time(NULL));
    int i, j;
    for(i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d baggage:\n", i + 1);
        for(j = 0; j < MAX_BAGS; j++) {
            int weight = random_number(MIN_WEIGHT, MAX_WEIGHT);
            baggage[i][j] = weight;
            printf("Bag %d: %d kg\n", j + 1, weight);
        }
        printf("\n");
    }
    printf("Handling baggage...\n");
    handle_baggage(baggage);
    return 0;
}