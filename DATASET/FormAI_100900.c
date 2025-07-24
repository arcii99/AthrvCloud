//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
/* A sophisticated C Color Code Converter Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex_code[7], rgb_code[13];    // allocate memory for storing codes

    printf("Enter hexadecimal color code: ");
    scanf("%s", hex_code);

    int num_code = (int) strtol(hex_code, NULL, 16);    // convert hex to decimal

    int red = (num_code >> 16) & 0xFF;    // get red value
    int green = (num_code >> 8) & 0xFF;   // get green value
    int blue = num_code & 0xFF;           // get blue value

    sprintf(rgb_code, "rgb(%d,%d,%d)", red, green, blue);    // format rgb code

    printf("The RGB color code is: %s", rgb_code);

    return 0;
}