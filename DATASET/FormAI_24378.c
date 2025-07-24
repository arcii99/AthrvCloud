//FormAI DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToHex(int num) {
    // Assumes num is less than or equal to 255

    char* hex = malloc(sizeof(char) * 3);
    sprintf(hex, "%02X", num);
    return hex;
}

int main() {
    int r, g, b;

    printf("Enter red value (0-255): ");
    scanf("%d", &r);
    printf("Enter green value (0-255): ");
    scanf("%d", &g);
    printf("Enter blue value (0-255): ");
    scanf("%d", &b);

    char* rHex = convertToHex(r);
    char* gHex = convertToHex(g);
    char* bHex = convertToHex(b);

    printf("Hex code is: #%s%s%s\n", rHex, gHex, bHex);

    free(rHex);
    free(gHex);
    free(bHex);

    return 0;
}