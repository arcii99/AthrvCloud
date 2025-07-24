//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, g, b;

    printf("Enter RGB values (0-255): ");
    scanf("%d %d %d", &r, &g, &b);

    // convert RGB to CMYK
    double c = 1 - (double)r / 255;
    double m = 1 - (double)g / 255;
    double y = 1 - (double)b / 255;
    double k = c < m ? (c < y ? c : y) : (m < y ? m : y);

    printf("\nCMYK values: %.2f %.2f %.2f %.2f", (c - k) / (1 - k), (m - k) / (1 - k), (y - k) / (1 - k), k);

    return 0;
}