//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random conspiracy theory
void generate_conspiracy_theory() {
    // Array of possible conspiracy theories
    char *theories[] = {"NASA faked the moon landing",
                        "The government is hiding the cure for cancer",
                        "The Illuminati controls the world",
                        "Chemtrails are poisoning the population",
                        "9/11 was an inside job",
                        "The earth is flat",
                        "The Bermuda Triangle is a gateway to another dimension",
                        "The reptilian elite are in control of our governments",
                        "Time travel has already been invented",
                        "Aliens are living among us"};

    // Get the number of theories in the array
    int num_theories = sizeof(theories)/sizeof(theories[0]);

    // Generate a random index between 0 and the number of theories - 1
    srand(time(NULL));
    int index = rand() % num_theories;

    // Print the randomly selected conspiracy theory
    printf("Did you know: %s?\n", theories[index]);
}

// Main function
int main() {
    // Generate 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        generate_conspiracy_theory();
    }

    return 0;
}