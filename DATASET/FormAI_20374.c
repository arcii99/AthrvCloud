//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define macros
#define MAX_LEN 100

// Define conspiracy struct
typedef struct conspiracy {
    char name[MAX_LEN];
    char description[MAX_LEN];
    int likelihood;
} Conspiracy;

// Declare global variables
Conspiracy conspiracies[5];

// Declare function prototypes
void create_conspiracies();
int select_conspiracy();
bool run_conspiracy(int conspiracy_index);

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create conspiracy objects
    create_conspiracies();

    // Display intro message
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press enter to generate your conspiracy theory.\n\n");

    // Wait for user input
    getchar();

    // Select conspiracy
    int conspiracy_index = select_conspiracy();

    // Run selected conspiracy
    bool success = run_conspiracy(conspiracy_index);

    // Display result message
    if (success) {
        printf("Congratulations! You've uncovered the truth!\n");
    } else {
        printf("Sorry, the conspiracy was too big to handle. Better luck next time!\n");
    }

    return 0;
}

void create_conspiracies() {
    // Conspiracy 1
    Conspiracy conspiracy1 = {"The Faked Moon Landing Conspiracy",
                        "The theory that the Apollo moon landing was fake and filmed by NASA in a studio.",
                        7};
    conspiracies[0] = conspiracy1;

    // Conspiracy 2
    Conspiracy conspiracy2 = {"The Big Pharma Conspiracy",
                        "The theory that pharmaceutical companies suppress cheap and effective cures for diseases in order to maximize profits.",
                        8};
    conspiracies[1] = conspiracy2;

    // Conspiracy 3
    Conspiracy conspiracy3 = {"The Illuminati Conspiracy",
                        "The theory that a secret society called the Illuminati controls world events and governments.",
                        5};
    conspiracies[2] = conspiracy3;

    // Conspiracy 4
    Conspiracy conspiracy4 = {"The Flat Earth Conspiracy",
                        "The theory that the Earth is actually flat and that NASA and other organizations are hiding this fact.",
                        6};
    conspiracies[3] = conspiracy4;

    // Conspiracy 5
    Conspiracy conspiracy5 = {"The Reptilian Elite Conspiracy",
                        "The theory that shape-shifting reptilian aliens control world governments and are responsible for many historical events.",
                        4};
    conspiracies[4] = conspiracy5;
}

int select_conspiracy() {
    // Generate random number between 0 and 4
    int i = rand() % 5;

    // Display selected conspiracy
    printf("Your selected conspiracy is:\n");
    printf("%s\n", conspiracies[i].name);
    printf("%s\n", conspiracies[i].description);
    printf("On a scale of 1 to 10, with 10 being most likely, this conspiracy has a likelihood rating of %d.\n", conspiracies[i].likelihood);

    // Return index of selected conspiracy
    return i;
}

bool run_conspiracy(int conspiracy_index) {
    // Generate random number between 1 and 10
    int i = rand() % 10 + 1;

    // Determine success based on likelihood
    if (i <= conspiracies[conspiracy_index].likelihood) {
        return true;
    } else {
        return false;
    }
}