//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define CHAR_WIDTH 6
#define CHAR_HEIGHT 10
#define CHAR_STEP 25
#define MAX_CHAR ((MAX_WIDTH / CHAR_WIDTH) * (MAX_HEIGHT / CHAR_HEIGHT))

void convert_to_ascii(char* img_fname, char* output_fname);
void draw_ascii(char* output, char* img_buf, int width, int height, int char_step);

char get_ascii_char(int gray_value);
char* load_image(char* img_fname, int* img_width, int* img_height);
void save_ascii(char* output_fname, char* output);

int main() {
    char* img_fname = "image.jpg";
    char* output_fname = "output.txt";

    convert_to_ascii(img_fname, output_fname);

    printf("Conversion complete!\n");

    return 0;
}

void convert_to_ascii(char* img_fname, char* output_fname) {
    int img_width, img_height;
    char* img_buf = load_image(img_fname, &img_width, &img_height);
    if (img_buf == NULL) {
        printf("Error loading image %s\n", img_fname);
        return;
    }

    char output[MAX_WIDTH * MAX_HEIGHT];
    memset(output, ' ', sizeof(output)); // Initialize the output with space characters

    draw_ascii(output, img_buf, img_width, img_height, CHAR_STEP);
    save_ascii(output_fname, output);

    free(img_buf);
}

void draw_ascii(char* output, char* img_buf, int width, int height, int char_step) {
    int i, j, char_idx;
    for (i = 0; i < height; i+=char_step) {
        for (j = 0; j < width; j+=CHAR_WIDTH) {
            char_idx = ((i / CHAR_HEIGHT) * (width / CHAR_WIDTH)) + (j / CHAR_WIDTH);
            output[char_idx] = get_ascii_char(img_buf[(i * width) + j]);
        }
    }
}

char get_ascii_char(int gray_value) {
    const char ascii_chars[] = " .:-=+*#%@";
    const int num_chars = sizeof(ascii_chars)-1;

    int step = 255 / num_chars;
    int char_idx = gray_value / step;

    return ascii_chars[char_idx];
}

char* load_image(char* img_fname, int* img_width, int* img_height) {
    FILE* fp = fopen(img_fname, "rb");
    if (fp == NULL) {
        return NULL;
    }

    // Read the BMP header
    char header[54];
    int bytes_read = fread(header, 1, 54, fp);
    if (bytes_read != 54 || header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return NULL;
    }

    // Get width and height information
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(short*)&header[28];

    if (bpp != 24) {    // We only support 24-bit BMP images
        fclose(fp);
        return NULL;
    }

    *img_width = width;
    *img_height = height;

    char* img_buf = malloc(width*height);
    memset(img_buf, 0, width*height);

    int row_size = ((width*3 + 3) / 4) * 4;
    char row_data[row_size];

    int i, j;
    for (i = 0; i < height; i++) {
        bytes_read = fread(row_data, 1, row_size, fp);
        if (bytes_read != row_size) {
            fclose(fp);
            free(img_buf);
            return NULL;
        }

        for (j = 0; j < width; j++) {
            img_buf[(i * width) + j] = (row_data[j*3] + row_data[j*3+1] + row_data[j*3+2]) / 3;
        }
    }

    fclose(fp);
    return img_buf;
}

void save_ascii(char* output_fname, char* output) {
    FILE* fp = fopen(output_fname, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(output, 1, MAX_CHAR, fp);
    fclose(fp);
}