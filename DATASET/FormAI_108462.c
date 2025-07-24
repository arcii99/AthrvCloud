//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Set the seed for random number generation

    // Welcome message
    printf("Welcome to the Haunted House Simulator! Press enter to continue.\n");
    getchar();

    // Set up a loop to run the simulation
    int runSimulation = 1;
    while (runSimulation) {
        // Randomly choose a room to enter
        int room = rand() % 3 + 1;
        switch (room) {
            case 1:
                printf("You entered the kitchen and found a ghost chef baking cookies!\n");
                break;
            case 2:
                printf("You entered the living room and found a ghostly tea party in progress!\n");
                break;
            case 3:
                printf("You entered the bedroom and found a friendly ghost playing video games!\n");
                break;
        }

        // Ask the user if they want to continue or exit
        printf("Would you like to explore another room? (y/n)\n");
        char continueResponse = getchar();
        getchar(); // Consume the newline character

        if (continueResponse == 'n' || continueResponse == 'N') {
            runSimulation = 0;
        }
    }

    // Goodbye message
    printf("Thanks for exploring the haunted house! We hope you had a boo-tiful time!\n");

    return 0;
}