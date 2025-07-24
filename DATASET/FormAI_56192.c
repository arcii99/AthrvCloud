//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hexToRGB(char *hex, int *red, int *green, int *blue, int index) {
    if (hex[index] == '\0') {
        return;
    }
    
    int val = 0;
    if (isalpha(hex[index])) {
        val = hex[index] - 'a' + 10;
    } else {
        val = hex[index] - '0';
    }
    
    if (index % 2 == 0) {
        *red = *red * 16 + val;
    } else if (index % 2 == 1 && index < 4) {
        *green = *green * 16 + val;
    } else {
        *blue = *blue * 16 + val;
    }
    
    hexToRGB(hex, red, green, blue, index + 1);
}

int main() {
    char hex[7];
    int red = 0, green = 0, blue = 0;
    
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);
    
    hexToRGB(hex, &red, &green, &blue, 0);
    
    printf("RGB: (%d, %d, %d)\n", red, green, blue);
    
    return 0;
}