//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int color_val, red_val, green_val, blue_val;

    // Ask User for RGB values
    printf("Enter Red, Green, and Blue values, separated by spaces: ");
    scanf("%d %d %d", &red_val, &green_val, &blue_val);

    // Convert RGB Values to Color Code
    color_val = (red_val << 16) + (green_val << 8) + blue_val;

    // Print out result
    printf("RGB: %d,%d,%d => Color: #%06X", red_val, green_val, blue_val, color_val);
    return 0;
}