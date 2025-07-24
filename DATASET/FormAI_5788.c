//FormAI DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    char hex[BUFFER_SIZE];
    char rgb[BUFFER_SIZE];
    int r, g, b;

    printf("Enter Hex Code: ");
    fgets(hex, BUFFER_SIZE, stdin);
    hex[strcspn(hex, "\n")] = 0; // remove trailing newline character

    // convert hex code to rgb values
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    // convert rgb values to string
    sprintf(rgb, "rgb(%d,%d,%d)", r, g, b);

    printf("%s\n", rgb);

    return 0;
}