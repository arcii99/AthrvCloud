//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for the periodic table
struct element {
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicMass;
};

// Define function to add elements to the periodic table
void addElement(struct element pTable[], int index, char symbol[3], char name[20], int atomicNumber, float atomicMass) {
    strcpy(pTable[index].symbol, symbol);
    strcpy(pTable[index].name, name);
    pTable[index].atomicNumber = atomicNumber;
    pTable[index].atomicMass = atomicMass;
}

// Define function to get a random element from the periodic table
struct element getRandomElement(struct element pTable[]) {
    int randomIndex = rand() % 118;
    return pTable[randomIndex];
}

// Define function to print out the periodic table
void printTable(struct element pTable[]) {
    printf("Symbol\tName\t\tAtomic Number\tAtomic Mass\n");
    for (int i = 0; i < 118; i++) {
        printf("%s\t%s\t\t%d\t\t%.4f\n", pTable[i].symbol, pTable[i].name, pTable[i].atomicNumber, pTable[i].atomicMass);
    }
}

// Define main function
int main() {
    // Create array to hold periodic table elements
    struct element pTable[118];

    // Add elements to the periodic table
    addElement(pTable, 0, "H", "Hydrogen", 1, 1.008);
    addElement(pTable, 1, "He", "Helium", 2, 4.003);
    addElement(pTable, 2, "Li", "Lithium", 3, 6.939);
    addElement(pTable, 3, "Be", "Beryllium", 4, 9.012);
    // Add rest of elements ...

    // Print out the periodic table
    printTable(pTable);

    // Get a random element from the periodic table
    struct element randomElement = getRandomElement(pTable);

    // Ask user to guess the symbol of the random element
    printf("\nGuess the symbol of the element with the atomic number %d: ", randomElement.atomicNumber);

    // Get user input
    char guessSymbol[3];
    scanf("%s", guessSymbol);

    // Check if guess is correct
    if (strcmp(guessSymbol, randomElement.symbol) == 0) {
        printf("Correct! The element was %s.\n", randomElement.name);
    }
    else {
        printf("Sorry, that was incorrect. The element was %s.\n", randomElement.name);
    }

    return 0;
}