//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BAGGAGE 1000
#define MAX_FLIGHTS 20

struct Baggage {
    int id;
    int flight_number;
    int weight;
    bool accepted;
};

struct Flight {
    int number;
    int max_weight;
    int current_weight;
    int baggage_count;
    struct Baggage baggages[MAX_BAGGAGE];
};

int main() {
    struct Flight flights[MAX_FLIGHTS];
    int flight_count = 0;

    // Add some flights
    struct Flight flight1 = { 1, 10000, 0, 0 };
    struct Flight flight2 = { 2, 5000, 0, 0 };
    flights[flight_count++] = flight1;
    flights[flight_count++] = flight2;

    // Add some baggage
    struct Baggage baggage1 = { 1, 1, 20, false };
    struct Baggage baggage2 = { 2, 1, 30, false };
    struct Baggage baggage3 = { 3, 1, 40, false };
    flights[0].baggages[flights[0].baggage_count++] = baggage1;
    flights[0].baggages[flights[0].baggage_count++] = baggage2;
    flights[0].baggages[flights[0].baggage_count++] = baggage3;

    // Simulate baggage handling
    for (int i = 0; i < flight_count; i++) {
        struct Flight flight = flights[i];
        for (int j = 0; j < flight.baggage_count; j++) {
            struct Baggage baggage = flight.baggages[j];
            if (baggage.weight <= flight.max_weight - flight.current_weight) {
                flights[i].current_weight += baggage.weight;
                flights[i].baggages[j].accepted = true;
            }
        }
    }

    // Print accepted baggage
    for (int i = 0; i < flight_count; i++) {
        struct Flight flight = flights[i];
        printf("Flight %d: \n", flight.number);
        for (int j = 0; j < flight.baggage_count; j++) {
            struct Baggage baggage = flight.baggages[j];
            if (baggage.accepted) {
                printf("Baggage %d (weight: %d) accepted\n", baggage.id, baggage.weight);
            }
        }
        printf("\n");
    }

    return 0;
}