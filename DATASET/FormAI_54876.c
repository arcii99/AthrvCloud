//FormAI DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    float c, m, y, k;
    
    printf("Enter Red value (0-255): ");
    scanf("%d", &red);
    
    printf("Enter Green value (0-255): ");
    scanf("%d", &green);
    
    printf("Enter Blue value (0-255): ");
    scanf("%d", &blue);
    
    float R = red / 255.0;
    float G = green / 255.0;
    float B = blue / 255.0;
    
    float max = R > G ? (R > B ? R : B) : (G > B ? G : B);
    float min = R < G ? (R < B ? R : B) : (G < B ? G : B);
    
    if (max == min) {
        c = 0;
        m = 0;
        y = 0;
        k = 1 - max;
    }
    else {
        float delta = max - min;
        k = 1 - max;
        c = (max - R) / delta;
        m = (max - G) / delta;
        y = (max - B) / delta;
    }
    
    printf("Cyan: %f\n", c);
    printf("Magenta: %f\n", m);
    printf("Yellow: %f\n", y);
    printf("Black: %f\n", k);
    
    return 0;
}