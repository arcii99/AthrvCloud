//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 10 // maximum number of bags per flight
#define MAX_FLIGHTS 5 // maximum number of flights per hour

// structure to represent a single bag
typedef struct {
    int id;
    int destination;
} Bag;

// structure to represent a single flight
typedef struct {
    int id;
    Bag baggage[MAX_BAGGAGE];
    int num_bags;
} Flight;

// function to initialize a bag
Bag create_bag(int id, int dest) {
    Bag b;
    b.id = id;
    b.destination = dest;
    return b;
}

// function to randomly assign a destination to a bag
int get_random_destination() {
    return rand() % 3 + 1;
}

int main() {
    srand(time(NULL));
    
    // create an array of flights
    Flight flights[MAX_FLIGHTS];
    
    // initialize each flight's bags with random destinations
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].id = i;
        flights[i].num_bags = rand() % MAX_BAGGAGE + 1;
        for (int j = 0; j < flights[i].num_bags; j++) {
            flights[i].baggage[j] = create_bag(j, get_random_destination());
        }
    }
    
    // simulate baggage handling process
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Processing bags for Flight %d...\n", flights[i].id);
        for (int j = 0; j < flights[i].num_bags; j++) {
            Bag b = flights[i].baggage[j];
            printf("    Bag %d is being transferred to Destination %d...\n", b.id, b.destination);
            // simulate time taken for bag to reach destination
            int time_to_arrive = rand() % 5 + 1;
            printf("    Bag %d arrived at Destination %d in %d seconds.\n", b.id, b.destination, time_to_arrive);
        }
        printf("All bags for Flight %d have been processed.\n", flights[i].id);
    }
    
    return 0;
}