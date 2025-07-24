//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numTerminals = 4; // number of terminals
    int terminalCapacity = 100; // maximum number of bags a terminal can handle
    int numAirplanes = 10; // number of airplanes

    int totalBags = numAirplanes * 50; // total number of bags for the whole simulation
    int bagsProcessed = 0; // number of bags that have been processed
    int currentTerminal = 0; // current terminal being processed

    int terminals[numTerminals][terminalCapacity]; // 2D array of terminals and their current bag capacity
    for (int i = 0; i < numTerminals; i++) {
        for (int j = 0; j < terminalCapacity; j++) {
            terminals[i][j] = 0; // initialize all terminals with 0 bags
        }
    }

    srand(time(NULL)); // seed the random number generator with current time

    // loop until all bags are processed
    while (bagsProcessed < totalBags) {
        int numBags = rand() % 10 + 1; // generate a random number of bags for the current airplane (1-10)
        int airplaneTerminal = rand() % numTerminals; // generate a random terminal for the current airplane

        printf("Airplane %d has %d bags and will go to Terminal %d\n", (bagsProcessed / 50) + 1, numBags, airplaneTerminal + 1);

        // loop until all bags for current airplane are processed
        for (int i = 0; i < numBags; i++) {
            int bagProcessed = 0; // flag to check if bag has been successfully processed

            // loop through all terminals starting from the current terminal
            for (int j = currentTerminal; j < numTerminals; j++) {
                // check if current terminal has enough capacity for current bag
                if (terminalCapacity - (int)(sizeof terminals[j] / sizeof terminals[j][0]) >= 1) {
                    // add bag to current terminal
                    terminals[j][terminalCapacity - (int)(sizeof terminals[j] / sizeof terminals[j][0])] = 1;
                    printf("Bag %d from Airplane %d processed successfully at Terminal %d\n", i + 1, (bagsProcessed / 50) + 1, j + 1);
                    bagProcessed = 1; // set flag to indicate successful processing
                    break; // exit loop once bag has been processed
                }
            }

            if (!bagProcessed) {
                // loop through all terminals starting from the beginning
                for (int j = 0; j < currentTerminal; j++) {
                    // check if current terminal has enough capacity for current bag
                    if (terminalCapacity - (int)(sizeof terminals[j] / sizeof terminals[j][0]) >= 1) {
                        // add bag to current terminal
                        terminals[j][terminalCapacity - (int)(sizeof terminals[j] / sizeof terminals[j][0])] = 1;
                        printf("Bag %d from Airplane %d processed successfully at Terminal %d\n", i + 1, (bagsProcessed / 50) + 1, j + 1);
                        break; // exit loop once bag has been processed
                    }
                }
            }
        }

        bagsProcessed += numBags; // update total number of bags processed

        // update current terminal for the next airplane
        currentTerminal = (currentTerminal + 1) % numTerminals;
    }

    return 0;
}