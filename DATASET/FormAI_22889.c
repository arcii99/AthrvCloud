//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <string.h>

#define ROWS 9
#define COLUMNS 44

void printAsciiArt(char word[]) {
    char asciiArt[ROWS][COLUMNS];
    memset(asciiArt, ' ', ROWS * COLUMNS);
    
    int letterCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            
            // calculate letter column
            int letterColumn = (j % 10) + (letterCount * 11);
            
            // add letter to ascii array
            if (j >= letterColumn && j < letterColumn + 8) {
                int rowInLetter = i - ((ROWS - 8) / 2);
                if (rowInLetter >= 0 && rowInLetter < 8) {
                    asciiArt[i][j] = word[letterCount * 8 + rowInLetter];
                } else {
                    asciiArt[i][j] = ' ';
                }
            }
        }
        if ((i + 1) % 8 == 0) {
            letterCount++;
        }
    }
    
    // print ascii art
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char word[] = "ASCII ART";
    printAsciiArt(word);
    return 0;
}