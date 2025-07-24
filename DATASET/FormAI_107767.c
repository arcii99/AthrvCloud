//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    char colorCode[7];
    
    printf("Enter color code (e.g. FF3355): ");
    scanf("%s", colorCode);
    
    red = (int) strtol(colorCode, NULL, 16) >> 16;
    green = (int) strtol(colorCode + 2, NULL, 16) >> 8;
    blue = (int) strtol(colorCode + 4, NULL, 16);
    
    printf("RGB color values: %d, %d, %d\n", red, green, blue);
    
    return 0;
}