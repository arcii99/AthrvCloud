//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>

int main() {
    int red, green, blue;
    printf("Enter a Color in RGB format:\n(Red, Green, Blue)\n");
    scanf("%d, %d, %d", &red, &green, &blue);

    // Converting RGB to HEX
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);

    // Converting RGB to CMYK
    float c, m, y, k;
    c = 1 - (float)red/255;
    m = 1 - (float)green/255;
    y = 1 - (float)blue/255;
    k = c < m ? (c < y ? c : y) : (m < y ? m : y);
    c = (c - k)/(1 - k);
    m = (m - k)/(1 - k);
    y = (y - k)/(1 - k);

    //Printing Results
    printf("\n RGB: %d, %d, %d", red, green, blue);
    printf("\n HEX: %s", hex);
    printf("\n CMYK: %0.2f, %0.2f, %0.2f, %0.2f", c, m, y, k);

    return 0;
}