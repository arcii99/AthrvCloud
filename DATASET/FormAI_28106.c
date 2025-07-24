//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char hex[7];
    int r, g, b;

    printf("Welcome to the C Color Code Converter!\n");
    printf("Please select your input type:\n");
    printf("1. RGB\n");
    printf("2. Hexadecimal\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Please enter your RGB values (separated by spaces): ");
        scanf("%d %d %d", &r, &g, &b);

        sprintf(hex, "#%02X%02X%02X", r, g, b);
        printf("Hexadecimal equivalent: %s\n", hex);
    } else if (choice == 2) {
        printf("Please enter your hexadecimal color code (without the #): ");
        scanf("%s", hex);

        r = (int)strtol(&hex[0], NULL, 16);
        g = (int)strtol(&hex[2], NULL, 16);
        b = (int)strtol(&hex[4], NULL, 16);

        printf("RGB equivalent: %d %d %d\n", r, g, b);
    } else {
        printf("Invalid choice. Please try again.\n");
        exit(1);
    }

    printf("Thanks for using the C Color Code Converter!\n");

    return 0;
}