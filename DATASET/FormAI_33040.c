//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    char color[20];
    
    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a color in its name or hex code: ");
    scanf("%s", color);
    
    // Hex to RGB conversion
    if (color[0] == '#' && strlen(color) == 7) {
        int red = strtol(&color[1], NULL, 16) >> 16;
        int green = (strtol(&color[1], NULL, 16) >> 8) & 0xFF;
        int blue = strtol(&color[1], NULL, 16) & 0xFF;
        printf("The RGB color code for %s is: %d,%d,%d", color, red, green, blue);
    }
    
    // RGB to Hex conversion
    else if (color[0] >= '0' && color[0] <= '9') {
        int red, green, blue;
        sscanf(color, "%d,%d,%d", &red, &green, &blue);
        printf("The hex code for %s is: #%02X%02X%02X", color, red, green, blue);
    }
    
    // Error message for invalid input
    else {
        printf("I'm sorry, \"%s\" is not a valid color format. Please try again!", color);
    }
    
    return 0;
}