//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <string.h>

// define the size of ASCII art screen
#define ROWS 12
#define COLS 70 

// function to print the ASCII art
void printArt(char art[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", art[row][col]);
        }
        printf("\n");
    }
}

int main() {
    char input[50];
    
    // ask user to input a string
    printf("Enter a string (up to 50 characters): ");
    fgets(input, 50, stdin);
    
    // strip new line character from input
    input[strcspn(input, "\n")] = '\0';
    
    // initialize the ASCII art screen
    char art[ROWS][COLS] = {
        " _______________________________________________________________  ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|                                                               | ",
        "|_______________________________________________________________| "
    };
    
    // check if input is too long
    if (strlen(input) > 60) {
        printf("Error: Input string too long.\n");
        return 0;
    }
    
    // calculate starting position for input on ASCII art screen
    int startCol = COLS / 2 - strlen(input) / 2;
    int startRow = ROWS / 2 - 1;
    
    // insert input onto the ASCII art screen
    for (int i = 0; i < strlen(input); i++) {
        art[startRow][startCol + i] = input[i];
    }

    // print the resulting ASCII art
    printArt(art);
    
    return 0;
}