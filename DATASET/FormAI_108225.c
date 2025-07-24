//FormAI DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHAR 10

int main() {
    char hex[MAXCHAR];
    int i, r, g, b;

    printf("Enter a HEX color code: #");
    scanf("%s", hex);

    // Convert input to uppercase
    for (i = 0; hex[i]; i++) 
        hex[i] = toupper(hex[i]);

    // Convert input from HEX to RGB
    r = (int)strtol(hex, NULL, 16) >> 16;
    g = (int)strtol(hex, NULL, 16) >> 8 & 0xff;
    b = (int)strtol(hex, NULL, 16) & 0xff;

    // Print RGB values
    printf("The equivalent RGB color code for #%s is (%d, %d, %d)\n", hex, r, g, b);

    return 0;
}