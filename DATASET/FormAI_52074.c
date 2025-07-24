//FormAI DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hex[7], r[3], g[3], b[3];
    int red, green, blue;

    printf("Welcome to the Color Converter! \n");
    printf("Enter hex value: ");
    scanf("%s", hex);

    if (strlen(hex) == 6)
    {
        strncpy(r, hex, 2);
        strncpy(g, hex + 2, 2);
        strncpy(b, hex + 4, 2);

        red = strtol(r, NULL, 16);
        green = strtol(g, NULL, 16);
        blue = strtol(b, NULL, 16);

        printf("\nRGB: (%d, %d, %d)\n", red, green, blue);
    }
    else
    {
        printf("\nInvalid hex code. Please enter a 6 digit hex code.\n");
        return 0;
    }

    printf("\n");

    return 0;
}