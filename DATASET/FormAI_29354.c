//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the size of the ASCII art grid
#define ROWS 10
#define COLS 50

// define the size of the alphabet, including space character
#define ALPHABET_SIZE 27

// define the ASCII art for each letter of the alphabet
const char ASCII_ART[ALPHABET_SIZE][ROWS][COLS] = {
    // space character
    {
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  "
    },
    // letter A
    {
        "                                                  ",
        "           .o8        .o88o.                         ",
        "          \"888       888 `\"                         ",
        " .ooooo.   888oooo.  888ooo  ooo. .oo.    .ooooo.   ",
        "d88' `88b  d88' `88b 888    `\"888P\"Y88b  d88' `88b  ",
        "888ooo888  888ooo888 888      888   888  888ooo888  ",
        "888    .o  888    .o 888      888   888  888    .o  ",
        "`Y8bod8P'  `Y8bod8P' o888o     `Y8bod8P'  `Y8bod8P'  ",
        "                                                  ",
        "                                                  "
    },
    // letter B
    {
        "                                                  ",
        "oooooooooo.                                          ",
        "`888'   `Y8b                                         ",
        " 888      888 ooo. .oo.  .oo.   oo.ooooo.   .oooo.o ",
        " 888      888 `888P\"Y88bP\"Y88b   888' `88b d88(  \"8 ",
        " 888      888  888   888   888   888   888 `\"Y88b.  ",
        "o888o    o888o 888   888   888o  888bod8P' o.  )88b ",
        "                              888                  ",
        "                         .o. 88P                  ",
        "                         `Y888P                    "
    },
    // add additional letters of the alphabet here
    // ...
};

// function to convert a text string to ASCII art
void text_to_ascii_art(const char* text) {
    int length = strlen(text);
    char output[ROWS][length * COLS];

    // loop through each row of the ASCII art grid
    for (int i = 0; i < ROWS; i++) {
        // loop through each character of the input text
        for (int j = 0; j < length; j++) {
            // determine the ASCII art for the current character
            char character = text[j];
            int index = 0;
            if (character >= 'A' && character <= 'Z') {
                index = character - 'A' + 1;
            }
            // add the ASCII art for the current character to the output grid
            for (int k = 0; k < COLS; k++) {
                output[i][j * COLS + k] = ASCII_ART[index][i][k];
            }
        }
    }

    // output the ASCII art to the console
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < length * COLS; j++) {
            printf("%c", output[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // get user input for the text to convert to ASCII art
    char input[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("\n");
    text_to_ascii_art(input);

    return 0;
}