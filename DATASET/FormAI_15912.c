//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>

int main() {
    float r, g, b;
    printf("Enter RGB values (0-255): ");
    scanf("%f %f %f", &r, &g, &b);

    // converting to 0-1 range
    float red = r/255;
    float green = g/255;
    float blue = b/255;

    // finding maximum and minimum values
    float max = red;
    if(green > max) max = green;
    if(blue > max) max = blue;

    float min = red;
    if(green < min) min = green;
    if(blue < min) min = blue;

    float c = max - min;
    float h, s, l;

    // finding hue
    if(max == red) h = (green - blue) / c;
    else if(max == green) h = 2 + (blue - red) / c;
    else h = 4 + (red - green) / c;
    h *= 60;
    if(h < 0) h += 360;

    // finding lightness
    l = (max + min) / 2;

    // finding saturation
    if(c == 0) s = 0;
    else s = c / (1 - fabs(2*l-1));

    // converting to percentage
    h = h / 360 * 100;
    s *= 100;
    l *= 100;

    // printing HSL values
    printf("\nHSL values: %f %f %f\n", h, s, l);

    return 0;
}