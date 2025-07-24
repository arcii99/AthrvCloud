//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Define the maximum size for element name
#define MAX_NAME_SIZE 20

// Structure for storing element properties
struct Element {
   int atomicNumber;
   char symbol[3];
   char name[MAX_NAME_SIZE];
   float atomicMass;
};

// Function for initializing the periodic table
void initPeriodicTable(struct Element *table) {
    // Loop through the first 20 elements
    for (int i = 0; i < 20; i++) {
        // Assign element properties
        table[i].atomicNumber = i+1;
        strcpy(table[i].symbol, "Xx");
        strcpy(table[i].name, "Unknown");
        table[i].atomicMass = -1.0;
    }
}

// Function for adding an element to the periodic table
void addElement(struct Element *table, int atomicNumber, char symbol[3], char name[MAX_NAME_SIZE], float atomicMass) {
    // Assign element properties
    table[atomicNumber-1].atomicNumber = atomicNumber;
    strcpy(table[atomicNumber-1].symbol, symbol);
    strcpy(table[atomicNumber-1].name, name);
    table[atomicNumber-1].atomicMass = atomicMass;
}

// Function for searching for an element by symbol
int searchElement(struct Element *table, char symbol[3]) {
    // Loop through all elements in the table
    for (int i = 0; i < 20; i++) {
        // If the symbol matches, return the atomic number
        if (strcmp(table[i].symbol, symbol) == 0) {
            return table[i].atomicNumber;
        }
    }
    // If the symbol is not found, return -1
    return -1;
}

// Main function for the periodic table quiz
int main() {
    // Initialize the periodic table
    struct Element table[20];
    initPeriodicTable(table);

    // Add some example elements to the table
    addElement(table, 1, "H", "Hydrogen", 1.008);
    addElement(table, 2, "He", "Helium", 4.003);

    // Ask the user for an element symbol
    char symbol[3];
    printf("Enter an element symbol: ");
    scanf("%s", symbol);

    // Search for the element in the periodic table
    int atomicNumber = searchElement(table, symbol);

    // Print the result to the user
    if (atomicNumber == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found: %s (atomic number %d)\n", table[atomicNumber-1].name, atomicNumber);
    }

    return 0;
}