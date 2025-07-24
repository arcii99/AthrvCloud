//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// define a structure to represent an element in the periodic table
typedef struct {
    int atomicNumber;
    char symbol[3];
    char name[20];
    float atomicMass;
} Element;

// define a function to initialize an element with given values
void createElement(Element *element, int atomicNumber, char symbol[], char name[], float atomicMass) {
    element->atomicNumber = atomicNumber;
    strcpy(element->symbol, symbol);
    strcpy(element->name, name);
    element->atomicMass = atomicMass;
}

// define an array of elements
Element periodicTable[MAX_ELEMENTS];

// define a function to initialize the periodic table with elements
void initializePeriodicTable() {
    createElement(&periodicTable[0], 1, "H", "Hydrogen", 1.008);
    createElement(&periodicTable[1], 2, "He", "Helium", 4.003);
    // add more elements here...
}

// define a function to search for an element by symbol
Element* findElementBySymbol(char symbol[]) {
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(periodicTable[i].symbol, symbol) == 0) {
            return &periodicTable[i];
        }
    }
    return NULL;
}

// define a function to print an element's information
void printElementInfo(Element *element) {
    printf("Atomic number: %d\n", element->atomicNumber);
    printf("Symbol: %s\n", element->symbol);
    printf("Name: %s\n", element->name);
    printf("Atomic mass: %.3f\n", element->atomicMass);
}

// main function to run the quiz program
int main() {
    initializePeriodicTable();

    while (1) {
        char input[3]; // only need 2 characters for symbol input
        printf("Enter an element symbol (or 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        Element *element = findElementBySymbol(input);
        if (element == NULL) {
            printf("Error: Element not found.\n");
        } else {
            printf("Element found!\n");
            printElementInfo(element);
        }
    }
    
    return 0;
}