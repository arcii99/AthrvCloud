//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>

int main() {
    char hex_value[7];
    int red, green, blue;
    printf("Enter 6 digit hexadecimal code: ");
    scanf("%s", hex_value);
    red = (int) strtol(hex_value, NULL, 16) >> 16;
    green = (int) strtol(hex_value, NULL, 16) >> 8 & 0xff;
    blue = (int) strtol(hex_value, NULL, 16) & 0xff;
    printf("RGB values: %d, %d, %d\n", red, green, blue);
    return 0;
}