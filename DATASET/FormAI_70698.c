//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constants for the number of elements and the length of element names
#define NUM_ELEMENTS 118
#define ELEMENT_NAME_LENGTH 15

// Define a struct for each element
typedef struct {
    int atomicNumber;
    char symbol[3];
    char name[ELEMENT_NAME_LENGTH];
    float atomicWeight;
} Element;

// Define an array of Element structs to store all the periodic table data
Element periodicTable[NUM_ELEMENTS] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.003},
    // additional element data omitted for brevity
    {117, "Ts", "Tennessine", 294},
    {118, "Og", "Oganesson", 294}
};

// Define a function to generate a random atomic number between 1 and NUM_ELEMENTS
int generateRandomAtomicNumber() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int randomAtomicNumber = rand() % NUM_ELEMENTS + 1;
    return randomAtomicNumber;
}

// Define a function to check if an input string is a valid element symbol or name
int isValidInput(char* input) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        Element element = periodicTable[i];
        if (strcmp(input, element.symbol) == 0 || strcmp(input, element.name) == 0) {
            return 1; // Input is valid
        }
    }
    return 0; // Input is invalid
}

// Define a function to retrieve an Element struct from the periodicTable array using a given atomic number
Element getElementByAtomicNumber(int atomicNumber) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        Element element = periodicTable[i];
        if (element.atomicNumber == atomicNumber) {
            return element;
        }
    }
}

int main() {
    int score = 0;
    int gameOver = 0;
    printf("Welcome to the Periodic Table Quiz!\n\n");

    while (!gameOver && score < NUM_ELEMENTS) {
        int randomAtomicNumber = generateRandomAtomicNumber();
        Element randomElement = getElementByAtomicNumber(randomAtomicNumber);
        printf("What is the symbol or name for element #%d?\n", randomAtomicNumber);

        char input[ELEMENT_NAME_LENGTH];
        fgets(input, ELEMENT_NAME_LENGTH, stdin); // Read user input
        input[strcspn(input, "\n")] = 0; // Remove trailing newline character

        if (isValidInput(input)) {
            if (strcmp(input, randomElement.symbol) == 0 || strcmp(input, randomElement.name) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", randomElement.symbol);
            }
        } else {
            printf("Invalid input. Please enter the symbol or name of an element.\n");
        }

        printf("Score: %d/%d\n\n", score, NUM_ELEMENTS);
        printf("Press 'q' to quit, or any other key to continue...\n");
        char quitInput[2];
        fgets(quitInput, 2, stdin); // Read user input
        if (strcmp(quitInput, "q") == 0) {
            gameOver = 1;
        }
    }

    printf("Game over! Final score: %d/%d\n", score, NUM_ELEMENTS);
    return 0;
}