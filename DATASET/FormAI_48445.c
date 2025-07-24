//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

int main() {
    char hex[6];
    printf("Enter a Hex Code (e.g. #FF5733): ");
    scanf("%s", hex);
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    float red = (float) r / 255;
    float green = (float) g / 255;
    float blue = (float) b / 255;
    printf("Red: %.2f\n", red);
    printf("Green: %.2f\n", green);
    printf("Blue: %.2f\n", blue);

    return 0;
}