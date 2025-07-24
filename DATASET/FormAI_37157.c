//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_GATES 10

typedef struct {
    int id;
    int weight;
} Baggage;

typedef struct {
    int gateNum;
    bool isBusy;
    Baggage baggage[MAX_BAGGAGE];
    int numBaggage;
} Gate;

typedef struct {
    int id;
    Baggage baggage[MAX_BAGGAGE];
    int numBaggage;
} Flight;

int getRandomWeight() {
    //Returns a random baggage weight between 1 and 100kg
    srand(time(NULL));
    return (1 + rand() % 100);
}

void addBaggageToFlight(Baggage baggage, Flight *flight) {
    flight->baggage[flight->numBaggage] = baggage;
    flight->numBaggage++;
}

void processGateBags(Gate *gate, Flight *flight) {
    //Empties all the baggages at the gate to the flight
    int i;
    for (i = 0; i < gate->numBaggage; i++) {
        Baggage currBaggage = gate->baggage[i];
        addBaggageToFlight(currBaggage, flight);
    }
    gate->numBaggage = 0;
}

void simulateFlight(Gate gates[MAX_GATES], Flight *flight) {
    int i, j, freeGates = 0;
    while (true) {
        freeGates = 0;
        //Find the number of free gates
        for (i = 0; i < MAX_GATES; i++) {
            if (!gates[i].isBusy) {
                freeGates++;
            }
        }
        //If there are no free gates, wait for some time
        if (freeGates == 0) {
            printf("All gates busy. Waiting for some gates to be free...\n");
            sleep(10);
        } else {
            //Randomly select a gate to process the bags
            for (i = 0; i < MAX_GATES; i++) {
                if (!gates[i].isBusy) {
                    printf("Gate %d is now processing bags...\n", gates[i].gateNum);
                    for (j = 0; j < MAX_BAGGAGE; j++) {
                        Baggage newBaggage;
                        newBaggage.id = j + 1;
                        newBaggage.weight = getRandomWeight();
                        gates[i].baggage[j] = newBaggage;
                        gates[i].numBaggage++;
                        if (gates[i].numBaggage == flight->numBaggage) {
                            break;
                        }
                    }
                    gates[i].isBusy = true;
                    printf("Gate %d has finished processing bags.\n", gates[i].gateNum);
                    processGateBags(&gates[i], flight);
                    gates[i].isBusy = false;
                    printf("Gate %d is now free.\n", gates[i].gateNum);
                    break;
                }
            }
            if (i == MAX_GATES) {
                printf("All gates busy. Waiting for some gates to be free...\n");
                sleep(10);
            }
        }
        //If all the bags are processed, end the simulation
        if (flight->numBaggage == MAX_BAGGAGE) {
            break;
        }
    }
    printf("All bags have been processed!");
}

int main() {
    //Initialize all the gates and the flight
    int i;
    Gate gates[MAX_GATES];
    for (i = 0; i < MAX_GATES; i++) {
        Gate newGate;
        newGate.gateNum = i + 1;
        newGate.isBusy = false;
        newGate.numBaggage = 0;
        gates[i] = newGate;
    }
    Flight flight;
    flight.id = 1;
    flight.numBaggage = 0;
    //Start simulating the flight
    simulateFlight(gates, &flight);
    return 0;
}