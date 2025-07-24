//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // A list of conspiracy theories
    char *theories[] = { 
        "The moon landing was faked by the government",
        "COVID-19 was purposely created in a lab",
        "The earth is flat and the government is covering it up",
        "The government is hiding evidence of alien life",
        "The Illuminati controls the world's governments",
        "The government is hiding the cure for cancer",
        "The 9/11 attacks were an inside job",
        "The government is suppressing free energy technology",
        "The government is manipulating the weather with chemtrails",
        "The Freemasons have been secretly controlling world events for centuries",
        "The global elite are planning a New World Order"
    };

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random index for the conspiracy theory
    int index = rand() % 11;

    // Output the conspiracy theory
    printf("Did you know that %s?\n", theories[index]);

    return 0;
}