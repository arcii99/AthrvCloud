//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    char hex[7];

    printf("Enter RGB values (0-255): ");
    scanf("%d %d %d", &red, &green, &blue);

    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        printf("Invalid RGB values.\n");
        exit(0);
    }

    sprintf(hex, "%02X%02X%02X", red, green, blue);

    printf("Hex Code: #%s\n", hex);
    return 0;
}