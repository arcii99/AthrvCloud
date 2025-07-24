//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
/* Romeo and Juliet: A Color Code Converter */

#include <stdio.h>
#include <string.h>

int main() {
    char color[10];
    int red_val, green_val, blue_val;

    printf("Oh, what light through yonder window breaks?\n");
    printf("Enter your color code in hex format, fair maiden: ");
    scanf("%s", color);

    // Convert hex color code to RGB values
    sscanf(color, "%02x%02x%02x", &red_val, &green_val, &blue_val);

    printf("By any other name would smell as sweet, but this color's RGB values are:\n");
    printf("Red: %d\nGreen: %d\nBlue: %d\n", red_val, green_val, blue_val);

    return 0;
}