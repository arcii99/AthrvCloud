//FormAI DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>

int main(void) {
    int red, green, blue, hexValue;

    printf("Enter RGB code (separated by spaces): ");
    scanf("%d %d %d", &red, &green, &blue);

    hexValue = (red << 16) + (green << 8) + blue;

    printf("Hex Code: #%06X\n", hexValue);

    return 0;
}