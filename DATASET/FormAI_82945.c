//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertHexToRgb(char* hex, int* r, int* g, int* b) {
    if (strlen(hex) != 6) {
        printf("Invalid HEX Color Code\n");
        exit(1);
    }
    
    char rStr[3], gStr[3], bStr[3];
    strncpy(rStr, hex, 2);
    strncpy(gStr, hex+2, 2);
    strncpy(bStr, hex+4, 2);

    *r = (int)strtol(rStr, NULL, 16);
    *g = (int)strtol(gStr, NULL, 16);
    *b = (int)strtol(bStr, NULL, 16);
}

int main() {
    char hexColor[7];
    printf("Enter a HEX Color Code (e.g., FF7F50): ");
    scanf("%s", hexColor);

    int r, g, b;
    convertHexToRgb(hexColor, &r, &g, &b);
    printf("RGB Color: (%d, %d, %d)\n", r, g, b);

    return 0;
}