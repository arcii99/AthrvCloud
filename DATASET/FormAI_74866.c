//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_weight;
    char state[10];
} Element;

Element periodic_table[118]; // Array to hold all elements

void initialize_periodic_table() {
    // Here, we are initializing some elements of the periodic table
    strcpy(periodic_table[0].symbol, "H");
    strcpy(periodic_table[0].name, "Hydrogen");
    periodic_table[0].atomic_number = 1;
    periodic_table[0].atomic_weight = 1.008;
    strcpy(periodic_table[0].state, "Gas");

    strcpy(periodic_table[1].symbol, "He");
    strcpy(periodic_table[1].name, "Helium");
    periodic_table[1].atomic_number = 2;
    periodic_table[1].atomic_weight = 4.003;
    strcpy(periodic_table[1].state, "Gas");

    strcpy(periodic_table[2].symbol, "Li");
    strcpy(periodic_table[2].name, "Lithium");
    periodic_table[2].atomic_number = 3;
    periodic_table[2].atomic_weight = 6.941;
    strcpy(periodic_table[2].state, "Solid");
    
    // Add more elements here...
}

void print_periodic_table() {
    // Print all the elements of the periodic table
    printf("\nPeriodic Table\n");
    printf("---------------\n");
    printf("Symbol\t\tName\t\tAtomic #\tAtomic Weight (g/mol)\tState\n");
    for(int i = 0; i < 118; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.3f\t\t\t%s\n", periodic_table[i].symbol, periodic_table[i].name, periodic_table[i].atomic_number, periodic_table[i].atomic_weight, periodic_table[i].state);
    }
}

int main() {
    initialize_periodic_table();

    printf("Welcome to the Periodic Table Quiz!\n\n");

    char input[3];
    int score = 0;

    for(int i = 0; i < 10; i++) {
        int rand_index = rand() % 118; // Get a random element from the periodic table
        printf("What is the symbol for %s?\n", periodic_table[rand_index].name);
        scanf("%s", input);

        if(strcmp(input, periodic_table[rand_index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Wrong. The correct answer is %s.\n", periodic_table[rand_index].symbol);
        }
    }

    printf("\nQuiz is over! You got %d out of 10 correct.\n", score);

    print_periodic_table();

    return 0;
}