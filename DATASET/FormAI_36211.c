//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program converts color codes from hexadecimal to RGB and vice versa */

/* Function prototypes */
void hexToRgb(char* hexCode);
void rgbToHex(int r, int g, int b);

int main()
{
    int choice;
    char hexCode[7];

    printf("Welcome to the Color Code Converter!\n\n");
    printf("Please select an option:\n");
    printf("1. Convert hexadecimal to RGB\n");
    printf("2. Convert RGB to hexadecimal\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter the hexadecimal color code: ");
            scanf("%s", &hexCode);
            hexToRgb(hexCode);
            break;

        case 2:
            int r, g, b;
            printf("\nEnter red value (0-255): ");
            scanf("%d", &r);
            printf("Enter green value (0-255): ");
            scanf("%d", &g);
            printf("Enter blue value (0-255): ");
            scanf("%d", &b);
            rgbToHex(r, g, b);
            break;

        default:
            printf("Invalid option.");
            break;
    }

    return 0;
}

/* Function to convert hexadecimal to RGB */
void hexToRgb(char* hexCode)
{
    int r, g, b;
    sscanf(hexCode, "%02x%02x%02x", &r, &g, &b);
    printf("\nThe RGB values are: %d, %d, %d\n", r, g, b);
}

/* Function to convert RGB to hexadecimal */
void rgbToHex(int r, int g, int b)
{
    char hexCode[7];
    sprintf(hexCode, "#%02x%02x%02x", r, g, b);
    printf("\nThe hexadecimal color code is: %s\n", hexCode);
}