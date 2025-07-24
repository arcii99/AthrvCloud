//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 100

int main()
{
    // Declare and initialize variables
    char input[MAX_BUFFER];
    char output[MAX_BUFFER];
    int r, g, b;

    // Prompt user for input
    printf("Enter a color code in Hexadecimal format (#RRGGBB): ");
    fgets(input, MAX_BUFFER, stdin);

    // Remove trailing new line from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is valid
    if (strlen(input) != 7 || input[0] != '#')
    {
        printf("Invalid input format!");
        exit(1);
    }

    // Convert input to RGB values
    sscanf(input, "#%2x%2x%2x", &r, &g, &b);

    // Convert RGB values to output color code formats
    sprintf(output, "RGB(%d, %d, %d)", r, g, b);
    printf("Output color code in RGB format: %s\n", output);

    sprintf(output, "HSV(%d, %d, %d)", (int)((float)r / 255 * 360), (int)((float)g / 255 * 100), (int)((float)b / 255 * 100));
    printf("Output color code in HSV format: %s\n", output);

    sprintf(output, "CMYK(%d%%, %d%%, %d%%, %d%%)", (int)((float)(255 - r) / 255 * 100), (int)((float)(255 - g) / 255 * 100), (int)((float)(255 - b) / 255 * 100), 0);
    printf("Output color code in CMYK format: %s\n", output);

    return 0;
}