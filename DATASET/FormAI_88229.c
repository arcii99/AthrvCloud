//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for elements in periodic table
typedef struct {
    int atomicNumber;
    char symbol[3];
    char name[20];
    float atomicWeight;
} Element;

// Define array for all elements in periodic table
Element elements[] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.003},
    {3, "Li", "Lithium", 6.941},
    {4, "Be", "Beryllium", 9.012},
    {5, "B", "Boron", 10.81},
    {6, "C", "Carbon", 12.01},
    {7, "N", "Nitrogen", 14.01},
    {8, "O", "Oxygen", 16.00},
    {9, "F", "Fluorine", 19.00},
    {10, "Ne", "Neon", 20.18},
    {11, "Na", "Sodium", 22.99},
    {12, "Mg", "Magnesium", 24.31}
    // ... more elements go here
};

int main() {
    int numElements = sizeof(elements) / sizeof(elements[0]);
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown the symbol or name of an element and have to provide the other one.\n");
    printf("Type 'quit' at any time to exit the quiz.\n\n");

    // Loop through all elements in the periodic table
    for (int i = 0; i < numElements; i++) {
        // Choose whether to ask for symbol or name
        int askSymbol = rand() % 2;

        // Print out question
        printf("What is the %s of %s? ", askSymbol ? "symbol" : "name", elements[i].name);

        // Read input from user
        char input[20];
        fgets(input, 20, stdin);

        // Check if user wants to quit
        if (strcmp(input, "quit\n") == 0) {
            printf("Thanks for playing!\n");
            return 0;
        }

        // Remove newline from input
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        // Check if input is correct
        if ((askSymbol && strcmp(input, elements[i].symbol) == 0) ||
            (!askSymbol && strcmp(input, elements[i].name) == 0)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer is %s.\n", askSymbol ? elements[i].symbol : elements[i].name);
        }
    }

    // Print out final score
    printf("\nYou scored %d out of %d!\n", score, numElements);

    return 0;
}