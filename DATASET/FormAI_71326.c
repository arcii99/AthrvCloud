//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hex[10];
    int r, g, b;

    printf("Enter a hex color code: ");
    scanf("%s", hex);

    // Convert hex to RGB
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    // Display RGB values
    printf("RGB code: (%d, %d, %d)\n", r, g, b);

    // Convert RGB to hex
    sprintf(hex, "%02X%02X%02X", r, g, b);

    // Display hex code
    printf("Hex code: #%s\n", hex);

    return 0;
}