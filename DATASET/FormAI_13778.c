//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct to represent bags
typedef struct {
    int id;
    char* destination;
    bool transferred;
} Bag;

// Function to generate random destination string
char* generateDestination() {
    char* destinations[] = {"New York", "London", "Paris", "Tokyo", "Sydney", "Dubai"};
    int numDestinations = sizeof(destinations)/sizeof(destinations[0]);
    int randomIndex = rand() % numDestinations;
    return destinations[randomIndex];
}

// Function to simulate baggage transfer
void transferBag(Bag* bag) {
    printf("Transferring bag %d to %s\n", bag->id, bag->destination);
    bag->transferred = true;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int numBags = 50;
    int transferTime = 3; // Number of seconds to transfer each bag
    int totalTransferred = 0;

    // Create array of bags
    Bag bags[numBags];
    for (int i = 0; i < numBags; i++) {
        bags[i].id = i + 1;
        bags[i].destination = generateDestination();
        bags[i].transferred = false;
    }

    // Simulate baggage transfer
    printf("Starting baggage transfer simulation...\n");
    while (totalTransferred < numBags) {
        for (int i = 0; i < numBags; i++) {
            if (!bags[i].transferred) {
                transferBag(&bags[i]);
                totalTransferred++;
                if (totalTransferred == numBags) {
                    break;
                }
                sleep(transferTime);
            }
        }
    }

    printf("All bags successfully transferred!\n");

    return 0;
}