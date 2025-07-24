//FormAI DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// function to convert RGB values to HEX code
void RGB_to_HEX(int red, int green, int blue) {
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue); // converting to HEX code
    printf("The HEX code is : %s", hex);
}

// function to convert HEX code to RGB values
void HEX_to_RGB(char hex[]) {
    int red, green, blue;
    sscanf(hex, "#%02X%02X%02X", &red, &green, &blue); // converting to RGB values
    printf("The RGB values are : (%d, %d, %d)", red, green, blue);
}

int main() {
    char choice;
    printf("Choose an option: \n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    scanf("%c", &choice);

    if (choice == '1') {
        int red, green, blue;
        printf("Enter the RGB values (separated by spaces): ");
        scanf("%d %d %d", &red, &green, &blue);
        RGB_to_HEX(red, green, blue);
    } else if (choice == '2') {
        char hex[7];
        printf("Enter the HEX code: ");
        scanf("%s", hex);
        HEX_to_RGB(hex);
    } else {
        printf("Invalid choice!");
        exit(0);
    }
    return 0;
}