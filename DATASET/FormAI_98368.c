//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void convertColor();
void hexToRgb();
void rgbToHex();

int main()
{
    int choice = 0;
    while (choice != 3) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                hexToRgb();
                break;
            case 2:
                rgbToHex();
                break;
            case 3:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\n===== Color Code Converter =====\n");
    printf("1. Convert HEX to RGB\n");
    printf("2. Convert RGB to HEX\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
}

void convertColor(char* hexCode, int* red, int* green, int* blue) {
    sscanf(hexCode, "#%02x%02x%02x", red, green, blue);
}

void hexToRgb() {
    char hexCode[7];
    int red, green, blue;

    printf("\nEnter a HEX color code (format: #RRGGBB): ");
    scanf("%6s", hexCode);

    convertColor(hexCode, &red, &green, &blue);

    printf("\nRGB color code for %s is (%d,%d,%d)\n", hexCode, red, green, blue);
}

void rgbToHex() {
    int red, green, blue;
    char hexCode[7];

    printf("\nEnter the RGB color code (format: R,G,B): ");
    scanf("%d,%d,%d", &red, &green, &blue);

    sprintf(hexCode, "#%02X%02X%02X", red, green, blue);

    printf("\nHEX color code for (%d,%d,%d) is %s\n", red, green, blue, hexCode);
}