//FormAI DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>

// Converts RGB values to HEX color code
void RGBtoHEX(int R, int G, int B) {
    printf("#%02x%02x%02x\n", R, G, B);
}

// Converts HEX color code to RGB values
void HEXtoRGB(char *hex) {
    if (!hex) return;
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("R: %d\nG: %d\nB: %d\n", r, g, b);
}

int main() {
    int R, G, B;
    char hex[7];
    printf("Enter RGB values (between 0 and 255):\n");
    printf("R = ");
    scanf("%d", &R);
    printf("G = ");
    scanf("%d", &G);
    printf("B = ");
    scanf("%d", &B);
    RGBtoHEX(R, G, B);
    printf("Enter a HEX color code (in the format #RRGGBB):\n");
    scanf("%s", hex);
    HEXtoRGB(hex);
    return 0;
}