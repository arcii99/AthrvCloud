//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <string.h>

struct element {
    char name[20];
    char symbol[3];
    int atomic_number;
    float atomic_weight;
};

typedef struct element Element;

int main() {
    Element periodic_table[118]; // Number of known elements
    int num_elements = 0;
    char user_symbol[3];
    int user_atomic_number;

    // Adding elements to the periodic table
    strcpy(periodic_table[num_elements].name, "Hydrogen");
    strcpy(periodic_table[num_elements].symbol, "H");
    periodic_table[num_elements].atomic_number = 1;
    periodic_table[num_elements].atomic_weight = 1.008;
    num_elements++;

    strcpy(periodic_table[num_elements].name, "Carbon");
    strcpy(periodic_table[num_elements].symbol, "C");
    periodic_table[num_elements].atomic_number = 6;
    periodic_table[num_elements].atomic_weight = 12.011;
    num_elements++;

    strcpy(periodic_table[num_elements].name, "Oxygen");
    strcpy(periodic_table[num_elements].symbol, "O");
    periodic_table[num_elements].atomic_number = 8;
    periodic_table[num_elements].atomic_weight = 15.999;
    num_elements++;

    // Additional elements can be added here

    printf("Welcome to the C Periodic Table Quiz\n");
    printf("Please enter either the element symbol or atomic number to get information about an element\n");

    // User input loop
    while (1) {
        printf("Enter element symbol or atomic number (0 to quit): ");
        if (scanf("%2s", user_symbol) == 1) {
            if (strcmp(user_symbol, "0") == 0) {
                printf("Thanks for playing!");
                break;
            }
            int i;
            int found = 0;
            for (i = 0; i < num_elements; i++) {
                if (strcmp(user_symbol, periodic_table[i].symbol) == 0) {
                    printf("Name: %s\n", periodic_table[i].name);
                    printf("Atomic Number: %d\n", periodic_table[i].atomic_number);
                    printf("Atomic Weight: %.3f\n", periodic_table[i].atomic_weight);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Element not found\n");
            }
        } else if (scanf("%d", &user_atomic_number) == 1) {
            if (user_atomic_number == 0) {
                printf("Thanks for playing!");
                break;
            }
            int i;
            int found = 0;
            for (i = 0; i < num_elements; i++) {
                if (user_atomic_number == periodic_table[i].atomic_number) {
                    printf("Name: %s\n", periodic_table[i].name);
                    printf("Symbol: %s\n", periodic_table[i].symbol);
                    printf("Atomic Weight: %.3f\n", periodic_table[i].atomic_weight);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Element not found\n");
            }
        } else {
            printf("Invalid input\n");
            char junk;
            while ((junk = getchar()) != '\n' && junk != EOF) {
                continue;
            }
        }
    }
    return 0;
}