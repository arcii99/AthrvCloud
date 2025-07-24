//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include<stdio.h>

int main(){
    int red, green, blue;
    float cyan, magenta, yellow, key;

    printf("Enter color code in RGB format\n");
    printf("Red value: ");
    scanf("%d", &red);
    printf("Green value: ");
    scanf("%d", &green);
    printf("Blue value: ");
    scanf("%d", &blue);

    //Converting from RGB to CMYK

    float r,g,b;
    r = red/255.0;
    g = green/255.0;
    b = blue/255.0;

    float black = 1 - fmax(r,fmax(g,b));
    cyan = (1-r-black)/(1-black);
    magenta = (1-g-black)/(1-black);
    yellow = (1-b-black)/(1-black);
    key = black;

    //Converting from RGB to HEX

    char hex[7];
    sprintf(hex,"%02X%02X%02X", red, green, blue);

    printf("The CMYK color code is C=%.2f%% | M=%.2f%% | Y=%.2f%% | K=%.2f%%\n", cyan*100, magenta*100, yellow*100, key*100);
    printf("The HEX color code is #%s\n", hex);

    return 0;
}