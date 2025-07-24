//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>

int main()
{
    char hex[7];
    int r, g, b;

    printf("Enter 6-character hexadecimal color code: ");
    scanf("%6s", hex);

    sscanf(hex, "%2x%2x%2x", &r, &g, &b);

    printf("RGB color code: (%d, %d, %d)\n", r, g, b);

    return 0;
}