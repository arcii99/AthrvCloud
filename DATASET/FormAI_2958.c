//FormAI DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>

/* This program converts various color code formats into each other */

// Function to convert RGB to HEX
void RGBtoHEX(int R, int G, int B) {
    char hex[7];
    sprintf(hex, "%02X%02X%02X", R, G, B);
    printf("\nHex Code: #%s\n", hex);
}

// Function to convert HEX to RGB
void HEXtoRGB(char* hex) {
    unsigned int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    printf("\nRGB Code: %d,%d,%d\n", r, g, b);
}

// Function to convert RGB to HSL
void RGBtoHSL(int R, int G, int B) {
    double H, S, L;

    // Convert RGB to percentage values
    double r = (double)R / 255;
    double g = (double)G / 255;
    double b = (double)B / 255;

    double cmin = fmin(r, fmin(g, b));
    double cmax = fmax(r, fmax(g, b));
    double delta = cmax - cmin;
   
    if(delta == 0){
      H = 0;
    }
    else if(cmax == r){
      H = fmod(((g - b) / delta), 6);
    }
    else if(cmax == g){
      H = ((b - r) / delta) + 2;
    }
    else if(cmax == b){
      H = ((r - g) / delta) + 4;
    }

    H = round(H * 60);
    if(H < 0){
      H += 360;
    }
    
    L = round(((cmax + cmin) / 2) * 100);

    if(delta == 0){
      S = 0;
    }
    else{
      S = round((delta / (1 - fabs((2 * L) - 1))) * 100);
    }
    
    printf("\nHSL Code: %d,%d,%d\n", (int)H, (int)S, (int)L);
}

// Function to convert HSL to RGB
void HSLtoRGB(int H, int S, int L) {
    double r, g, b;

    double c = (1 - fabs((2 * (double)L/100) - 1)) * (double)S/100;
    double x = c * (1 - fabs(fmod((double)H/60, 2) - 1));
    double m = (double)L/100 - c/2;

    if(H >= 0 && H < 60){
        r = c;
        g = x;
        b = 0;
    }
    else if(H >= 60 && H < 120){
        r = x;
        g = c;
        b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0;
        g = c;
        b = x;
    }
    else if(H >= 180 && H < 240){
        r = 0;
        g = x;
        b = c;
    }
    else if(H >= 240 && H < 300){
        r = x;
        g = 0;
        b = c;
    }
    else{
        r = c;
        g = 0;
        b = x;
    }

    int R = round((r + m) * 255);
    int G = round((g + m) * 255);
    int B = round((b + m) * 255);

    printf("\nRGB Code: %d,%d,%d\n", R, G, B);
}

int main() {
    int choice;
    
    printf("Color Code Converter\n\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. RGB to HSL\n");
    printf("4. HSL to RGB\n");
    printf("5. Exit\n");
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int r, g, b;
                printf("\nEnter the RGB code (separate values with space): ");
                scanf("%d %d %d", &r, &g, &b);
                RGBtoHEX(r, g, b);
                break;
            }
            case 2: {
                char hex[7];
                printf("\nEnter the HEX code: ");
                scanf("%s", hex);
                HEXtoRGB(hex);
                break;
            }
            case 3: {
                int r, g, b;
                printf("\nEnter the RGB code (separate values with space): ");
                scanf("%d %d %d", &r, &g, &b);
                RGBtoHSL(r, g, b);
                break;
            }
            case 4: {
                int h, s, l;
                printf("\nEnter the HSL code (separate values with space): ");
                scanf("%d %d %d", &h, &s, &l);
                HSLtoRGB(h, s, l);
                break;
            }
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}