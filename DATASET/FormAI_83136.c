//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of element name and symbol
#define ELEM_NAME_LEN 20
#define ELEM_SYM_LEN 3

// Define the maximum number of elements
#define MAX_ELEMS 118

// Define the struct for each element
typedef struct Element {
    char name[ELEM_NAME_LEN];
    char symbol[ELEM_SYM_LEN];
    int atomic_number;
    double atomic_weight;
} Element;

// Define an array to store the elements
Element elements[MAX_ELEMS];

// Define the function prototype for printing the periodic table
void print_periodic_table();

// Define the function prototype for the quiz
void run_quiz();

int main() {
    // Initialize the elements array
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomic_number = 1;
    elements[0].atomic_weight = 1.008;
    // Initialize the other elements (abbreviated for brevity)
    // ...

    // Call the function to print the periodic table
    print_periodic_table();

    // Call the function to run the quiz
    run_quiz();

    return 0;
}

void print_periodic_table() {
    printf("%-3s %-20s %-5s %-10s\n", "No", "Name", "Sym", "Weight");
    printf("--- -------------------- ----- ----------\n");
    for (int i = 0; i < MAX_ELEMS; i++) {
        if (strlen(elements[i].name) > 0) {
            printf("%-3d %-20s %-5s %-10.4f\n", elements[i].atomic_number, elements[i].name, elements[i].symbol, elements[i].atomic_weight);
        }
    }
}

void run_quiz() {
    // Define variables for tracking quiz progress
    int num_correct = 0;
    int num_total = 0;

    printf("Welcome to the Periodic Table Quiz!\n");

    // Loop until the user decides to quit
    while (1) {
        // Randomly select an element
        int elem_idx = rand() % MAX_ELEMS;
        while (strlen(elements[elem_idx].name) == 0) {
            // If the element at this index is not defined, choose another index
            elem_idx = rand() % MAX_ELEMS;
        }

        // Ask the user for the symbol of the selected element
        printf("What is the symbol for %s? (type 'q' to quit)\n", elements[elem_idx].name);
        char user_input[ELEM_SYM_LEN + 2];
        scanf("%s", user_input);

        // Convert the user input to uppercase
        for (int i = 0; i < strlen(user_input); i++) {
            user_input[i] = toupper(user_input[i]);
        }

        if (strcmp(user_input, "Q") == 0) {
            // If the user typed 'q', exit the loop
            break;
        } else if (strcmp(user_input, elements[elem_idx].symbol) == 0) {
            // If the user input matches the correct symbol, increment the score
            printf("Correct!\n");
            num_correct++;
        } else {
            // If the user input does not match the correct symbol, show the correct answer
            printf("Sorry, the correct symbol for %s is %s.\n", elements[elem_idx].name, elements[elem_idx].symbol);
        }

        // Increment the number of questions asked
        num_total++;
    }

    // Print the final score
    printf("You got %d out of %d questions correct!\n", num_correct, num_total);
}