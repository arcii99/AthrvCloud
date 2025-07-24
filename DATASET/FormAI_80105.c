//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declaration
void printHeader();
void printFooter();
void printConspiracy();

// Main function
int main() {
    printHeader();

    // Seed random number generator
    srand(time(NULL));

    // Print 10 random conspiracy theories
    for (int i = 1; i <= 10; i++) {
        printConspiracy();
    }

    printFooter();
    return 0;
}

// Function to print header
void printHeader() {
    printf("#############################################\n");
    printf("##              Conspiracy Bot             ##\n");
    printf("#############################################\n");
    printf("\n");
    printf("Generating random conspiracy theories...\n");
    printf("\n");
}

// Function to print footer
void printFooter() {
    printf("\n");
    printf("That's all for now. Stay safe!\n");
}

// Function to print a single conspiracy theory
void printConspiracy() {
    const char *theories[] = {
        "The moon landing was faked by NASA",
        "Chemtrails are being used to control people's minds",
        "The earth is actually flat and the globe model is a cover-up",
        "The Illuminati is controlling world events",
        "9/11 was an inside job",
        "Aliens have already made contact with the government and are being hidden from the public",
        "The government is hiding a cure for cancer",
        "The world is secretly run by a small group of wealthy individuals",
        "Climate change is a hoax created by the government to control the population",
        "The COVID-19 pandemic was created in a lab and released on purpose"
    };

    // Random index within the size of the theories array
    int index = rand() % (sizeof(theories) / sizeof(theories[0]));

    // Print theory
    printf("%d. %s\n", index+1, theories[index]);
}