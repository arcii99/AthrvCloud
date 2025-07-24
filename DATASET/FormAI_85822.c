//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for element information
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_weight;
} element;

// Function to initialize the periodic table
void initialize_table(element table[]) {
    // Add each element to the table
    strcpy(table[0].symbol, "H");
    strcpy(table[0].name, "Hydrogen");
    table[0].atomic_number = 1;
    table[0].atomic_weight = 1.008;

    strcpy(table[1].symbol, "He");
    strcpy(table[1].name, "Helium");
    table[1].atomic_number = 2;
    table[1].atomic_weight = 4.003;

    strcpy(table[2].symbol, "Li");
    strcpy(table[2].name, "Lithium");
    table[2].atomic_number = 3;
    table[2].atomic_weight = 6.941;

    // ...continue initializing the rest of the elements
}

// Function to print the periodic table
void print_table(element table[]) {
    printf("Symbol\tName\tAtomic Number\tAtomic Weight\n");

    for (int i = 0; i < 118; i++) {
        printf("%s\t%s\t%d\t\t%lf\n", table[i].symbol, table[i].name, table[i].atomic_number, table[i].atomic_weight);
    }
}

int main() {
    // Create an array to hold the periodic table
    element table[118];

    // Initialize the periodic table
    initialize_table(table);

    // Print the periodic table
    printf("Welcome to the Periodic Table Quiz! Here is the periodic table:\n");
    print_table(table);

    // Display a prompt to the user and read their input
    char user_input[10];
    printf("Enter the symbol of an element to get its name and information: ");
    scanf("%s", user_input);

    // Find the element with the matching symbol
    int index = -1;
    for (int i = 0; i < 118; i++) {
        if (strcmp(user_input, table[i].symbol) == 0) {
            index = i;
            break;
        }
    }

    // Print the information of the found element or an error message
    if (index >= 0) {
        printf("Name: %s\n", table[index].name);
        printf("Atomic Number: %d\n", table[index].atomic_number);
        printf("Atomic Weight: %lf\n", table[index].atomic_weight);
    } else {
        printf("Error: Element not found.\n");
    }

    return 0;
}