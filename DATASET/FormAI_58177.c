//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define ART_DIMENSION 8
#define NUM_CHARS 95

char ascii_chars[NUM_CHARS][ART_DIMENSION][ART_DIMENSION] =
{
// ASCII art characters
{"        ",
 "  ____  ",
 " /    \\ ",
 "|      |",
 " \\    / ",
 "  \\__/  ",
 "        ",
 "        "},

{"         ",
 "  /\\/\\   ",
 " /    \\  ",
 "/ /\\/\\ \\ ",
 "\\ \\    / ",
 " \\/_/\\_\\",
 "         ",
 "         "},

{"     ",
 " __  ",
 "|__| ",
 "|  | ",
 "|  | ",
 "|__| ",
 "     ",
 "     "},

// Add more characters here

};

char* text_to_ascii(char* text)
{
    int art_width = strlen(text) * (ART_DIMENSION + 1); // +1 for space between characters
    char* ascii_art = malloc(sizeof(char) * (MAX_LINE_LENGTH + 1) * ART_DIMENSION);
    char line[MAX_LINE_LENGTH + 1];
    int row, col, i, j;

    // Initialize ascii_art string to empty
    strcpy(ascii_art, "");

    // Loop through each row of each character, append to ascii_art string
    for (row = 0; row < ART_DIMENSION; row++) 
    {
        strcpy(line, "");
        for (i = 0; i < strlen(text); i++) 
        {
            int ascii_index = text[i] - 32; // ASCII code - 32 = index in ascii_chars array
            if (ascii_index < 0 || ascii_index >= NUM_CHARS) ascii_index = 94; // use default '_' character
            for (col = 0; col < ART_DIMENSION; col++) 
            {
                line[(i * (ART_DIMENSION + 1)) + col] = ascii_chars[ascii_index][row][col];
            }
            line[(i * (ART_DIMENSION + 1)) + ART_DIMENSION] = ' '; // space between characters
        }
        line[art_width] = '\0';
        strcat(ascii_art, line);
        strcat(ascii_art, "\n"); // add line break
    }

    return ascii_art;
}

int main() 
{
    char* text = "ASCII ART";
    char* ascii_art = text_to_ascii(text);

    printf("%s", ascii_art);

    free(ascii_art); // remember to free dynamically allocated memory

    return 0;
}