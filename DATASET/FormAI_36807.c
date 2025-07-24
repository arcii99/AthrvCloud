//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 12

// Struct to hold information about a chemical element
struct Element {
    char symbol[3];
    char name[20];
    int atomicNumber;
};

// Function to initialize elements array with data
void initElements(struct Element elements[]) {
    // Symbols and names from https://www.lenntech.com/periodic/periodic-chart.htm
    // Atomic numbers from https://education.jlab.org/itselemental/
    strcpy(elements[0].symbol, "H\0");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomicNumber = 1;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomicNumber = 2;

    // Rest of the elements (up to Neon) have been omitted for brevity

    strcpy(elements[10].symbol, "Ne");
    strcpy(elements[10].name, "Neon");
    elements[10].atomicNumber = 10;

    strcpy(elements[11].symbol, "Na");
    strcpy(elements[11].name, "Sodium");
    elements[11].atomicNumber = 11;
}

// Function to shuffle elements array
void shuffleElements(struct Element elements[]) {
    srand(time(NULL)); // Seed random number generator
    int i, j;
    struct Element temp;

    for (i = NUM_ELEMENTS - 1; i >= 1; i--) {
        j = rand() % (i + 1); // Choose random index from 0 to i

        // Swap elements[i] and elements[j]
        temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Function to print periodic table quiz
void printPeriodicTableQuiz(struct Element elements[]) {
    int i, j;
    char response[3];

    printf("Welcome to the periodic table quiz!\n");
    printf("Type in the atomic symbol for each element.\n");
    printf("When you're done, type 'exit' to quit.\n\n");

    for (i = 0; i < 5; i++) { // Print 5 rows of 3 elements
        for (j = 0; j < 3; j++) {
            printf("%-3s", elements[i * 3 + j].symbol);
        }
        printf("\n");
    }

    while (1) { // Loop until user types 'exit'
        printf("\nEnter an atomic symbol: ");
        scanf("%s", response);

        if (!strcmp(response, "exit")) {
            printf("\nThanks for playing!\n");
            break;
        }

        // Look for matching atomic symbol
        for (i = 0; i < NUM_ELEMENTS; i++) {
            if (!strcmp(response, elements[i].symbol)) {
                printf("Correct! %s is %s.\n", response, elements[i].name);
                break;
            }
        }

        if (i == NUM_ELEMENTS) { // No match was found
            printf("Sorry, that is not a valid atomic symbol.\n");
        }
    }
}

int main(void) {
    struct Element elements[NUM_ELEMENTS];
    initElements(elements);
    shuffleElements(elements);
    printPeriodicTableQuiz(elements);
    return 0;
}