//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// This struct represents a single element in the periodic table
typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
    double atomic_weight;
} Element;

// This function initializes an Element struct with the given values
void make_element(Element *element, char *name, char *symbol, int atomic_number, double atomic_weight) {
    strcpy(element->name, name);
    strcpy(element->symbol, symbol);
    element->atomic_number = atomic_number;
    element->atomic_weight = atomic_weight;
}

// This array stores all the elements in the periodic table
Element periodic_table[] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.003},
    {"Lithium", "Li", 3, 6.941},
    {"Beryllium", "Be", 4, 9.012},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.01},
    {"Nitrogen", "N", 7, 14.01},
    {"Oxygen", "O", 8, 16.00},
    {"Fluorine", "F", 9, 19.00},
    {"Neon", "Ne", 10, 20.18},
    {"Sodium", "Na", 11, 22.99},
    {"Magnesium", "Mg", 12, 24.31},
    {"Aluminum", "Al", 13, 26.98},
    {"Silicon", "Si", 14, 28.09},
    {"Phosphorus", "P", 15, 30.97},
    {"Sulfur", "S", 16, 32.07},
    {"Chlorine", "Cl", 17, 35.45},
    {"Argon", "Ar", 18, 39.95},
    {"Potassium", "K", 19, 39.10},
    {"Calcium", "Ca", 20, 40.08},
    {"Scandium", "Sc", 21, 44.96},
    {"Titanium", "Ti", 22, 47.87},
    {"Vanadium", "V", 23, 50.94},
    {"Chromium", "Cr", 24, 52.00},
    {"Manganese", "Mn", 25, 54.94},
    {"Iron", "Fe", 26, 55.85},
    {"Cobalt", "Co", 27, 58.93},
    {"Nickel", "Ni", 28, 58.69},
    {"Copper", "Cu", 29, 63.55},
    {"Zinc", "Zn", 30, 65.38},
    {"Gallium", "Ga", 31, 69.72},
    {"Germanium", "Ge", 32, 72.63},
    {"Arsenic", "As", 33, 74.92},
    {"Selenium", "Se", 34, 78.96},
    {"Bromine", "Br", 35, 79.90},
    {"Krypton", "Kr", 36, 83.80}
};

// This function returns true if the given string is a valid element symbol
bool is_valid_symbol(char *symbol) {
    // Loop through the periodic table and check if any symbol matches the given string
    for (int i = 0; i < sizeof(periodic_table) / sizeof(periodic_table[0]); i++) {
        if (strcmp(periodic_table[i].symbol, symbol) == 0) {
            return true;
        }
    }
    return false;
}

// This function returns true if the user wants to quit the program
bool should_quit(char *input) {
    return strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0;
}

int main() {
    char input[20];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Type 'quit' or 'exit' to stop the program.\n\n");
    
    // Loop until the user decides to quit
    while (true) {
        // Ask the user for an element symbol
        printf("Enter an element symbol: ");
        fgets(input, 20, stdin);
        
        // Remove whitespace from the input
        for (int i = 0; i < strlen(input); i++) {
            if (isspace(input[i])) {
                input[i] = '\0';
                break;
            }
        }
        
        // Check if the user wants to quit
        if (should_quit(input)) {
            printf("\nThank you for playing the Periodic Table Quiz!\n");
            break;
        }
        
        // Check if the input is a valid symbol
        if (!is_valid_symbol(input)) {
            printf("\nSorry, '%s' is not a valid element symbol.\n\n", input);
            continue;
        }
        
        // Find the element with the given symbol and print its information
        for (int i = 0; i < sizeof(periodic_table) / sizeof(periodic_table[0]); i++) {
            if (strcmp(periodic_table[i].symbol, input) == 0) {
                printf("\n%s\n", periodic_table[i].name);
                printf("Symbol: %s\n", periodic_table[i].symbol);
                printf("Atomic number: %d\n", periodic_table[i].atomic_number);
                printf("Atomic weight: %.3f\n\n", periodic_table[i].atomic_weight);
                break;
            }
        }
    }
    
    return 0;
}