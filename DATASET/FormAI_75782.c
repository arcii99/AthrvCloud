//FormAI DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>

int main() {
    char hex[7]; // array to store hex color code
    char rgb[16]; // array to store RGB color code
    
    printf("Enter a 6-digit hex color code: ");
    scanf("%s", hex); // user input
    
    // converting from hex to RGB
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    
    sprintf(rgb, "rgb(%d, %d, %d)", r, g, b); // formatting RGB color code
    
    printf("The RGB color code for %s is %s.\n", hex, rgb); // outputting result
    
    return 0;
}