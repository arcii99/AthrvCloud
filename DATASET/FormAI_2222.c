//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE_WEIGHT 50
#define MAX_BAGGAGE_VOLUME 100
#define MAX_CONVEYOR_BELT_SIZE 10
#define MAX_FLIGHTS 5

struct Baggage {
    int flightNumber;
    int weight;
    int volume;
};

struct ConveyorBelt {
    struct Baggage baggage[MAX_CONVEYOR_BELT_SIZE];
    int size;
};

struct Flight {
    int number;
    int maxBaggageWeight;
    int maxBaggageVolume;
    int remainingWeight;
    int remainingVolume;
    struct ConveyorBelt conveyorBelt;
};

void printBaggage(struct Baggage baggage) {
    printf("Flight Number: %d, Weight: %d, Volume: %d\n", baggage.flightNumber, baggage.weight, baggage.volume);
}

void printConveyorBelt(struct ConveyorBelt conveyorBelt) {
    printf("Conveyor Belt Size: %d\n", conveyorBelt.size);
    for (int i = 0; i < conveyorBelt.size; i++) {
        printBaggage(conveyorBelt.baggage[i]);
    }
}

void printFlight(struct Flight flight) {
    printf("Flight Number: %d\n", flight.number);
    printf("Max Baggage Weight: %d, Max Baggage Volume: %d\n", flight.maxBaggageWeight, flight.maxBaggageVolume);
    printf("Remaining Weight: %d, Remaining Volume: %d\n", flight.remainingWeight, flight.remainingVolume);
    printConveyorBelt(flight.conveyorBelt);
}

int getFlightIndex(struct Flight flights[], int flightNumber, int numFlights) {
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].number == flightNumber) {
            return i;
        }
    }
    return -1;
}

void addToConveyorBelt(struct ConveyorBelt* conveyorBelt, struct Baggage baggage) {
    if (conveyorBelt->size < MAX_CONVEYOR_BELT_SIZE) {
        conveyorBelt->baggage[conveyorBelt->size] = baggage;
        conveyorBelt->size += 1;
        printf("Baggage added to conveyor belt.\n");
    } else {
        printf("Conveyor belt is full. Cannot add baggage.\n");
    }
}

void removeFromConveyorBelt(struct ConveyorBelt* conveyorBelt, int index) {
    if (index >= 0 && index < conveyorBelt->size) {
        for (int i = index; i < conveyorBelt->size - 1; i++) {
            conveyorBelt->baggage[i] = conveyorBelt->baggage[i+1];
        }
        conveyorBelt->size -= 1;
        printf("Baggage removed from conveyor belt.\n");
    } else {
        printf("Invalid index. Cannot remove baggage from conveyor belt.\n");
    }
}

void handleBaggage(struct Flight* flight, struct Baggage baggage) {
    if (baggage.weight <= flight->remainingWeight && baggage.volume <= flight->remainingVolume) {
        flight->remainingWeight -= baggage.weight;
        flight->remainingVolume -= baggage.volume;
        printf("Baggage added to flight %d.\n", flight->number);
    } else {
        addToConveyorBelt(&(flight->conveyorBelt), baggage);
    }
}

void transferBaggage(struct Flight* flight) {
    for (int i = 0; i < flight->conveyorBelt.size; i++) {
        handleBaggage(flight, flight->conveyorBelt.baggage[i]);
        removeFromConveyorBelt(&(flight->conveyorBelt), i);
        i -= 1;
    }
}

void randomizeBaggage(struct Flight flights[], int numFlights) {
    struct Baggage baggage;
    int flightIndex;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        baggage.flightNumber = rand() % numFlights + 1;
        flightIndex = getFlightIndex(flights, baggage.flightNumber, numFlights);
        baggage.weight = rand() % MAX_BAGGAGE_WEIGHT + 1;
        baggage.volume = rand() % MAX_BAGGAGE_VOLUME + 1;
        handleBaggage(&(flights[flightIndex]), baggage);
    }
}

int main() {
    struct Flight flights[MAX_FLIGHTS] = {
        {1, 500, 1000, 500, 1000, { .size = 0 }},
        {2, 600, 1200, 600, 1200, { .size = 0 }},
        {3, 700, 1400, 700, 1400, { .size = 0 }},
        {4, 800, 1600, 800, 1600, { .size = 0 }},
        {5, 900, 1800, 900, 1800, { .size = 0 }}
    };
    randomizeBaggage(flights, MAX_FLIGHTS);
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        transferBaggage(&(flights[i]));
        printFlight(flights[i]);
    }
    return 0;
}