//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert hexadecimal color code to RGB
void hexToRGB(char hexCode[], int *red, int *green, int *blue) {
    sscanf(hexCode, "#%02x%02x%02x", red, green, blue);
}

//function to convert RGB color code to hexadecimal
void RGBtoHex(int red, int green, int blue, char hexCode[]) {
    sprintf(hexCode, "#%02x%02x%02x", red, green, blue);
}

int main() {
    int red = 0, green = 0, blue = 0;
    char hexCode[7], choice;

    printf("Welcome to Color Code Converter!\n");
    printf("1. Hexadecimal to RGB\n");
    printf("2. RGB to Hexadecimal\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);

    switch(choice) {
        case '1':
            printf("Enter hexadecimal color code (without # symbol): ");
            scanf("%s", hexCode);
            hexToRGB(hexCode, &red, &green, &blue);
            printf("RGB code: %d,%d,%d", red, green, blue);
            break;

        case '2':
            printf("Enter RGB color code (separated by commas): ");
            scanf("%d,%d,%d", &red, &green, &blue);
            RGBtoHex(red, green, blue, hexCode);
            printf("Hexadecimal code: %s", hexCode);
            break;

        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}