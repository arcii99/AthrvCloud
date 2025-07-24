//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "@#&$%*o!:.- "

char image[MAX_HEIGHT][MAX_WIDTH];
char ascii_image[MAX_HEIGHT][MAX_WIDTH];

void read_image(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "r");
    char c;
    int i = 0, j = 0;
    while ((c = fgetc(fp)) != EOF && i < MAX_HEIGHT) {
        if (c == '\n') {
            *height = i;
            i++;
            j = 0;
        } else {
            image[i][j] = c;
            j++;
            if (j > *width) {
                *width = j;
            }
        }
    }
    fclose(fp);
}

void convert_to_ascii(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int gray_value = (int) image[y][x];
            int char_index = gray_value * 11 / 255;
            ascii_image[y][x] = ASCII_CHARS[char_index];
        }
    }
}

void print_ascii_image(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii_image[y][x]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    memset(image, 0, MAX_WIDTH * MAX_HEIGHT);
    memset(ascii_image, 0, MAX_WIDTH * MAX_HEIGHT);

    int width = 0, height = 0;
    read_image(argv[1], &width, &height);
    convert_to_ascii(width, height);
    print_ascii_image(width, height);

    return 0;
}