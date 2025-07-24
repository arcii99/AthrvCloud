//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the periodic table
void printPeriodicTable(char element[30]) {
    if (strcmp(element, "Hydrogen") == 0) {
        printf("H\nAtomic Number: 1\nAtomic Mass: 1.008\n");
    } else if (strcmp(element, "Helium") == 0) {
        printf("He\nAtomic Number: 2\nAtomic Mass: 4.003\n");
    } else if (strcmp(element, "Lithium") == 0) {
        printf("Li\nAtomic Number: 3\nAtomic Mass: 6.941\n");
    } else if (strcmp(element, "Beryllium") == 0) {
        printf("Be\nAtomic Number: 4\nAtomic Mass: 9.012\n");
    } else if (strcmp(element, "Boron") == 0) {
        printf("B\nAtomic Number: 5\nAtomic Mass: 10.81\n");
    } else if (strcmp(element, "Carbon") == 0) {
        printf("C\nAtomic Number: 6\nAtomic Mass: 12.01\n");
    } else if (strcmp(element, "Nitrogen") == 0) {
        printf("N\nAtomic Number: 7\nAtomic Mass: 14.01\n");
    } else if (strcmp(element, "Oxygen") == 0) {
        printf("O\nAtomic Number: 8\nAtomic Mass: 16.00\n");
    } else if (strcmp(element, "Fluorine") == 0) {
        printf("F\nAtomic Number: 9\nAtomic Mass: 19.00\n");
    } else if (strcmp(element, "Neon") == 0) {
        printf("Ne\nAtomic Number: 10\nAtomic Mass: 20.18\n");
    } else {
        printf("Invalid element name.\n");
    }
}

int main() {
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter the name of an element to get its information: ");
    char element[30];
    scanf("%s", element);
    printPeriodicTable(element);
    return 0;
}