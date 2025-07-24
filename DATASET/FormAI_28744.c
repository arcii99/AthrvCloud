//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of color string
#define MAX_COLOR_LENGTH 8

void convertColorCode(char *color);
void printError(char *errorMsg);

int main(void)
{
    char color[MAX_COLOR_LENGTH];
    printf("Enter color code in HEX format (e.g. #FF0000): ");
    scanf("%s", color);
    convertColorCode(color);
    return 0;
}

void convertColorCode(char *color)
{
    // Check if the color code starts with #
    if (color[0] != '#')
    {
        printError("Invalid color code");
        return;
    }

    // Check if the color code contains exactly six hex digits
    if (strlen(color) != 7)
    {
        printError("Invalid color code");
        return;
    }

    // Convert the hexadecimal values to decimal values
    unsigned int red = strtol(&color[1], NULL, 16);
    unsigned int green = strtol(&color[3], NULL, 16);
    unsigned int blue = strtol(&color[5], NULL, 16);

    // Print the RGB values
    printf("The RGB values are: %u %u %u\n", red, green, blue);
}

void printError(char *errorMsg)
{
    printf("Error: %s\n", errorMsg);
}