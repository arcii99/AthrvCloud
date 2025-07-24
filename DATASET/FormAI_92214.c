//FormAI DATASET v1.0 Category: Image Editor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT 512
#define WIDTH 512

typedef struct {
    unsigned char r,g,b;
} RGB;

RGB image[HEIGHT][WIDTH];

void read_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fseek(file, 54, SEEK_SET);

    for (int y = HEIGHT-1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            RGB pixel;
            fread(&pixel, sizeof(RGB), 1, file);
            image[y][x] = pixel;
        }
    }

    fclose(file);
}

void write_image(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    unsigned char header[54] = {
        0x42, 0x4d, 0x36, 0x00, 0x0c, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x60, 0x00, 0x0c, 0x00, 0x13, 0x0b,
        0x00, 0x00, 0x13, 0x0b, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
    };
    fwrite(header, sizeof(unsigned char), 54, file);

    for (int y = HEIGHT-1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            RGB pixel = image[y][x];
            fwrite(&pixel, sizeof(RGB), 1, file);
        }
    }

    fclose(file);
}

void invert_colors() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x].r = 255 - image[y][x].r;
            image[y][x].g = 255 - image[y][x].g;
            image[y][x].b = 255 - image[y][x].b;
        }
    }
}

void grayscale() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char gray = (image[y][x].r + image[y][x].g + image[y][x].b) / 3;
            image[y][x].r = gray;
            image[y][x].g = gray;
            image[y][x].b = gray;
        }
    }
}

void blur() {
    for (int y = 1; y < HEIGHT-1; y++) {
        for (int x = 1; x < WIDTH-1; x++) {
            unsigned int rsum = 0, gsum = 0, bsum = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int yy = y+dy;
                    int xx = x+dx;
                    rsum += image[yy][xx].r;
                    gsum += image[yy][xx].g;
                    bsum += image[yy][xx].b;
                }
            }
            image[y][x].r = rsum / 9;
            image[y][x].g = gsum / 9;
            image[y][x].b = bsum / 9;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    read_image(argv[1]);
    invert_colors();
    write_image("inverted.bmp");

    read_image(argv[1]);
    grayscale();
    write_image("grayscale.bmp");

    read_image(argv[1]);
    blur();
    write_image("blur.bmp");

    return 0;
}