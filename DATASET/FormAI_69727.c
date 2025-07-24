//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hex[10], r[3], g[3], b[3];
    printf("Enter a hex value: #");
    scanf("%s", hex);
    getchar();
    if (strlen(hex) == 6)
    {
        strncpy(r, hex, 2);
        r[2] = '\0';
        strncpy(g, hex + 2, 2);
        g[2] = '\0';
        strncpy(b, hex + 4, 2);
        b[2] = '\0';
    }
    else
    {
        printf("Invalid input\n");
        return 1;
    }
    int red, green, blue;
    red = strtol(r, NULL, 16);
    green = strtol(g, NULL, 16);
    blue = strtol(b, NULL, 16);
    printf("The RGB value is: (%d, %d, %d)\n", red, green, blue);
    return 0;
}