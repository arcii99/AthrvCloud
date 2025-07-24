//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COLOR_VALUE 255

// Structure to represent RGBA color
typedef struct {
    int r;
    int g;
    int b;
    float a;
} RGBA;

// Structure to represent HSLA color
typedef struct {
    float h;
    float s;
    float l;
    float a;
} HSLA;

// Function to convert RGB to hexadecimal color code
char* rgb_to_hex(int r, int g, int b) {
    char* hex = (char*) malloc(sizeof(char) * 7);
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

// Function to convert hexadecimal color code to RGB
void hex_to_rgb(char* hex, int* r, int* g, int* b) {
    if (hex[0] == '#') hex++;

    // Convert hexadecimal string to integer values
    sscanf(hex, "%02x%02x%02x", r, g, b);
}

// Function to convert RGB to HSL
void rgb_to_hsl(int r, int g, int b, float* h, float* s, float* l) {
    // Normalize RGB values to range 0-1
    float R = r / (float) MAX_COLOR_VALUE;
    float G = g / (float) MAX_COLOR_VALUE;
    float B = b / (float) MAX_COLOR_VALUE;

    float minval = fminf(R, fminf(G, B));
    float maxval = fmaxf(R, fmaxf(G, B));
    float delta = maxval - minval;

    *l = (maxval + minval) / 2.0;

    if (delta == 0) {
        *h = 0;
        *s = 0;
    } else {
        if (*l < 0.5) {
            *s = delta / (maxval + minval);
        } else {
            *s = delta / (2 - maxval - minval);
        }

        float del_R = (((maxval - R) / 6.0) + (delta / 2.0)) / delta;
        float del_G = (((maxval - G) / 6.0) + (delta / 2.0)) / delta;
        float del_B = (((maxval - B) / 6.0) + (delta / 2.0)) / delta;

        if (R == maxval) *h = del_B - del_G;
        else if (G == maxval) *h = (1.0 / 3.0) + del_R - del_B;
        else if (B == maxval) *h = (2.0 / 3.0) + del_G - del_R;

        if (*h < 0) *h += 1;
        if (*h > 1) *h -= 1;
    }
}

// Function to convert HSL to RGB
void hsl_to_rgb(float h, float s, float l, int* r, int* g, int* b) {
    float C = (1 - fabsf(2 * l - 1)) * s;
    float X = C * (1 - fabsf(fmodf(h * 6, 2) - 1));
    float m = l - C / 2.0;

    float R, G, B;
    if (h < 1.0 / 6.0) {
        R = C;
        G = X;
        B = 0;
    } else if (h < 2.0 / 6.0) {
        R = X;
        G = C;
        B = 0;
    } else if (h < 3.0 / 6.0) {
        R = 0;
        G = C;
        B = X;
    } else if (h < 4.0 / 6.0) {
        R = 0;
        G = X;
        B = C;
    } else if (h < 5.0 / 6.0) {
        R = X;
        G = 0;
        B = C;
    } else {
        R = C;
        G = 0;
        B = X;
    }

    // Add m to each component and scale to 0-255 range
    *r = roundf((R + m) * MAX_COLOR_VALUE);
    *g = roundf((G + m) * MAX_COLOR_VALUE);
    *b = roundf((B + m) * MAX_COLOR_VALUE);
}

int main() {
    int r = 255, g = 165, b = 0;
    printf("RGB: %d %d %d\n", r, g, b);

    char* hex = rgb_to_hex(r, g, b);
    printf("Hex: %s\n", hex);
    free(hex);

    float h, s, l;
    rgb_to_hsl(r, g, b, &h, &s, &l);
    printf("HSL: %0.2f %0.2f %0.2f\n", h, s, l);

    int red, green, blue;
    hsl_to_rgb(h, s, l, &red, &green, &blue);
    printf("RGB: %d %d %d\n", red, green, blue);

    char hexcode[8];
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hexcode);

    int red2, green2, blue2;
    hex_to_rgb(hexcode, &red2, &green2, &blue2);
    printf("RGB: %d %d %d\n", red2, green2, blue2);

    float h2, s2, l2;
    rgb_to_hsl(red2, green2, blue2, &h2, &s2, &l2);
    printf("HSL: %0.2f %0.2f %0.2f\n", h2, s2, l2);

    return 0;
}