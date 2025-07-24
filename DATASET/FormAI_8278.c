//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_INPUT_LENGTH 10
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[25];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable()
{
    strcpy(periodicTable[0].symbol, "H");
    strcpy(periodicTable[0].name, "Hydrogen");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicWeight = 1.008;

    strcpy(periodicTable[1].symbol, "He");
    strcpy(periodicTable[1].name, "Helium");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicWeight = 4.003;

    strcpy(periodicTable[2].symbol, "Li");
    strcpy(periodicTable[2].name, "Lithium");
    periodicTable[2].atomicNumber = 3;
    periodicTable[2].atomicWeight = 6.941;
    // remaining initialize code goes here
}

int main()
{
    // Initialize the periodic table
    initializePeriodicTable();

    // Display a welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Instructions: Enter the symbol or name of the element that corresponds to the given atomic number.\n");
    printf("Type 'quit' to end the quiz.\n\n");

    // Begin the quiz
    int numCorrect = 0;
    int numQuestions = 0;
    char input[MAX_INPUT_LENGTH];
    while (1) {
        // Generate random atomic number
        int atomicNumber = rand() % MAX_ELEMENTS + 1;

        // Prompt for symbol or name of corresponding element
        printf("Question %d: ", numQuestions + 1);
        printf("What element has an atomic number of %d? ", atomicNumber);
        scanf("%s", input);

        // Check for quit command
        if (strcmp(input, "quit") == 0) {
            printf("\n\nYou got %d out of %d questions correct!\n", numCorrect, numQuestions);
            printf("Thanks for playing the Periodic Table Quiz.\n");
            break;
        }

        // Check if input is symbol or name
        int isSymbol = (strlen(input) <= MAX_SYMBOL_LENGTH);

        // Search for element in periodic table
        int index = -1;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if ((isSymbol && strcmp(input, periodicTable[i].symbol) == 0) ||
                (!isSymbol && strcmp(input, periodicTable[i].name) == 0)) {
                index = i;
                break;
            }
        }

        // Check if correct answer
        if (index >= 0 && periodicTable[index].atomicNumber == atomicNumber) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect. The answer is %s.\n", periodicTable[atomicNumber - 1].symbol);
        }

        numQuestions++;
    }

    return 0;
}