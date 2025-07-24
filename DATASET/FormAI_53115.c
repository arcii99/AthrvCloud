//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Constants
#define MAX_DESTINATIONS 5
#define MAX_BAGGAGE 100

// Define Structures
typedef struct {
    int destination;
    int weight;
} Baggage;

typedef struct {
    Baggage baggages[MAX_BAGGAGE];
    int count;
} ConveyorBelt;

typedef struct {
    int id;
    int destination;
} Flight;

typedef struct {
    Flight flights[MAX_DESTINATIONS];
    int count;
} FlightScheduler;

// Function Declarations
void loadBaggage(ConveyorBelt *belt, int destination, int weight);
void scheduleFlight(FlightScheduler *scheduler, int id, int destination);
void handleBaggage(ConveyorBelt *belt, FlightScheduler *scheduler);

int main() {
    ConveyorBelt belt = {{}, 0};
    FlightScheduler scheduler = {{}, 0};

    // Load Baggage onto the Belt
    loadBaggage(&belt, 3, 50);
    loadBaggage(&belt, 1, 30);
    loadBaggage(&belt, 5, 20);
    loadBaggage(&belt, 2, 25);

    // Schedule Flights
    scheduleFlight(&scheduler, 1, 2);
    scheduleFlight(&scheduler, 2, 3);
    scheduleFlight(&scheduler, 3, 1);
    scheduleFlight(&scheduler, 4, 5);
    scheduleFlight(&scheduler, 5, 4);

    // Handle Baggage
    handleBaggage(&belt, &scheduler);

    return 0;
}

// Function Definitions
void loadBaggage(ConveyorBelt *belt, int destination, int weight) {
    if (belt->count >= MAX_BAGGAGE) {
        printf("Conveyor Belt Full! Cannot load more baggage.\n");
        return;
    }

    Baggage newBaggage = {destination, weight};
    belt->baggages[belt->count++] = newBaggage;

    printf("Loaded Baggage with weight %d for Destination %d onto Conveyor Belt.\n", weight, destination);
}

void scheduleFlight(FlightScheduler *scheduler, int id, int destination) {
    if (scheduler->count >= MAX_DESTINATIONS) {
        printf("All Flights Scheduled! Cannot schedule more flights.\n");
        return;
    }

    Flight newFlight = {id, destination};
    scheduler->flights[scheduler->count++] = newFlight;

    printf("Scheduled Flight with ID %d for Destination %d.\n", id, destination);
}

void handleBaggage(ConveyorBelt *belt, FlightScheduler *scheduler) {
    for (int i = 0; i < scheduler->count; i++) {
        int destination = scheduler->flights[i].destination;

        printf("\nHandling Baggage for Flight with ID %d to Destination %d...\n", scheduler->flights[i].id, destination);

        for (int j = 0; j < belt->count; j++) {
            Baggage baggage = belt->baggages[j];

            if (baggage.destination == destination) {
                printf("Loading Baggage with weight %d for Destination %d onto Flight with ID %d.\n", baggage.weight, destination, scheduler->flights[i].id);
                belt->count--;
                for (int k = j; k < belt->count; k++) {
                    belt->baggages[k] = belt->baggages[k + 1];
                }
                j--;
            }
        }
    }
}