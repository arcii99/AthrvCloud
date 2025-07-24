//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 15
#define COLS 40

// Function to generate ASCII art using random characters
void surrealASCII(char ascii[ROWS][COLS]) {
    int i, j;
    char ch;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // Assign random characters to each cell
            ch = (char)(rand() % 94 + 32);
            ascii[i][j] = ch;
        }
    }
}

// Function to display the generated ASCII art
void displayASCII(char ascii[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char ascii[ROWS][COLS];
    surrealASCII(ascii);
    displayASCII(ascii);
    return 0;
}