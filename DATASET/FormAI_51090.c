//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char colorCode[7];
    printf("Enter a 6 digit hexadecimal color code: ");
    scanf("%s", colorCode);

    int r, g, b;
    sscanf(colorCode, "%02x%02x%02x", &r, &g, &b);

    printf("The RGB values for #%s are: %d,%d,%d\n", colorCode, r, g, b);

    return 0;
}