//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>

int main() {
    char hex[7];
    int r, g, b;
    
    printf("Enter a color code in hex format (e.g. FFFFFF): ");
    scanf("%s", hex);
    
    // convert hex to decimal
    r = (int)strtol(hex, NULL, 16) >> 16;
    g = (int)strtol(hex, NULL, 16) >> 8 & 0xFF;
    b = (int)strtol(hex, NULL, 16) & 0xFF;
    
    printf("RGB values: %d %d %d\n", r, g, b);
    
    return 0;
}