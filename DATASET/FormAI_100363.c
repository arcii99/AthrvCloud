//FormAI DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 10

// Function to convert hex digit to integer
int hexToDec(char hexDigit)
{
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    }
    else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    }
    else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    }
    else {
        return -1;
    }
}

// Function to convert RGB values to hex string
void rgbToHex(int red, int green, int blue, char hexString[])
{
    sprintf(hexString, "#%02X%02X%02X", red, green, blue);
}

// Function to convert hex string to RGB values
void hexToRgb(char hexString[], int *red, int *green, int *blue)
{
    // Check if string starts with #
    if (hexString[0] != '#') {
        printf("Error: Invalid hex string\n");
        return;
    }

    // Check if string has correct length
    if (strlen(hexString) != 7) {
        printf("Error: Invalid hex string\n");
        return;
    }

    // Convert hex string to RGB values
    *red = hexToDec(hexString[1]) * 16 + hexToDec(hexString[2]);
    *green = hexToDec(hexString[3]) * 16 + hexToDec(hexString[4]);
    *blue = hexToDec(hexString[5]) * 16 + hexToDec(hexString[6]);
}

int main()
{
    // Variables for user input and output
    char input[MAX_STRING_LENGTH];
    char output[MAX_STRING_LENGTH];
    int red, green, blue;

    // Infinite loop to allow user to convert multiple colors
    while (1) {
        // Print menu options
        printf("Choose an option:\n");
        printf("1. Convert RGB values to hex string\n");
        printf("2. Convert hex string to RGB values\n");
        printf("3. Exit program\n");

        // Get user input
        printf("Enter your choice: ");
        fgets(input, MAX_STRING_LENGTH, stdin);
        int choice = atoi(input);

        // Perform selected action
        switch (choice) {
            case 1:
                // Get user input
                printf("Enter red value (0-255): ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                red = atoi(input);

                printf("Enter green value (0-255): ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                green = atoi(input);

                printf("Enter blue value (0-255): ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                blue = atoi(input);

                // Convert RGB values to hex string
                rgbToHex(red, green, blue, output);
                printf("Hex string: %s\n", output);
                break;

            case 2:
                // Get user input
                printf("Enter hex string (e.g. #FF0000): ");
                fgets(input, MAX_STRING_LENGTH, stdin);

                // Convert hex string to RGB values
                hexToRgb(input, &red, &green, &blue);
                printf("Red: %d\n", red);
                printf("Green: %d\n", green);
                printf("Blue: %d\n", blue);
                break;

            case 3:
                // Exit program
                printf("Goodbye!\n");
                exit(0);

            default:
                // Invalid input
                printf("Error: Invalid choice\n");
                break;
        }
    }

    return 0;
}