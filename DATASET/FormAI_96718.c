//FormAI DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>

int main() {

    int r, g, b;

    printf("Enter the RGB values (0-255) separated by a space: ");
    scanf("%d %d %d", &r, &g, &b);

    float c = 0, m = 0, y = 0, k = 0;

    // Converting RGB values to CMYK values
    c = 1 - (float)r/255;
    m = 1 - (float)g/255;
    y = 1 - (float)b/255;

    float tmp = c < m ? c : m;
    k = tmp < y ? tmp : y;
    c = (c - k)/(1 - k);
    m = (m - k)/(1 - k);
    y = (y - k)/(1 - k);
    k = k * 100;

    // Printing the final CMYK values
    printf("\nCMYK values: \n");
    printf("C = %.2f%%\n", c*100);
    printf("M = %.2f%%\n", m*100);
    printf("Y = %.2f%%\n", y*100);
    printf("K = %.2f%%\n", k);

    return 0;
}