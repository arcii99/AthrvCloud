//FormAI DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>

// This function converts an RGB value to its corresponding hex code
char* RGBToHex(int R, int G, int B) {
    static char hex[7];
    sprintf(hex, "#%02X%02X%02X", R, G, B);
    return hex;
}

// This function converts a hex code to its corresponding RGB value
void HexToRGB(char* hex, int* R, int* G, int* B) {
    sscanf(hex, "#%02X%02X%02X", R, G, B);
}

int main() {
    int R = 255, G = 165, B = 0;
    char* hex = RGBToHex(R, G, B);
    printf("RGB(%d, %d, %d) is represented as %s in hex code.\n", R, G, B, hex);

    char* hexCode = "#FFA500";
    int newR, newG, newB;
    HexToRGB(hexCode, &newR, &newG, &newB);
    printf("%s in hex code represents RGB(%d, %d, %d).\n", hexCode, newR, newG, newB);

    return 0;
}