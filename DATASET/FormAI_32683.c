//FormAI DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int color_code;
    char color[20];

    printf("Please enter a C Color Code: ");
    scanf("%d", &color_code);

    switch(color_code) {
        case 0:
            sprintf(color, "BLACK");
            break;
        case 1:
            sprintf(color, "RED");
            break;
        case 2:
            sprintf(color, "GREEN");
            break;
        case 3:
            sprintf(color, "YELLOW");
            break;
        case 4:
            sprintf(color, "BLUE");
            break;
        case 5:
            sprintf(color, "MAGENTA");
            break;
        case 6:
            sprintf(color, "CYAN");
            break;
        case 7:
            sprintf(color, "WHITE");
            break;
        default:
            printf("Invalid C Color Code\n");
            return 1;
    }

    printf("The C Color Code %d corresponds to the color %s\n", color_code, color);

    return 0;
}