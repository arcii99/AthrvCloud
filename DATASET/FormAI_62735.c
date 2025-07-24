//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_FLIGHTS 25

typedef struct {
    int id;
    int weight;
} Bag;

typedef struct {
    int flight_number;
    int num_bags;
    Bag bags[MAX_BAGS];
} Flight;

Flight flights[MAX_FLIGHTS];
int num_flights = 0;
int num_bags_not_loaded = 0;

void load_bags(Flight* flight) {
    int i, sum = 0;
    for (i = 0; i < flight->num_bags; i++) {
        sum += flight->bags[i].weight;
    }
    printf("Loading bags for flight %d, total weight: %d\n", flight->flight_number, sum);
}

void print_summary() {
    printf("Number of bags not loaded: %d\n",num_bags_not_loaded);
}

int main() {
    srand((unsigned int) time(NULL));
    int i, j, num_bags;
    bool should_load = true;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        num_bags = rand() % MAX_BAGS;
        flights[i].flight_number = i + 1;
        flights[i].num_bags = num_bags;
        for (j = 0; j < num_bags; j++) {
            flights[i].bags[j].id = j + 1;
            flights[i].bags[j].weight = rand() % 50;
        }
        if (should_load) {
            load_bags(&flights[i]);
            should_load = false;
        } else {
            num_bags_not_loaded += num_bags;
            printf("Flight %d baggage not loaded due to lack of capacity.\n",flights[i].flight_number);
        }
        if (num_bags_not_loaded > MAX_BAGS) {
            printf("Too many bags not loaded, terminating simulation.\n");
            break;
        }
    }
    print_summary();
    return 0;
}