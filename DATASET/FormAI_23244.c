//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10

typedef struct {
    int id;
    int weight;
    int flight_num;
} Baggage;

typedef struct {
    int id;
    int num_bags;
    Baggage bags[MAX_BAGGAGE];
} Flight;

typedef struct {
    int num_flights;
    Flight flights[MAX_FLIGHTS];
} Airport;

void add_baggage(Airport *airport, int flight_num, int weight) {
    if (airport->num_flights < MAX_FLIGHTS) {
        Flight *flight = &airport->flights[flight_num];
        if (flight->num_bags < MAX_BAGGAGE) {
            Baggage *bag = &flight->bags[flight->num_bags];
            bag->id = flight_num * 1000 + flight->num_bags;
            bag->weight = weight;
            bag->flight_num = flight_num;
            flight->num_bags++;
        } else {
            printf("Flight %d has too many bags\n", flight_num);
        }
    } else {
        printf("Max number of flights reached\n");
    }
}

void print_airport(Airport *airport) {
    printf("Airport\n");
    printf("-------\n");
    for (int i = 0; i < airport->num_flights; i++) {
        Flight *flight = &airport->flights[i];
        printf("Flight %d (%d bags):\n", flight->id, flight->num_bags);
        for (int j = 0; j < flight->num_bags; j++) {
            Baggage *bag = &flight->bags[j];
            printf("Baggage %d (weight: %d)\n", bag->id, bag->weight);
        }
    }
}

int main() {
    Airport airport = {0};
    add_baggage(&airport, 0, 20);
    add_baggage(&airport, 0, 30);
    add_baggage(&airport, 1, 15);
    print_airport(&airport);
    return 0;
}