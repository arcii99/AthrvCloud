//FormAI DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 10

int main() {
    char input[MAX_INPUT];
    char hex[3];
    int red, green, blue;
    int r_hex, g_hex, b_hex;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color code in the format RRRGGGBB: ");
    fgets(input, MAX_INPUT, stdin);

    sscanf(input, "%2x%2x%2x", &r_hex, &g_hex, &b_hex);

    printf("RGB Color: %d %d %d\n", r_hex, g_hex, b_hex);

    red = r_hex * 255 / 255;
    green = g_hex * 255 / 255;
    blue = b_hex * 255 / 255;

    printf("Converted to C color code: #");
    sprintf(hex, "%02x", red);
    printf("%s", hex);
    sprintf(hex, "%02x", green);
    printf("%s", hex);
    sprintf(hex, "%02x", blue);
    printf("%s\n", hex);

    return 0;
}