//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter the color code you would like to convert.\n");
    
    char input[10];
    scanf("%s", input);

    if (strlen(input) != 6)
    {
        printf("Invalid color code entered. Please enter a valid 6-digit color code.\n");
        return 1;
    }

    char red[3];
    char green[3];
    char blue[3];
    
    strncpy(red, input, 2);
    strncpy(green, input+2, 2);
    strncpy(blue, input+4, 2);

    red[2] = green[2] = blue[2] = '\0';

    int r = strtol(red, NULL, 16);
    int g = strtol(green, NULL, 16);
    int b = strtol(blue, NULL, 16);

    printf("Your color in RGB is (%d, %d, %d)\n", r, g, b);
    printf("Congratulations! You have successfully converted your code. Have a nice day!\n");

    return 0;
}