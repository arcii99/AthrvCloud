//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODES_COUNT 5

struct ColorCode {
    char name[20];
    char hex[8];
    int red;
    int green;
    int blue;
} color_codes[COLOR_CODES_COUNT] = {
    {"Red", "#FF0000", 255, 0, 0},
    {"Green", "#00FF00", 0, 255, 0},
    {"Blue", "#0000FF", 0, 0, 255},
    {"Cyan", "#00FFFF", 0, 255, 255},
    {"Magenta", "#FF00FF", 255, 0, 255},
};

int main() {
    while (1) {
        printf("Enter a color name or hex code (q to quit): ");
        char input[20];
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < COLOR_CODES_COUNT; i++) {
            if (strcmp(input, color_codes[i].name) == 0 ||
                strcmp(input, color_codes[i].hex) == 0) {
                printf("%s color code is (%d, %d, %d)\n", color_codes[i].name, color_codes[i].red, color_codes[i].green, color_codes[i].blue);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Color not found\n");
        }
    }

    return 0;
}