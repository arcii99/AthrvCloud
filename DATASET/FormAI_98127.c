//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define ROWS 8
#define COLS 8
#define MAX_LEN 100

void printArt(int table[ROWS][COLS], int len) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int k = j*len/COLS;
            if (table[i][k] >= ROWS - i) {
                putchar('#');
            } else {
                putchar(' ');
            }
            putchar(' ');
        }
        putchar('\n');
    }
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string to generate ASCII art: ");
    fgets(input, MAX_LEN, stdin);
    int table[ROWS][COLS] = { {3,4,5,6,7,6,5,4}, {3,4,5,6,7,6,5,4}, {2,3,4,5,6,5,4,3}, {1,2,3,4,5,4,3,2}, {0,1,2,3,2,1,0,1}, {0,1,2,1,0,1,2,3}, {0,1,0,1,2,3,4,5}, {1,0,1,2,3,4,5,6} }; // ASCII art data table
    int len = strlen(input) - 1; // exclude newline character
    printf("\nASCII ART OUTPUT FOR INPUT STRING: %s\n\n", input);
    printArt(table, len);
    return 0;
}