//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int rows, int columns) {
    int pixels[rows][columns];
    srand(time(NULL)); // Initializing random number generator

    // Generating random pixel art matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            pixels[i][j] = rand() % 2; // Assigning random 0 or 1
        }
    }

    // Printing pixel art
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (pixels[i][j] == 0) {
                printf("."); // Displaying "." for "off" pixels
            } else {
                printf("#"); // Displaying "#" for "on" pixels
            }
        }
        printf("\n"); // Moving to next line
    }
}

int main() {
    int rows, columns;

    printf("Welcome to the Pixel Art Generator!\n");

    do {
        printf("Enter number of rows (5-20): ");
        scanf("%d", &rows);
    } while (rows < 5 || rows > 20); // Validating rows input

    do {
        printf("Enter number of columns (5-20): ");
        scanf("%d", &columns);
    } while (columns < 5 || columns > 20); // Validating columns input

    generatePixelArt(rows, columns); // Generating and displaying pixel art

    return 0;
}