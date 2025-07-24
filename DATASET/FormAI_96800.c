//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void convertToDecimal(int r, int g, int b);
void convertToHexadecimal(int r, int g, int b);

int main() {
    int r, g, b;

    printf("Enter the red value (0-255): ");
    scanf("%d", &r);

    printf("Enter the green value (0-255): ");
    scanf("%d", &g);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &b);

    printf("Choose the conversion method:\n");
    printf("1. RGB to Decimal\n");
    printf("2. RGB to Hexadecimal\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        convertToDecimal(r, g, b);
    } else if (choice == 2) {
        convertToHexadecimal(r, g, b);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

void convertToDecimal(int r, int g, int b) {
    printf("Decimal value of RGB(%d,%d,%d) is (%d,%d,%d)\n", r, g, b, r, g, b);
}

void convertToHexadecimal(int r, int g, int b) {
    char hex[7];
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    printf("Hexadecimal value of RGB(%d,%d,%d) is %s\n", r, g, b, hex);
}