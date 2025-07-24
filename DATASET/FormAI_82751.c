//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>

int main() {
    // Prompt the user to enter a color code
    printf("Enter the color code: ");
    char colorCode[7];
    scanf("%s", colorCode);
    
    // Check if the given color code is valid
    int i;
    for (i=0; i<6; i++) {
        if (!((colorCode[i] >= '0' && colorCode[i] <= '9') || (colorCode[i] >= 'A' && colorCode[i] <= 'F'))) {
            printf("Invalid color code!\n");
            return 0;
        }
    }

    // Convert the given color code to its corresponding RGB values
    int red = (int)strtol(colorCode, NULL, 16) >> 16;
    int green = (int)strtol(colorCode, NULL, 16) >> 8 & 0xff;
    int blue = (int)strtol(colorCode, NULL, 16) & 0xff;

    // Display the RGB values
    printf("RGB values: (%d, %d, %d)\n", red, green, blue);

    return 0;
}