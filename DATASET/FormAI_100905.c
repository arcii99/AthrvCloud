//FormAI DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char hex[8];
    printf("Enter a hexadecimal color code in the format RRGGBB: ");
    scanf("%s", hex);

    // Convert hex to uppercase
    for (int i = 0; i < strlen(hex); i++)
    {
        hex[i] = toupper(hex[i]);
    }

    // Split hex into red, green, and blue components
    char r[3] = {hex[0], hex[1], '\0'};
    char g[3] = {hex[2], hex[3], '\0'};
    char b[3] = {hex[4], hex[5], '\0'};

    // Convert from hex to base 10
    int red = (int)strtol(r, NULL, 16);
    int green = (int)strtol(g, NULL, 16);
    int blue = (int)strtol(b, NULL, 16);

    // Calculate the closest ANSI color
    int nearest_r = (red + 28) / 56;
    int nearest_g = (green + 28) / 56;
    int nearest_b = (blue + 28) / 56;
    int nearest_code = 16 + (36 * nearest_r) + (6 * nearest_g) + nearest_b;

    printf("The closest ANSI color code is: %d\n", nearest_code);

    return 0;
}