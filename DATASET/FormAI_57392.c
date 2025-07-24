//FormAI DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>

int main(void) {

    int choice;
    char hexCode[8];
    int r, g, b;

    printf("=== Post-Apocalyptic Color Code Converter ===\n");
    printf("Enter 1 for RGB to Hex Conversion\nEnter 2 for Hex to RGB Conversion\nChoice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nEnter the Red, Green, Blue values separated by space: ");
        scanf("%d %d %d", &r, &g, &b);

        printf("\nThe hex code equivalent is #%02x%02x%02x\n", r, g, b);

    } else if(choice == 2) {
        printf("\nEnter the hex code (format: #RRGGBB): ");
        scanf("%s", hexCode);

        sscanf(hexCode, "#%2x%2x%2x", &r, &g, &b);
        printf("\nThe R value is %d, G value is %d, and B value is %d\n", r, g, b);

    } else {
        printf("\nInvalid Choice\n");
    }
    return 0;
}