//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_WIDTH 2000
#define MAX_HEIGHT 2000
#define ASCII_CHARS " .,-:;i1tfLCG08@"
#define ASCII_CHAR_COUNT strlen(ASCII_CHARS)

void load_image(const char* filename, uint8_t image[MAX_WIDTH][MAX_HEIGHT], int* width, int* height);
void convert_to_ascii(uint8_t image[MAX_WIDTH][MAX_HEIGHT], int width, int height, char ascii[MAX_WIDTH][MAX_HEIGHT]);
void print_ascii(char ascii[MAX_WIDTH][MAX_HEIGHT], int width, int height);

int main(int argc, char* argv[]) 
{
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    uint8_t image[MAX_WIDTH][MAX_HEIGHT];
    char ascii[MAX_WIDTH][MAX_HEIGHT];
    int width = 0, height = 0;

    load_image(argv[1], image, &width, &height);
    convert_to_ascii(image, width, height, ascii);
    print_ascii(ascii, width, height);

    return 0;
}

void load_image(const char* filename, uint8_t image[MAX_WIDTH][MAX_HEIGHT], int* width, int* height)
{
    FILE* file = fopen(filename, "rb");

    if(file == NULL) {
        printf("ERROR: unable to open image file for reading\n");
        exit(-1);
    }

    // get the file size
    fseek(file, 0L, SEEK_END);
    long int file_size = ftell(file);
    rewind(file);

    // read the data into the image buffer
    fread(image, sizeof(uint8_t), file_size, file);

    // calculate the width and height based on file size
    *width = (int)(file_size / sizeof(uint8_t));
    *height = 1;

    for(int i = 0; i < *width; i++) {
        if(image[i][0] == '\n') {
            *height += 1;
        }
    }

    fclose(file);
}

void convert_to_ascii(uint8_t image[MAX_WIDTH][MAX_HEIGHT], int width, int height, char ascii[MAX_WIDTH][MAX_HEIGHT])
{
    if(width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("ERROR: image is too large\n");
        exit(-1);
    }

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            uint8_t pixel = image[x][y];
            int ascii_index = pixel * ASCII_CHAR_COUNT / 256;

            ascii[x][y] = ASCII_CHARS[ascii_index];
        }
    }
}

void print_ascii(char ascii[MAX_WIDTH][MAX_HEIGHT], int width, int height)
{
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            printf("%c", ascii[x][y]);
        }
        printf("\n");
    }
}