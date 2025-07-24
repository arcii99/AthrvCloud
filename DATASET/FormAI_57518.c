//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

char ascii_chars[] = {' ', '.', ',', ':', ';', 'i', '1', 't', 'f', 'L', 'C', 'G', 'O', 'Q', '8', '@'};

void rgb_to_grayscale(int *r, int *g, int *b, int *grayscale) {
    *grayscale = (*r + *g + *b) / 3;
}

int map_to_ascii(int grayscale_val) {
    int num_chars = sizeof(ascii_chars) / sizeof(char);
    int step_size = 255 / num_chars;
    int char_index = grayscale_val / step_size;

    if (char_index >= num_chars) {
        char_index = num_chars - 1;
    }

    return ascii_chars[char_index];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Please provide a filename.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    char line[WIDTH * 3];
    int image[HEIGHT][WIDTH];
    int row, col;

    for (row = 0; row < HEIGHT; row++) {
        fgets(line, sizeof(line), file);

        for (col = 0; col < WIDTH; col++) {
            int index = col * 3;
            int r = (int) line[index];
            int g = (int) line[index + 1];
            int b = (int) line[index + 2];

            rgb_to_grayscale(&r, &g, &b, &(image[row][col]));
        }
    }

    fclose(file);

    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            printf("%c", map_to_ascii(image[row][col]));
        }
        printf("\n");
    }

    return 0;
}