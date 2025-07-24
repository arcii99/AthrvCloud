//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char color[10];
    printf("Enter the hexadecimal color code (without #): ");
    scanf("%s", color);

    int r = strtol(color, NULL, 16) >> 16;
    int g = (strtol(color, NULL, 16) & 0x00ff00) >> 8;
    int b = strtol(color, NULL, 16) & 0x0000ff;

    printf("RGB color code: (%d, %d, %d)\n", r, g, b);
    printf("Would you like to convert this color to CMYK? (y/n): ");

    char response;
    scanf(" %c", &response);

    if (response == 'y')
    {
        double c = 1 - ((double)r / 255);
        double m = 1 - ((double)g / 255);
        double y = 1 - ((double)b / 255);
        double k = fmin(c, fmin(m, y));

        c = (c - k) / (1 - k);
        m = (m - k) / (1 - k);
        y = (y - k) / (1 - k);

        printf("CMYK color code: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);
    }
    else
    {
        printf("Okay, no problem. Have a nice day!\n");
    }
    return 0;
}