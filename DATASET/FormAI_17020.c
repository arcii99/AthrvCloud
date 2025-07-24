//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    char hex[7], res;
    
    printf("Enter color values in RGB format:\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    
    printf("The color in hex format is: %s\n", hex);
    
    printf("Do you want to convert it back to RGB? (y/n): ");
    scanf(" %c", &res);
    
    if(res == 'y' || res == 'Y') {
        int r, g, b;
        sscanf(hex, "#%02X%02X%02X", &r, &g, &b);
        printf("The color in RGB format is: (%d, %d, %d)\n", r, g, b);
    }
    
    return 0;
}