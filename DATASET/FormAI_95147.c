//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

int main()
{
    int r, g, b;
    printf("Enter RGB values (0-255):\n");
    scanf("%d %d %d", &r, &g, &b);

    float c, m, y, k; //initialize CMYK variables

    // convert RGB values to CMY values
    float cmy_c = 1 - r / 255.0;
    float cmy_m = 1 - g / 255.0;
    float cmy_y = 1 - b / 255.0;

    // find minimum CMY value and calculate K value
    float cmy_min = cmy_c;
    if (cmy_min > cmy_m)
        cmy_min = cmy_m;
    if (cmy_min > cmy_y)
        cmy_min = cmy_y;
    k = cmy_min;

    // calculate CMYK values
    c = (cmy_c - k) / (1 - k);
    m = (cmy_m - k) / (1 - k);
    y = (cmy_y - k) / (1 - k);

    // output results
    printf("The CMYK values are:\n");
    printf("C: %f\n", c);
    printf("M: %f\n", m);
    printf("Y: %f\n", y);
    printf("K: %f\n", k);

    return 0;
}