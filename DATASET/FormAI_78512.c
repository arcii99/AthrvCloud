//FormAI DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define MAX_ITERATIONS 500
#define WIDTH 400
#define HEIGHT 400
#define MIN_X -1.5
#define MAX_X 1.5
#define MIN_Y -1.5
#define MAX_Y 1.5

void write_bitmap(float **bitmap);

int main() {
    float **bitmap = (float **)malloc(sizeof(float *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        bitmap[i] = (float *)malloc(sizeof(float) * WIDTH);
    }
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            double x = MIN_X + col * ((MAX_X - MIN_X) / WIDTH);
            double y = MIN_Y + row * ((MAX_Y - MIN_Y) / HEIGHT);
            double complex z = x + y * I;
            double complex c = z;
            int iterations;
            for (iterations = 0; iterations < MAX_ITERATIONS; iterations++) {
                z = z * z + c;
                if (cabs(z) > 2) {
                    break;
                }
            }
            bitmap[row][col] = iterations / (float)MAX_ITERATIONS;
        }
    }
    write_bitmap(bitmap);
    for (int i = 0; i < HEIGHT; i++) {
        free(bitmap[i]);
    }
    free(bitmap);
    return 0;
}

void write_bitmap(float **bitmap) {
    FILE *output_file;
    output_file = fopen("fractal.bmp", "wb");
    int file_size = 54 + 3 * WIDTH * HEIGHT;
    unsigned char bmp_file_header[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmp_info_header[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};
    unsigned char bmp_pad[3] = {0,0,0};
    bmp_file_header[2] = (unsigned char)(file_size);
    bmp_file_header[3] = (unsigned char)(file_size >> 8);
    bmp_file_header[4] = (unsigned char)(file_size >> 16);
    bmp_file_header[5] = (unsigned char)(file_size >> 24);
    bmp_info_header[4] = (unsigned char)(WIDTH);
    bmp_info_header[5] = (unsigned char)(WIDTH >> 8);
    bmp_info_header[6] = (unsigned char)(WIDTH >> 16);
    bmp_info_header[7] = (unsigned char)(WIDTH >> 24);
    bmp_info_header[8] = (unsigned char)(HEIGHT);
    bmp_info_header[9] = (unsigned char)(HEIGHT >> 8);
    bmp_info_header[10] = (unsigned char)(HEIGHT >> 16);
    bmp_info_header[11] = (unsigned char)(HEIGHT >> 24);
    fwrite(bmp_file_header, sizeof(unsigned char), 14, output_file);
    fwrite(bmp_info_header, sizeof(unsigned char), 40, output_file);
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            unsigned char pixel[3];
            pixel[0] = (unsigned char)(bitmap[row][col] * 255);
            pixel[1] = (unsigned char)(bitmap[row][col] * 255);
            pixel[2] = (unsigned char)(bitmap[row][col] * 255);
            fwrite(pixel, sizeof(unsigned char), 3, output_file);
        }
        fwrite(bmp_pad, sizeof(unsigned char), (4 - (WIDTH * 3) % 4) % 4, output_file);
    }
    fclose(output_file);
}