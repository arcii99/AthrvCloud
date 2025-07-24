//FormAI DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>

int main() {
    char hex[6];
    int red, green, blue;
    printf("Enter a 6-digit hex code: ");
    scanf("%s", hex);
    sscanf(hex, "%02x%02x%02x", &red, &green, &blue);
    printf("RGB code: %d,%d,%d\n", red, green, blue);
    printf("C code: 0x%.2X%.2X%.2X\n", red, green, blue);
    printf("OpenGL code: %.3f, %.3f, %.3f\n", (float)red/255, (float)green/255, (float)blue/255);
    printf("HTML code: #%s\n", hex);
    return 0;
}