//FormAI DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void rgb_to_hex(int red, int green, int blue);
void hex_to_rgb(char *hex);

int main() {
    int choice;
    printf("Welcome to the color code converter!\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            int red, blue, green;
            printf("Enter the RGB values (0-255): ");
            scanf("%d %d %d", &red, &green, &blue);
            rgb_to_hex(red, green, blue);
            break;
        }
        case 2: {
            char hex[7];
            printf("Enter the hex code (without #): ");
            scanf("%s", hex);
            hex_to_rgb(hex);
            break;
        }
        default:
            printf("Invalid choice!");
            break;
    }
    return 0;
}

void rgb_to_hex(int red, int green, int blue) {
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    printf("Hex code: %s\n", hex);
}

void hex_to_rgb(char *hex) {
    int red, green, blue;
    sscanf(hex, "%02X%02X%02X", &red, &green, &blue);
    printf("RGB values: (%d,%d,%d)\n", red, green, blue);
}