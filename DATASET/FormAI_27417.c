//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>

int main() {
    int red, green, blue;
    char color[20];

    printf("Enter Color in HEX Code: ");
    scanf("#%02X%02X%02X", &red, &green, &blue);

    printf("\nRGB Code is: %d, %d, %d", red, green, blue);

    printf("\nEnter a color name: ");
    scanf("%s", color);

    printf("\n%s in HEX code is: #%02X%02X%02X", color, red, green, blue);
    return 0;
}