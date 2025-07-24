//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 120 // Maximum elements the periodic table can have
#define MAX_NAME_LEN 50 // Maximum length of the name of an element
#define MAX_SYMBOL_LEN 3 // Maximum length of the symbol of an element

typedef struct { // Data structure to hold information about an element
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int atomic_number;
    double atomic_weight;
} element_info;

element_info periodic_table[MAX_ELEMENTS]; // Global variable to hold the elements in the periodic table
int num_elements = 0; // Global variable to hold the number of elements in the periodic table

/* Function to add a new element to the periodic table */
void add_element_to_periodic_table(char *name, char *symbol, int atomic_number, double atomic_weight) {
    if(num_elements >= MAX_ELEMENTS) { // Check if adding a new element will exceed the maximum number of elements
        printf("Error: Maximum number of elements reached!\n");
        return;
    }

    // Add the new element to the periodic table
    strncpy(periodic_table[num_elements].name, name, MAX_NAME_LEN);
    strncpy(periodic_table[num_elements].symbol, symbol, MAX_SYMBOL_LEN);
    periodic_table[num_elements].atomic_number = atomic_number;
    periodic_table[num_elements].atomic_weight = atomic_weight;

    num_elements++;
}

/* Function to print all elements in the periodic table */
void print_periodic_table() {
    printf("Elements in the periodic table:\n");
    for(int i=0; i<num_elements; i++) {
        printf("%s (%s) - Atomic number: %d, Atomic weight: %.4f\n", periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_number, periodic_table[i].atomic_weight);
    }
}

/* Function to sort the periodic table by atomic number using bubble sort */
void sort_periodic_table_by_atomic_number() {
    for(int i=0; i<num_elements-1; i++) {
        for(int j=0; j<num_elements-i-1; j++) {
            if(periodic_table[j].atomic_number > periodic_table[j+1].atomic_number) {
                element_info temp = periodic_table[j];
                periodic_table[j] = periodic_table[j+1];
                periodic_table[j+1] = temp;
            }
        }
    }

    printf("Periodic table sorted by atomic number!\n");
}

int main() {
    /* Add elements to the periodic table */
    add_element_to_periodic_table("Hydrogen", "H", 1, 1.008);
    add_element_to_periodic_table("Helium", "He", 2, 4.003);
    add_element_to_periodic_table("Lithium", "Li", 3, 6.941);
    add_element_to_periodic_table("Beryllium", "Be", 4, 9.012);
    add_element_to_periodic_table("Carbon", "C", 6, 12.011);
    add_element_to_periodic_table("Nitrogen", "N", 7, 14.007);
    add_element_to_periodic_table("Oxygen", "O", 8, 15.999);
    add_element_to_periodic_table("Fluorine", "F", 9, 18.998);
    add_element_to_periodic_table("Neon", "Ne", 10, 20.180);

    print_periodic_table();

    sort_periodic_table_by_atomic_number();

    print_periodic_table();

    return 0;
}