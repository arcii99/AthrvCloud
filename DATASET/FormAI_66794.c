//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the size of the ASCII art character matrix
#define MAX_ROW 12
#define MAX_COL 60

// define the default ascii art character
#define DEFAULT_CHAR '#'

// global 2D character matrix to store the ASCII art character
char characterMatrix[MAX_ROW][MAX_COL];

// function to print the character matrix
void printMatrix() {
    for (int i=0; i<MAX_ROW; i++) {
        for (int j=0; j<MAX_COL; j++) {
            printf("%c", characterMatrix[i][j]);
        }
        printf("\n");
    }
}

// function to generate the ASCII art character matrix
void generateMatrix(char *inputString) {
    // convert the input string into ASCII values
    int len = strlen(inputString);
    int asciiVals[MAX_COL];

    for (int i=0; i<len; i++) {
        asciiVals[i] = (int) inputString[i];
    }

    // initialize the character matrix with default value
    for (int i=0; i<MAX_ROW; i++) {
        for (int j=0; j<MAX_COL; j++) {
            characterMatrix[i][j] = DEFAULT_CHAR;
        }
    }

    // generate the ASCII art character matrix
    for (int i=0; i<len; i++) {
        int asciiVal = asciiVals[i];

        if (asciiVal == 32) {
            // handle space character
            for (int j=0; j<MAX_ROW; j++) {
                characterMatrix[j][i] = ' ';
            }
        } else {
            // generate the ASCII art character for non-space characters
            int rowIndex, colIndex;
            int startVal;

            if (asciiVal >= 48 && asciiVal <= 57) {
                // handle numeric characters
                rowIndex = 0;
                colIndex = (asciiVal - 48) * 5;
                startVal = asciiVal;
            } else if (asciiVal >= 65 && asciiVal <= 90) {
                // handle upper-case alphabets
                rowIndex = 1;
                colIndex = (asciiVal - 65) * 5;
                startVal = asciiVal + 32;
            } else if (asciiVal >= 97 && asciiVal <= 122) {
                // handle lower-case alphabets
                rowIndex = 7;
                colIndex = (asciiVal - 97) * 5;
                startVal = asciiVal;
            } else {
                // handle special characters
                rowIndex = 10;
                colIndex = (asciiVal - 33) * 5;
                startVal = asciiVal;
            }

            // copy the corresponding ASCII art character to the character matrix
            for (int j=rowIndex; j<rowIndex+5; j++) {
                int charVal = startVal;

                for (int k=colIndex; k<colIndex+5; k++) {
                    characterMatrix[j][k] = charVal;
                    charVal++;
                }

                startVal += 16;
            }
        }
    }
}

int main() {
    // get the input string from user
    char inputString[100];
    printf("Enter a string:\n");
    fgets(inputString, sizeof(inputString), stdin);

    // generate the ASCII art character matrix
    generateMatrix(inputString);

    // print the character matrix
    printMatrix();

    return 0;
}