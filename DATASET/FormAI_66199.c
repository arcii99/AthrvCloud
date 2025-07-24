//FormAI DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>

//Function to convert RGB to HSL
void RGBtoHSL(int r, int g, int b, double *h, double *s, double *l)
{
    double max, min, delta;
    double rd, gd, bd;

    rd = ((double) r) / 255.0;
    gd = ((double) g) / 255.0;
    bd = ((double) b) / 255.0;
    max = rd > gd ? (rd > bd ? rd : bd) : (gd > bd ? gd : bd);
    min = rd < gd ? (rd < bd ? rd : bd) : (gd < bd ? gd : bd);
    delta = max - min;
    
    //Calculate HSL values
    if (delta == 0.0) {
        *h = 0;
        *s = 0;
    } else if (max == rd) {
        *h = 60.0 * (((gd-bd)/delta)+360);
    } else if (max == gd) {
        *h = 60.0 * (((bd-rd)/delta)+120);
    } else if (max == bd) {
        *h = 60.0 * (((rd-gd)/delta)+240);
    }
    
    if (*h < 0) {
        *h += 360;
    }

    *l = (max + min) / 2.0;
    
    if (delta == 0.0) {
        *s = 0.0;
    } else {
        *s = delta / (1.0 - fabs(2.0 * (*l) - 1.0));
    }
}

//Function to convert HSL to RGB
void HSLtoRGB(double h, double s, double l, int *r, int *g, int *b)
{
    double c, m, x;
    double hd, sd, ld;

    hd = h / 60.0; //Convert to degrees
    sd = s;
    ld = l;
    c = (1.0 - fabs(2.0 * ld - 1.0)) * sd;
    m = ld - c / 2.0;
    x = c * (1.0 - fabs(hd - ((int)hd/2)*2 - 1.0));
    
    switch((int)hd) 
    {
        case 0:
            *r = (int)((c + m) * 255.0);
            *g = (int)((x + m) * 255.0);
            *b = (int)((0 + m) * 255.0);
            break;
        case 1:
            *r = (int)((x + m) * 255.0);
            *g = (int)((c + m) * 255.0);
            *b = (int)((0 + m) * 255.0);
            break;
        case 2:
            *r = (int)((0 + m) * 255.0);
            *g = (int)((c + m) * 255.0);
            *b = (int)((x + m) * 255.0);
            break;
        case 3:
            *r = (int)((0 + m) * 255.0);
            *g = (int)((x + m) * 255.0);
            *b = (int)((c + m) * 255.0);
            break;
        case 4:
            *r = (int)((x + m) * 255.0);
            *g = (int)((0 + m) * 255.0);
            *b = (int)((c + m) * 255.0);
            break;
        case 5:
            *r = (int)((c + m) * 255.0);
            *g = (int)((0 + m) * 255.0);
            *b = (int)((x + m) * 255.0);
            break;
        default:
            break;
    }
}

//Function to convert RGB to HEX
void RGBtoHEX(int r, int g, int b, char *hex)
{
    sprintf(hex, "%02X%02X%02X", r, g, b);
}

//Function to convert HEX to RGB
void HEXtoRGB(char *hex, int *r, int *g, int *b)
{
    sscanf(hex, "%02X%02X%02X", r, g, b);
}

int main()
{
    int r, g, b, tensec = 10;
    double h, s, l;
    char hex[7];
    char input[100];
    int mode = 0;

    printf("Welcome to the Color Code Converter.\n\n");
    printf("This program can convert between RGB, HSL, and HEX color codes.\n\n");

    while (tensec > 0) 
    {
        printf("Enter a color value (or 'quit' to exit): ");
        fgets(input, sizeof input, stdin);
        
        //Check for quit command
        if (strcmp(input, "quit\n") == 0)
        {
            break;
        }
        
        //Convert input to lowercase
        for (int i = 0; i < strlen(input); i++) 
        {
            input[i] = tolower(input[i]);
        }
        
        //Parse input based on format
        if (input[0] == '#') 
        {
            HEXtoRGB(input+1, &r, &g, &b);
            mode = 1;
        } else if (sscanf(input, "%d,%d,%d", &r, &g, &b) == 3) {
            mode = 0;
        } else if (sscanf(input, "%lf,%lf,%lf", &h, &s, &l) == 3) {
            mode = 2;
        } else {
            printf("Invalid input. Please enter a color value in the format R,G,B, H,S,L or #RRGGBB.\n");
            continue;
        }
        
        //Convert to other formats
        if (mode == 0) 
        {
            RGBtoHEX(r, g, b, hex);
            RGBtoHSL(r, g, b, &h, &s, &l);
        } else if (mode == 1) {
            RGBtoHSL(r, g, b, &h, &s, &l);
        } else if (mode == 2) {
            HSLtoRGB(h, s, l, &r, &g, &b);
            RGBtoHEX(r, g, b, hex);
        }
        
        //Print results
        printf("RGB: %d,%d,%d\n", r, g, b);
        printf("HSL: %0.2f,%0.2f,%0.2f\n", h, s, l);
        printf("HEX: #%s\n\n", hex);
        
        tensec--;
    }

    printf("\nThanks for using the Color Code Converter!");

    return 0;
}