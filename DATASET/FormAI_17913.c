//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>

int main() {
    char color_code[7];
    printf("Please enter the hexadecimal color code: ");
    scanf("%s", color_code);

    // Check the length of the input
    if (strlen(color_code) != 6) {
        printf("Invalid input!\n");
        return 1;
    }

    // Validate the input
    for (int i = 0; i < 6; i++) {
        if ((color_code[i] < '0' || color_code[i] > '9') && 
            (color_code[i] < 'A' || color_code[i] > 'F') &&
            (color_code[i] < 'a' || color_code[i] > 'f')) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    // Convert the input to decimal
    int red = (int)strtol(color_code, NULL, 16) >> 16 & 0xFF;
    int green = (int)strtol(color_code, NULL, 16) >> 8 & 0xFF;
    int blue = (int)strtol(color_code, NULL, 16) & 0xFF;

    printf("RGB color code: (%d, %d, %d)\n", red, green, blue);

    return 0;
}