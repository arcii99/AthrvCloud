//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

char* ART_SYMBOLS = "@%#*+=-:. ";

int main()
{
    char input[MAX_WIDTH*MAX_HEIGHT];
    int width, height, i, j, symbol_index, pixel_value;

    // get input string and dimensions
    printf("Enter a string of text: ");
    fgets(input, MAX_WIDTH*MAX_HEIGHT, stdin);
    printf("Enter the width of your output (maximum %d): ", MAX_WIDTH);
    scanf("%d", &width);

    // calculate height based on input size and width
    height = strlen(input) / width;

    // initialize output array
    char output[MAX_HEIGHT][MAX_WIDTH+1];

    // loop through input string and convert characters to ASCII art symbols
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            symbol_index = (int)(((float)input[i*width+j] / 127.0) * 9.0);
            output[i][j] = ART_SYMBOLS[symbol_index];
        }
        output[i][j] = '\0';
    }

    // print the final output
    for (i = 0; i < height; i++) {
        printf("%s\n", output[i]);
    }

    return 0;
}