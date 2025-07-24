//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118

// Define element structure
typedef struct Element {
    char name[20];
    char symbol[3];
    int atomic_number;
    int group_number;
    int period;
    char electron_configuration[30];
} Element;

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize array of elements
    Element elements[MAX_ELEMENTS];
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomic_number = 1;
    elements[0].group_number = 1;
    elements[0].period = 1;
    strcpy(elements[0].electron_configuration, "1s1");

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomic_number = 2;
    elements[1].group_number = 18;
    elements[1].period = 1;
    strcpy(elements[1].electron_configuration, "1s2");

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomic_number = 3;
    elements[2].group_number = 1;
    elements[2].period = 2;
    strcpy(elements[2].electron_configuration, "1s2 2s1");

    // Add remaining elements here...

    // Shuffle array of elements
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    int score = 0;
    int total = 0;

    // Ask user questions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Type the element's symbol or 'exit' to quit the quiz.\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        char answer[3];
        printf("\nWhat is the symbol for %s? ", elements[i].name);
        scanf("%s", answer);

        // Check if user wants to exit quiz
        if (strcmp(answer, "exit") == 0) {
            break;
        }

        total++;

        // Check if user gave correct answer
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %s.\n", elements[i].symbol);
        }
    }

    // Calculate and display final score
    printf("\nYou answered %d out of %d questions correctly.\n", score, total);
    printf("Thank you for taking the quiz!\n");

    return 0;
}