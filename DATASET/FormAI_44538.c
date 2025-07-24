//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 118
#define ELEMENT_NAME_LENGTH 20
#define SYMBOL_LENGTH 3

typedef struct element {
    char name[ELEMENT_NAME_LENGTH];
    char symbol[SYMBOL_LENGTH];
    int atomic_number;
    double atomic_weight;
} element;

element table[TABLE_SIZE];

void initialize_table() {
    strcpy(table[0].name, "Hydrogen");
    strcpy(table[0].symbol, "H");
    table[0].atomic_number = 1;
    table[0].atomic_weight = 1.008;

    strcpy(table[1].name, "Helium");
    strcpy(table[1].symbol, "He");
    table[1].atomic_number = 2;
    table[1].atomic_weight = 4.003;

    strcpy(table[2].name, "Lithium");
    strcpy(table[2].symbol, "Li");
    table[2].atomic_number = 3;
    table[2].atomic_weight = 6.941;

    // rest of the elements initialized here
}

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbol of an element, and you must guess its name.\n");
    printf("Enter 'quit' at any time to exit the quiz.\n\n");

    char input[SYMBOL_LENGTH];
    char guess[ELEMENT_NAME_LENGTH];

    initialize_table();

    int score = 0;
    int total = 0;

    while (1) {
        // choose a random element from the table
        int index = rand() % TABLE_SIZE;
        printf("What is the name of the element with symbol %s?\n", table[index].symbol);

        scanf("%s", input);

        // quit command
        if (strcmp(input, "quit") == 0) {
            printf("You got %d out of %d correct. Goodbye!\n", score, total);
            return 0;
        }

        // incorrect guess
        if (strcmp(input, table[index].symbol) != 0) {
            printf("Sorry, that is incorrect. The correct answer is %s.\n", table[index].name);
        } 
        // correct guess
        else {
            printf("Correct!\n");
            score++;
        }

        total++;
        printf("Your current score is %d out of %d.\n\n", score, total);
    }
}