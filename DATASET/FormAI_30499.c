//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define the maximum number of characters in an element name and abbreviation
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

// Define a struct for elements in the periodic table
typedef struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
    float atomicWeight;
} Element;

// Define a function to display the periodic table based on the provided elements
void displayPeriodicTable(Element elements[], int numElements) {
    printf("%-3s %-18s %-4s %s\n", "No", "Name", "Sym", "Weight");
    printf("--- ------------------ ---- ------\n");
    for (int i = 0; i < numElements; i++) {
        printf("%-3d %-18s %-4s %.4f\n", elements[i].atomicNumber, elements[i].name,
            elements[i].symbol, elements[i].atomicWeight);
    }
}

// Define a function to prompt the user for an element abbreviation and return the element
Element getElementBySymbol(Element elements[], int numElements, char symbol[]) {
    for (int i = 0; i < numElements; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return elements[i];
        }
    }
    // If the symbol isn't found, return a default element with blank values
    Element defaultElement = {"", "", 0, 0.0};
    return defaultElement;
}

int main() {
    // Initialize the array of elements in the periodic table
    Element elements[MAX_ELEMENTS] = {
        {"Hydrogen", "H", 1, 1.008},
        {"Helium", "He", 2, 4.003},
        {"Lithium", "Li", 3, 6.941},
        {"Beryllium", "Be", 4, 9.012},
        {"Boron", "B", 5, 10.81},
        // More elements...
    };
    int numElements = 5; // Update the number of elements in the periodic table as needed

    // Display the periodic table
    displayPeriodicTable(elements, numElements);

    // Prompt the user for an element abbreviation and display the resulting element
    char symbol[MAX_SYMBOL_LENGTH];
    printf("Enter an element symbol: ");
    scanf("%2s", symbol);
    Element element = getElementBySymbol(elements, numElements, symbol);
    printf("Element found: %s, %s, atomic number %d, atomic weight %.4f\n", 
        element.name, element.symbol, element.atomicNumber, element.atomicWeight);

    return 0;
}