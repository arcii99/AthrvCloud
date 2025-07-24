//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    pixel data[MAX_WIDTH*MAX_HEIGHT];
    int width;
    int height;
} image;

void load_image(char *filename, image *img) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "The file %s could not be opened.\n", filename);
        exit(1);
    }
    char magic_num[3];
    fscanf(f, "%2s\n", magic_num);
    if (strcmp(magic_num, "P6") != 0) {
        fprintf(stderr, "The file %s is not a P6 PPM image.\n", filename);
        exit(1);
    }
    while (fgets(magic_num, sizeof(magic_num), f)) {
        if (magic_num[0] == '#') {
            continue;
        } else {
            break;
        }
    }
    int w, h, maxval;
    sscanf(magic_num, "%d %d\n%d\n", &w, &h, &maxval);
    img->width = w;
    img->height = h;
    unsigned char r, g, b;
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            fread(&r, sizeof(r), 1, f);
            fread(&g, sizeof(g), 1, f);
            fread(&b, sizeof(b), 1, f);
            img->data[i*w+j].r = r;
            img->data[i*w+j].g = g;
            img->data[i*w+j].b = b;
        }
    }
}

void save_image(char *filename, image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "The file %s could not be opened.\n", filename);
        exit(1);
    }
    fprintf(f, "P6\n%d %d\n255\n", img->width, img->height);
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            fwrite(&img->data[i*img->width+j].r, sizeof(img->data[i*img->width+j].r), 1, f);
            fwrite(&img->data[i*img->width+j].g, sizeof(img->data[i*img->width+j].g), 1, f);
            fwrite(&img->data[i*img->width+j].b, sizeof(img->data[i*img->width+j].b), 1, f);
        }
    }
}

void flip(image *img) {
    int i, j;
    pixel t_img[img->width*img->height];
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            t_img[(img->height-1-i)*img->width+j] = img->data[i*img->width+j];
        }
    }
    memcpy(img->data, t_img, sizeof(t_img));
}

void adjust_brightness(image *img, float value) {
    int i;
    for (i = 0; i < img->width*img->height; i++) {
        int r = img->data[i].r + (int)(value*255);
        int g = img->data[i].g + (int)(value*255);
        int b = img->data[i].b + (int)(value*255);
        img->data[i].r = (unsigned char)fmax(fmin(r, 255), 0);
        img->data[i].g = (unsigned char)fmax(fmin(g, 255), 0);
        img->data[i].b = (unsigned char)fmax(fmin(b, 255), 0);
    }
}

void adjust_contrast(image *img, float value) {
    float factor = (259*(value+255))/(255*(259-value));
    int i;
    for (i = 0; i < img->width*img->height; i++) {
        int r = factor * (img->data[i].r - 128) + 128;
        int g = factor * (img->data[i].g - 128) + 128;
        int b = factor * (img->data[i].b - 128) + 128;
        img->data[i].r = (unsigned char)fmax(fmin(r, 255), 0);
        img->data[i].g = (unsigned char)fmax(fmin(g, 255), 0);
        img->data[i].b = (unsigned char)fmax(fmin(b, 255), 0);
    }
}

int main(int argc, char **argv) {
    image img;
    load_image("input.ppm", &img);
    flip(&img);
    adjust_brightness(&img, -0.1);
    adjust_contrast(&img, 1.5);
    save_image("output.ppm", &img);
    printf("Done.\n");
    return 0;
}