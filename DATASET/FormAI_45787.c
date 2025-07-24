//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENTS 118

// Define a struct for each element
typedef struct element {
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicMass;
} element;

// Initialize an array of element structs
element periodicTable[MAX_ELEMENTS];

// Function to populate the periodic table with elements
void populateTable() {
    strcpy(periodicTable[0].symbol, "H");
    strcpy(periodicTable[0].name, "Hydrogen");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicMass = 1.0079;

    strcpy(periodicTable[1].symbol, "He");
    strcpy(periodicTable[1].name, "Helium");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicMass = 4.0026;

    // Add more elements here...
}

// Function to display periodic table
void displayTable() {
    printf("Periodic Table\n");
    printf("--------------------\n");
    printf("Symbol\tName\t\tAtomic Number\tAtomic Mass\n");
    printf("--------------------\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%s\t%s\t\t%d\t\t%.4f\n", periodicTable[i].symbol, periodicTable[i].name, periodicTable[i].atomicNumber, periodicTable[i].atomicMass);
    }
}

// Function to start the quiz
void startQuiz() {
    int score = 0;
    char answer[10];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the questions with the element's symbol.\n\n");

    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for %s?\n", i+1, periodicTable[randomIndex].name);
        scanf("%s", answer);

        // Convert answer to uppercase
        for (int j = 0; answer[j] != '\0'; j++) {
            answer[j] = toupper(answer[j]);
        }

        if (strcmp(answer, periodicTable[randomIndex].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The symbol for %s is %s.\n", periodicTable[randomIndex].name, periodicTable[randomIndex].symbol);
        }
    }

    printf("\nQuiz complete! You scored %d out of 10.\n", score);
}

// Main function
int main() {
    populateTable();
    displayTable();
    startQuiz();

    return 0;
}