//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>

int main() {
    int code;
    char color;

    printf("Enter a color code (R/G/B): ");
    scanf("%c", &color);

    switch(color) {
        case 'R':
            code = 0xFF0000;
            break;
        case 'G':
            code = 0x00FF00;
            break;
        case 'B':
            code = 0x0000FF;
            break;
        default:
            printf("Invalid color code!");
            return 0;
    }

    printf("The code for color %c is: %d", color, code);

    return 0;
}