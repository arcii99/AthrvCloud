//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char hex[7], char rgb[15]) {
    /* base case */
    if (hex[0] == '\0') {
        return;
    }
    else {
        /* recursive case */
        char r[3], g[3], b[3];
        strncpy(r, hex, 2);
        r[2] = '\0';
        strncpy(g, hex + 2, 2);
        g[2] = '\0';
        strncpy(b, hex + 4, 2);
        b[2] = '\0';

        int red = (int)strtol(r, NULL, 16);
        int green = (int)strtol(g, NULL, 16);
        int blue = (int)strtol(b, NULL, 16);

        sprintf(rgb, "(%d, %d, %d) ", red, green, blue);

        convert(hex + 6, rgb + 12);
    }
}

int main() {
    char hex[50];
    printf("Enter a hex color code: ");
    fgets(hex, 50, stdin);
    hex[strcspn(hex, "\n")] = '\0';

    char rgb[150] = "";
    convert(hex, rgb);

    printf("The RGB equivalent of %s is: %s\n", hex, rgb);

    return 0;
}