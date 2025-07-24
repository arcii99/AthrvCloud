//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void print_pixel(char pixel) {
    switch (pixel) {
        case 'B':
            printf("\033[44m "); // Blue background
            break;
        case 'G':
            printf("\033[42m "); // Green background
            break;
        case 'R':
            printf("\033[41m "); // Red background
            break;
        case 'Y':
            printf("\033[43m "); // Yellow background
            break;
        case 'M':
            printf("\033[45m "); // Magenta background
            break;
        case 'C':
            printf("\033[46m "); // Cyan background
            break;
        default:
            printf(" ");
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Failed to open file %s\n", argv[1]);
        exit(1);
    }

    char pixels[WIDTH][HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char c = fgetc(file);
            pixels[j][i] = c;
        }
        fgetc(file); // Eat newline character
    }

    fclose(file);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            print_pixel(pixels[j][i]);
        }
        printf("\033[0m\n"); // Reset color
    }

    return 0;
}