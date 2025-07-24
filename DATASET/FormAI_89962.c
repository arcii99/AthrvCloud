//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal color code to RGB color code
void hexToRGB(char hexColorCode[], int *r, int *g, int *b)
{
    // Check if the color code starts with #, remove it if necessary
    if(hexColorCode[0] == '#')
    {
        memmove(hexColorCode, hexColorCode+1, strlen(hexColorCode));
    }

    // Convert the hex color code to RGB values
    sscanf(hexColorCode, "%02x%02x%02x", r, g, b);
}

// Function to convert RGB color code to hexadecimal color code
void RGBToHex(int r, int g, int b, char hexColorCode[])
{
    sprintf(hexColorCode, "#%02x%02x%02x", r, g, b);
}

// Main function
int main()
{
    int choice;
    char hexColorCode[7], newHexColorCode[7];
    int r, g, b;

    // Display the menu
    printf("Select an option:\n");
    printf("1. Convert hex color code to RGB color code.\n");
    printf("2. Convert RGB color code to hex color code.\n");
    printf("3. Exit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the desired operation
    switch(choice)
    {
        case 1:
            // Get the hex color code from the user
            printf("Enter the hex color code (without the # sign): ");
            scanf("%s", hexColorCode);

            // Convert the hex color code to RGB
            hexToRGB(hexColorCode, &r, &g, &b);

            // Display the RGB color code
            printf("The RGB color code for %s is %d,%d,%d\n", hexColorCode, r, g, b);
            break;

        case 2:
            // Get the RGB color code from the user
            printf("Enter the RGB color code (in the format r,g,b): ");
            scanf("%d,%d,%d", &r, &g, &b);

            // Convert the RGB color code to hex
            RGBToHex(r, g, b, newHexColorCode);

            // Display the hex color code
            printf("The hex color code for %d,%d,%d is %s\n", r, g, b, newHexColorCode);
            break;

        case 3:
            // Exit the program
            exit(0);

        default:
            // Invalid choice
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}