//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the number of elements in each row and column
#define ROWS 5
#define COLS 14

// Define structure for element data with name, symbol, atomic number, and group number
typedef struct {
    char name[20];
    char symbol[3];
    int atomicNum;
    int groupNum;
} Element;

// Define global variable for the periodic table array with 5 rows and 14 columns
Element periodicTable[ROWS][COLS];

// Function to initialize the periodic table with element data
void initializePeriodicTable() {
    // Row 1
    strcpy(periodicTable[0][0].name, "Hydrogen");
    strcpy(periodicTable[0][0].symbol, "H");
    periodicTable[0][0].atomicNum = 1;
    periodicTable[0][0].groupNum = 1;

    strcpy(periodicTable[0][1].name, "Helium");
    strcpy(periodicTable[0][1].symbol, "He");
    periodicTable[0][1].atomicNum = 2;
    periodicTable[0][1].groupNum = 18;

    // Row 2
    strcpy(periodicTable[1][0].name, "Lithium");
    strcpy(periodicTable[1][0].symbol, "Li");
    periodicTable[1][0].atomicNum = 3;
    periodicTable[1][0].groupNum = 1;

    strcpy(periodicTable[1][1].name, "Beryllium");
    strcpy(periodicTable[1][1].symbol, "Be");
    periodicTable[1][1].atomicNum = 4;
    periodicTable[1][1].groupNum = 2;

    strcpy(periodicTable[1][12].name, "Carbon");
    strcpy(periodicTable[1][12].symbol, "C");
    periodicTable[1][12].atomicNum = 6;
    periodicTable[1][12].groupNum = 14;

    strcpy(periodicTable[1][13].name, "Nitrogen");
    strcpy(periodicTable[1][13].symbol, "N");
    periodicTable[1][13].atomicNum = 7;
    periodicTable[1][13].groupNum = 15;

    // Row 3
    strcpy(periodicTable[2][0].name, "Sodium");
    strcpy(periodicTable[2][0].symbol, "Na");
    periodicTable[2][0].atomicNum = 11;
    periodicTable[2][0].groupNum = 1;

    strcpy(periodicTable[2][12].name, "Oxygen");
    strcpy(periodicTable[2][12].symbol, "O");
    periodicTable[2][12].atomicNum = 8;
    periodicTable[2][12].groupNum = 16;

    strcpy(periodicTable[2][13].name, "Fluorine");
    strcpy(periodicTable[2][13].symbol, "F");
    periodicTable[2][13].atomicNum = 9;
    periodicTable[2][13].groupNum = 17;

    // Row 4
    strcpy(periodicTable[3][0].name, "Potassium");
    strcpy(periodicTable[3][0].symbol, "K");
    periodicTable[3][0].atomicNum = 19;
    periodicTable[3][0].groupNum = 1;

    strcpy(periodicTable[3][1].name, "Calcium");
    strcpy(periodicTable[3][1].symbol, "Ca");
    periodicTable[3][1].atomicNum = 20;
    periodicTable[3][1].groupNum = 2;

    strcpy(periodicTable[3][12].name, "Chlorine");
    strcpy(periodicTable[3][12].symbol, "Cl");
    periodicTable[3][12].atomicNum = 17;
    periodicTable[3][12].groupNum = 17;

    // Row 5
    strcpy(periodicTable[4][0].name, "Copper");
    strcpy(periodicTable[4][0].symbol, "Cu");
    periodicTable[4][0].atomicNum = 29;
    periodicTable[4][0].groupNum = 11;

    strcpy(periodicTable[4][1].name, "Zinc");
    strcpy(periodicTable[4][1].symbol, "Zn");
    periodicTable[4][1].atomicNum = 30;
    periodicTable[4][1].groupNum = 12;

    strcpy(periodicTable[4][2].name, "Bromine");
    strcpy(periodicTable[4][2].symbol, "Br");
    periodicTable[4][2].atomicNum = 35;
    periodicTable[4][2].groupNum = 17;

    strcpy(periodicTable[4][3].name, "Silver");
    strcpy(periodicTable[4][3].symbol, "Ag");
    periodicTable[4][3].atomicNum = 47;
    periodicTable[4][3].groupNum = 11;

    strcpy(periodicTable[4][6].name, "Gold");
    strcpy(periodicTable[4][6].symbol, "Au");
    periodicTable[4][6].atomicNum = 79;
    periodicTable[4][6].groupNum = 11;

    strcpy(periodicTable[4][7].name, "Mercury");
    strcpy(periodicTable[4][7].symbol, "Hg");
    periodicTable[4][7].atomicNum = 80;
    periodicTable[4][7].groupNum = 12;
}

// Function to print the periodic table with element data
void printPeriodicTable() {
    printf("\n");
    printf("   ---------------------------------------------------------------------------------------------------------------------\n");
    printf("  |                                                  PERIODIC TABLE                                                  |\n");
    printf("  |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |  1   |      H      |      He     |             |             |             |             |             |             |\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |  2   |      Li     |      Be     |             |             |             |      C      |      N      |      O      |\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |  3   |      Na     |             |             |             |             |             |             |      F      |\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |  4   |      K      |      Ca     |             |             |             |             |             |      Cl     |\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |-------------------------------------------------------------------------------------------------------------------|\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  |  5   |      Cu     |      Zn     |      Br     |      Ag     |             |      Au     |      Hg     |             |\n");
    printf("  |      |             |             |             |             |             |             |             |             |\n");
    printf("  ---------------------------------------------------------------------------------------------------------------------\n\n");

    // Loop through the rows and columns of the periodic table array to print the element data
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (strcmp(periodicTable[i][j].name, "") != 0) {
                printf("%-5s", periodicTable[i][j].symbol);
            } else {
                printf("     ");
            }
        }
        printf("\n");

        for (int j = 0; j < COLS; j++) {
            if (strcmp(periodicTable[i][j].name, "") != 0) {
                printf("%-5d", periodicTable[i][j].atomicNum);
            } else {
                printf("     ");
            }
        }
        printf("\n");

        for (int j = 0; j < COLS; j++) {
            if (strcmp(periodicTable[i][j].name, "") != 0) {
                printf("%-4s ", periodicTable[i][j].name);
            } else {
                printf("     ");
            }
        }
        printf("\n");

        for (int j = 0; j < COLS; j++) {
            if (strcmp(periodicTable[i][j].name, "") != 0) {
                printf("%-5d", periodicTable[i][j].groupNum);
            } else {
                printf("     ");
            }
        }
        printf("\n\n");
    }
}

int main() {
    initializePeriodicTable();
    printPeriodicTable();

    printf("Enter the symbol of an element to get its atomic number and group number: ");
    char symbol[3];
    scanf("%s", symbol);

    // Loop through the rows and columns of the periodic table array to find the element with the matching symbol
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (strcmp(periodicTable[i][j].symbol, symbol) == 0) {
                printf("%s has an atomic number of %d and is in group %d.\n", periodicTable[i][j].name, periodicTable[i][j].atomicNum, periodicTable[i][j].groupNum);
                return 0;
            }
        }
    }

    printf("Invalid symbol.\n");
    return 0;
}