//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constants
#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 50

// struct to hold element information
typedef struct element_t {
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    float atomic_weight;
} element;

// function to print periodic table
void print_periodic_table(element *table, int num_elements) {
    printf("------------------------------------------------------------------------\n");
    printf("| Atomic Num | Symbol |           Name           | Atomic Weight (g/mol) |\n");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < num_elements; i++) {
        printf("|%11d|%8s|%25s|%22.4f|\n", table[i].atomic_number, table[i].symbol, table[i].name, table[i].atomic_weight);
    }
    printf("------------------------------------------------------------------------\n");
}

// function to search for element by symbol
element* search_by_symbol(char symbol[], element *table, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        if (strcmp(symbol, table[i].symbol) == 0) {
            return &table[i];
        }
    }
    return NULL;
}

int main() {
    // initialize periodic table
    element periodic_table[NUM_ELEMENTS] = {
        {1, "H", "Hydrogen", 1.008},
        {2, "He", "Helium", 4.0026},
        {3, "Li", "Lithium", 6.94},
        {4, "Be", "Beryllium", 9.0122},
        {5, "B", "Boron", 10.81},
        {6, "C", "Carbon", 12.011},
        {7, "N", "Nitrogen", 14.007},
        {8, "O", "Oxygen", 15.999},
        {9, "F", "Flourine", 18.998},
        {10, "Ne", "Neon", 20.180},
        // add remaining elements here
    };

    int choice = -1;
    while (choice != 0) {
        // print options
        printf("---------------------------------------------------------------\n");
        printf("|            PERIODIC TABLE QUIZ MENU                          |\n");
        printf("---------------------------------------------------------------\n");
        printf("| Option |                      Description                      |\n");
        printf("---------------------------------------------------------------\n");
        printf("|   1    |  Print the periodic table                             |\n");
        printf("|   2    |  Search for an element by symbol                      |\n");
        printf("|   0    |  Exit                                                |\n");
        printf("---------------------------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // print periodic table
                print_periodic_table(periodic_table, NUM_ELEMENTS);
                break;
            case 2: // search for element by symbol
                char symbol[3];
                printf("Enter symbol: ");
                scanf("%s", symbol);

                element *el = search_by_symbol(symbol, periodic_table, NUM_ELEMENTS);
                if (el == NULL) {
                    printf("Element not found.\n");
                } else {
                    printf("Atomic number: %d\n", el->atomic_number);
                    printf("Name: %s\n", el->name);
                    printf("Atomic weight: %f\n", el->atomic_weight);
                }
                break;
            case 0: // exit program
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}