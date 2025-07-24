//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char hex[7];
    printf("Enter the hexadecimal color code: ");
    scanf("%s", hex);
    
    int r = strtol(&hex[0], NULL, 16);
    int g = strtol(&hex[2], NULL, 16);
    int b = strtol(&hex[4], NULL, 16);
    
    printf("RGB color code: %d,%d,%d\n", r, g, b);
    
    return 0;
}