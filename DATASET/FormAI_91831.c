//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include <stdio.h>
#include <string.h>

// define maximum length of element name
#define MAX_NAME_LENGTH 20

// define maximum number of elements
#define MAX_ELEMENTS 118

// define structure for elements
struct Element {
    int atomicNumber;
    char symbol[3];
    char fullName[MAX_NAME_LENGTH];
    float atomicMass;
};

// function to create element
struct Element createElement(int atomicNumber, char *symbol, char *fullName, float atomicMass) {
    struct Element element;
    element.atomicNumber = atomicNumber;
    strcpy(element.symbol, symbol);
    strcpy(element.fullName, fullName);
    element.atomicMass = atomicMass;
    return element;
}

// function to display periodic table
void displayPeriodicTable(struct Element elements[]) {

    printf("\nPeriodic Table of Elements\n\n");
    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= 7; j++) {
            int index = (j - 1) * 18 + i;
            if (index <= MAX_ELEMENTS) {
                printf("%-3d", elements[index].atomicNumber);
            }
        }
        printf("\n");
        for (int j = 1; j <= 7; j++) {
            int index = (j - 1) * 18 + i;
            if (index <= MAX_ELEMENTS) {
                printf("%-3s", elements[index].symbol);
            }
        }
        printf("\n");
        for (int j = 1; j <= 7; j++) {
            int index = (j - 1) * 18 + i;
            if (index <= MAX_ELEMENTS) {
                printf("%-3s", elements[index].fullName);
            }
        }
        printf("\n");
        for (int j = 1; j <= 7; j++) {
            int index = (j - 1) * 18 + i;
            if (index <= MAX_ELEMENTS) {
                printf("%-5.2f", elements[index].atomicMass);
            }
        }
        printf("\n\n");
    }
}


int main() {

    // create all elements of the periodic table
    struct Element elements[MAX_ELEMENTS];
    elements[1] = createElement(1, "H", "Hydrogen", 1.008);
    elements[2] = createElement(2, "He", "Helium", 4.003);
    elements[3] = createElement(3, "Li", "Lithium", 6.941);
    elements[4] = createElement(4, "Be", "Beryllium", 9.012);
    // and so on...

    // display periodic table
    displayPeriodicTable(elements);

    return 0;
}