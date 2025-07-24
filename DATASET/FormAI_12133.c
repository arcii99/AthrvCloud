//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

// struct to represent a pixel in an image
typedef struct pixel {
    int r;
    int g;
    int b;
} Pixel;

// convert a pixel to a grayscale value
int pixel_to_grayscale(Pixel p) {
    return (int)(0.299*p.r + 0.587*p.g + 0.114*p.b);
}

// convert a grayscale value to ascii character
char grayscale_to_ascii(int gray) {
    // ascii characters arranged from darkest to lightest
    static char ascii_chars[] = "$@B%8&WM#*oahkbdpqwmZO0QCJYXzcvn\
                                UYXjkluyxvnmfri|()1{}[]?-_+~<>i!lI\
                                ;:,\"^`'. ";
    // calculate the index of ascii character based on the grayscale value
    int index = gray*strlen(ascii_chars)/256;
    // return the corresponding ascii character
    return ascii_chars[index];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }
    // read image file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error: failed to open file %s\n", argv[1]);
        exit(1);
    }
    Pixel image[WIDTH][HEIGHT];
    fread(image, sizeof(Pixel), WIDTH*HEIGHT, fp);
    fclose(fp);
    // convert image to grayscale and collect ascii characters
    char ascii_art[HEIGHT][WIDTH];
    memset(ascii_art, ' ', sizeof(ascii_art));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int gray = pixel_to_grayscale(image[x][y]);
            char ascii_char = grayscale_to_ascii(gray);
            ascii_art[y][x] = ascii_char;
        }
    }
    // print ascii art to console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(ascii_art[y][x]);
        }
        putchar('\n');
    }
    return 0;
}