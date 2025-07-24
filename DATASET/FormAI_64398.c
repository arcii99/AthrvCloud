//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[8];
    char output[8];
    int red, green, blue;

    printf("Enter a color code in hexadecimal format (e.g. #ffaa00): ");
    scanf("%s", input);

    if (strlen(input) != 7 || input[0] != '#') {
        printf("Invalid color code format!\n");
        return 1;
    }

    red = strtol(&input[1], NULL, 16);
    green = strtol(&input[3], NULL, 16);
    blue = strtol(&input[5], NULL, 16);

    if (red > 255 || green > 255 || blue > 255) {
        printf("Invalid color code value!\n");
        return 1;
    }

    printf("The RGB values for %s are (%d,%d,%d).\n", input, red, green, blue);

    sprintf(output, "%.2X%.2X%.2X", red, green, blue);

    printf("The equivalent color code for RGB(%d,%d,%d) is #%s.\n", red, green, blue, output);

    return 0;
}