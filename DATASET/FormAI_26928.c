//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int weight;
    int arrival_time;
    int processing_time;
} baggage;

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    srand(time(NULL));
    int num_bags = rand() % 10 + 1;
    int total_weight = 0;
    baggage bag[num_bags];

    printf("Total number of bags: %d\n", num_bags);

    for (int i = 0; i < num_bags; i++) {
        bag[i].id = i + 1;
        bag[i].weight = rand() % 50 + 1;
        bag[i].arrival_time = rand() % 5 + 1;
        bag[i].processing_time = rand() % 5 + 1;

        printf("Bag ID: %d, Weight: %d kg, Arrival Time: %d sec, Processing Time: %d sec\n", bag[i].id, bag[i].weight, bag[i].arrival_time, bag[i].processing_time);

        total_weight += bag[i].weight;
        delay(bag[i].arrival_time);
        printf("Bag ID: %d has arrived at the baggage claim area.\n", bag[i].id);

        delay(bag[i].processing_time);
        printf("Bag ID: %d has been processed and sent to the conveyor belt.\n", bag[i].id);
    }

    printf("Total weight of baggage: %d kg\n", total_weight);

    return 0;
}