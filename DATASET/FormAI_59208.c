//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>

int main() {
    char hex[7];
    int r, g, b;

    printf("Enter a Hex Color Code (e.g. FFFFFF): ");
    scanf("%s", hex);

    sscanf(hex, "%2x%2x%2x", &r, &g, &b);

    printf("RGB Color Code: %d,%d,%d\n", r, g, b);

    printf("\n");

    int c, m, y, k;

    c = 255 - r;
    m = 255 - g;
    y = 255 - b;

    int max = c;
    if (m > max) max = m;
    if (y > max) max = y;

    if (max == 0) k = 0;
    else k = max - ((r + g + b) / 3);

    c = (c - k) * (100 / (float)255);
    m = (m - k) * (100 / (float)255);
    y = (y - k) * (100 / (float)255);
    k = k * (100 / (float)255);

    printf("CMYK Color Code: %d%%,%d%%,%d%%,%d%%\n", c, m, y, k);

    return 0;
}