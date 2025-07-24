//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, g, b;
    char hex[7];

    printf("Enter RGB color values, range [0, 255]:\n");
    printf("Red: ");
    scanf("%d", &r);

    printf("Green: ");
    scanf("%d", &g);

    printf("Blue: ");
    scanf("%d", &b);

    // convert RGB to hex
    sprintf(hex, "%02x%02x%02x", r, g, b);

    printf("RGB: (%d, %d, %d)\n", r, g, b);
    printf("Hex: #");
    puts(hex);

    return 0;
}