//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // array of conspiracy theories
    char *theories[] = {
        "The moon landing was faked.",
        "JFK was assassinated by the CIA.",
        "9/11 was an inside job.",
        "The government is hiding the cure for cancer.",
        "Elvis is still alive.",
        "Chemtrails are poisoning us.",
        "The Illuminati control the world.",
        "Bigfoot is a government experiment.",
        "Aliens are among us.",
        "The Earth is flat.",
        "Vaccines cause autism."
    };

    int num_theories = sizeof(theories) / sizeof(theories[0]); // get number of theories

    printf("The truth is out there...\n");

    while(1) {
        printf("Press enter to generate a new conspiracy theory...\n");
        getchar(); // wait for user input

        int random_index = rand() % num_theories; // generate random index
        printf("Conspiracy Theory: %s\n", theories[random_index]);
    }

    return 0;
}