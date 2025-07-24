//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char hex[7] = "#000000"; // assume default color is Black
    int red, green, blue;

    printf("Welcome to the Color Code Converter\n\n");
    printf("Please select an option:\n");
    printf("1. Convert RGB to Hex Code\n");
    printf("2. Convert Hex Code to RGB\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the Red, Green, and Blue values (0-255):\n");
            scanf("%d %d %d", &red, &green, &blue);
            sprintf(hex, "#%02X%02X%02X", red, green, blue);
            printf("The Hex code is %s\n", hex);
            break;

        case 2:
            printf("Enter the Hex code (including the '#' symbol):\n");
            scanf("%s", hex);
            sscanf(hex, "#%02X%02X%02X", &red, &green, &blue);
            printf("The RGB values are (%d,%d,%d)\n", red, green, blue);
            break;

        case 3:
            printf("Thanks for using the Color Code Converter!\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}