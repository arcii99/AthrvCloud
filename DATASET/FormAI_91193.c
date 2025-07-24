//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>

typedef union {
    unsigned int value;
    struct {
        unsigned char r, g, b;
    } components;
} color_t;

void rgb_to_hex(color_t *color) {
    printf("RGB to Hex Converter\n\n");
    printf("Enter Red (0-255): ");
    scanf("%hhu", &color->components.r);
    printf("Enter Green (0-255): ");
    scanf("%hhu", &color->components.g);
    printf("Enter Blue (0-255): ");
    scanf("%hhu", &color->components.b);
    printf("\n");
    printf("Hex Value: #%02X%02X%02X\n", color->components.r, color->components.g, color->components.b);
}

void hex_to_rgb(color_t *color) {
    printf("Hex to RGB Converter\n\n");
    char hex[7];
    printf("Enter Hex Value: ");
    scanf("%s", hex);
    sscanf(hex, "%02hhX%02hhX%02hhX", &color->components.r, &color->components.g, &color->components.b);
    printf("\n");
    printf("Red: %d\n", color->components.r);
    printf("Green: %d\n", color->components.g);
    printf("Blue: %d\n", color->components.b);
}

int main() {
    color_t color;
    int choice;
    do {
        printf("1. RGB to Hex\n");
        printf("2. Hex to RGB\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                rgb_to_hex(&color);
                break;
            case 2:
                hex_to_rgb(&color);
                break;
            case 0:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        printf("\n");
    } while (choice != 0);
    return 0;
}