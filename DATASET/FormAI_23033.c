//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include<stdio.h>
#include<string.h>

int main() {
    // initialize variables
    char code[8], hex[8];
    int r = 0, g = 0, b = 0;

    // read the input color code
    printf("Enter the color code in RRRGGGBB format: ");
    scanf("%s", code);

    // extract the r, g, b values from the code
    r = ((code[0] - '0') * 100) + ((code[1] - '0') * 10) + (code[2] - '0');
    g = ((code[3] - '0') * 100) + ((code[4] - '0') * 10) + (code[5] - '0');
    b = ((code[6] - '0') * 100) + ((code[7] - '0') * 10) + (code[8] - '0');

    // convert the r, g, b values to hexadecimal
    sprintf(hex, "#%02x%02x%02x", r, g, b);

    // output the result
    printf("The color code in hexadecimal is: %s\n", hex);

    return 0;
}