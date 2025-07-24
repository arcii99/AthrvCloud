//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    char hex[7];
    int choice;

    printf("Enter 1 to convert from RGB to HEX\nEnter 2 to convert from HEX to RGB\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter value of red: ");
        scanf("%d", &red);
        printf("Enter value of green: ");
        scanf("%d", &green);
        printf("Enter value of blue: ");
        scanf("%d", &blue);

        sprintf(hex, "#%02x%02x%02x", red, green, blue); // Using sprintf to convert RGB values to HEX format
        printf("Hex code: %s\n", hex);
    } else if (choice == 2) {
        printf("Enter hex code: ");
        scanf("%s", hex);

        red = strtol(hex+1, NULL, 16) >> 16; // using strtol to convert HEX to RGB values
        green = strtol(hex+3, NULL, 16) >> 8;
        blue = strtol(hex+5, NULL, 16);

        printf("RGB values: (%d,%d,%d)", red, green, blue);
    } else {
        printf("Invalid choice");
        return 0;
    }
    return 0;
}