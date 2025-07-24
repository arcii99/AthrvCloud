//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

void convertToArt(char message[]) {
    char asciiArt[ROWS][COLUMNS];
    int i, j, messageIndex = 0;

    // Initialize the asciiArt array
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            asciiArt[i][j] = ' ';
        }
    }

    // Fill the asciiArt array with the message
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (message[messageIndex] != '\0') {
                asciiArt[i][j] = message[messageIndex];
                messageIndex++;
            }
        }
    }

    // Print the asciiArt array
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char message[] = "TEXT TO ASCII ART";
    convertToArt(message);
    return 0;
}