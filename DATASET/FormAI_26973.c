//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    int num_theories = 10; // Number of conspiracy theories generated
    char* theories[] = { // Array of conspiracy theories
        "The government is hiding aliens in Area 51",
        "The moon landing was faked by the government",
        "The Illuminati controls the world",
        "Bigfoot is real and the government is hiding it",
        "The Titanic sinking was not an accident",
        "The chocolate industry is controlled by the lizard people",
        "The Earth is flat",
        "The government is controlling the weather with HAARP",
        "The Loch Ness Monster is a government experiment",
        "The pyramids were built by aliens"
    };

    printf("Generating conspiracy theories...\n");

    for (int i = 0; i < num_theories; i++) { // Loop through each theory
        int random_index = rand() % num_theories; // Generate random index from 0 to num_theories-1
        printf("%d. %s\n", i+1, theories[random_index]); // Print the theory
    }

    return 0;
}