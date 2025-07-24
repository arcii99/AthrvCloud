//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int r, g, b;

    printf("Enter RGB values (0-255): \n");
    printf("Enter value for red: ");
    scanf("%d", &r);
    printf("Enter value for green: ");
    scanf("%d", &g);
    printf("Enter value for blue: ");
    scanf("%d", &b);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid input. RGB values must be between 0 and 255.\n");
        return 0;
    }

    int hex = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);

    printf("\nHexadecimal Color Code: #%06X\n", hex);

    return 0;
}