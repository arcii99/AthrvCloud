//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void getColor(int r, int g, int b) {
    printf("Entered RGB color code: (%d,%d,%d)\n", r, g, b);
    int hexValue = (r * (65536)) + (g * (256)) + b;
    printf("Hex Color Code: #%06X\n", hexValue);
}

int main() {
    int r, g, b;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter the RGB color code values (0-255):\n");

    printf("Red Value: ");
    scanf("%d", &r);

    printf("Green Value: ");
    scanf("%d", &g);

    printf("Blue Value: ");
    scanf("%d", &b);

    while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("The values should be between 0 and 255. Please try again.\n");

        printf("Red Value: ");
        scanf("%d", &r);

        printf("Green Value: ");
        scanf("%d", &g);

        printf("Blue Value: ");
        scanf("%d", &b);
    }

    getColor(r, g, b);

    printf("Thank you for using the Color Code Converter! Have a colorful day!\n");

    return 0;
}