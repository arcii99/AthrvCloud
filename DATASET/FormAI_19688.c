//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>

int main() {
    int choice;
    float red, blue, green, cyan, magenta, yellow;
    
    printf("\nColor Code Converter\n");
    printf("\n1. RGB to CMY");
    printf("\n2. CMY to RGB\n");
    printf("\nEnter your choice: ");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nEnter the values of R, G and B (0 to 255): ");
            scanf("%f %f %f", &red, &green, &blue);
            
            cyan = 1 - (red/255);
            magenta = 1 - (green/255);
            yellow = 1 - (blue/255);
            
            printf("\nCMY Color Code: C=%.2f M=%.2f Y=%.2f\n", cyan, magenta, yellow);
            break;
            
        case 2:
            printf("\nEnter the values of C, M and Y (0 to 1): ");
            scanf("%f %f %f", &cyan, &magenta, &yellow);
            
            red = (1 - cyan) * 255;
            green = (1 - magenta) * 255;
            blue = (1 - yellow) * 255;
            
            printf("\nRGB Color Code: R=%.0f G=%.0f B=%.0f\n", red, green, blue);
            break;
            
        default:
            printf("\nInvalid choice\n");
    }
    
    return 0;
}