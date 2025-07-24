//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main(){
    //define variables
    int red, green, blue;
    double cyan, magenta, yellow, key;

    //get user input for rgb values
    printf("Enter Red value (0-255): ");
    scanf("%d", &red);
    printf("Enter Green value (0-255): ");
    scanf("%d", &green);
    printf("Enter Blue value (0-255): ");
    scanf("%d", &blue);

    //convert rgb to cmyk
    double r = (double) red / 255;
    double g = (double) green / 255;
    double b = (double) blue / 255;

    double k = 1 - fmax(fmax(r,g),b);

    if (k==1){
        cyan = 0;
        magenta = 0;
        yellow = 0;
    } else {
        cyan = (1-r-k)/(1-k);
        magenta = (1-g-k)/(1-k);
        yellow = (1-b-k)/(1-k);
    }

    key = k;

    //print cmyk values
    printf("\nCyan Value: %.3f", cyan);
    printf("\nMagenta Value: %.3f", magenta);
    printf("\nYellow Value: %.3f", yellow);
    printf("\nKey Value: %.3f", key);

    return 0;
}