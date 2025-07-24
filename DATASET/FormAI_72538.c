//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_TERMINALS 3

// Defines the structure of a baggage
typedef struct {
    int id;  // Unique identifier for the baggage
    int weight;  // Weight of the baggage in kg
    int terminal;  // Terminal number
    int flight;  // Flight number
} Baggage;

int main() {
    srand(time(NULL));  // Initialize random seed

    Baggage baggage[MAX_BAGS];
    int num_bags = 0;
    int flights[MAX_FLIGHTS];
    int num_flights = 0;
    int terminals[MAX_TERMINALS];
    int num_terminals = 0;

    // Populate flights and terminals arrays with random values
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = rand() % 1000;
        num_flights += 1;
    }

    for (int i = 0; i < MAX_TERMINALS; i++) {
        terminals[i] = i + 1;
        num_terminals += 1;
    }

    // Generate initial baggage
    for (int i = 0; i < 20; i++) {
        Baggage new_baggage;
        new_baggage.id = i;
        new_baggage.weight = rand() % 50 + 1;
        new_baggage.terminal = terminals[rand() % num_terminals];
        new_baggage.flight = flights[rand() % num_flights];
        baggage[num_bags] = new_baggage;
        num_bags += 1;
    }

    // Display initial baggage
    printf("Initial Baggage:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("Baggage ID: %d, Flight Number: %d, Terminal: %d, Weight: %dkg\n",
            baggage[i].id, baggage[i].flight, baggage[i].terminal, baggage[i].weight);
    }

    // Sort baggage by terminal and flight number
    for (int i = 0; i < num_bags; i++) {
        for (int j = i + 1; j < num_bags; j++) {
            if (baggage[j].terminal < baggage[i].terminal) {
                Baggage temp = baggage[i];
                baggage[i] = baggage[j];
                baggage[j] = temp;
            }
            else if (baggage[j].terminal == baggage[i].terminal && baggage[j].flight < baggage[i].flight) {
                Baggage temp = baggage[i];
                baggage[i] = baggage[j];
                baggage[j] = temp;
            }
        }
    }

    // Display sorted baggage
    printf("\nSorted Baggage:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("Baggage ID: %d, Flight Number: %d, Terminal: %d, Weight: %dkg\n",
            baggage[i].id, baggage[i].flight, baggage[i].terminal, baggage[i].weight);
    }

    return 0;
}