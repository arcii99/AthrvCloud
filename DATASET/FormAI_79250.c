//FormAI DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct image {
    int width;
    int height;
    struct pixel pixels[MAX_WIDTH][MAX_HEIGHT];
};

void load_image(struct image *img, char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error loading %s\n", filename);
        exit(1);
    }
    char header[54];
    fread(header, sizeof(char), 54, f);
    img->width = *(int*)&header[18];
    img->height = *(int*)&header[22];
    int padding = (4 - (img->width * 3) % 4) % 4;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            struct pixel p;
            fread(&p.b, sizeof(unsigned char), 1, f);
            fread(&p.g, sizeof(unsigned char), 1, f);
            fread(&p.r, sizeof(unsigned char), 1, f);
            img->pixels[j][i] = p;
        }
        fseek(f, padding, SEEK_CUR);
    }
    fclose(f);
}

void save_image(struct image *img, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error saving %s\n", filename);
        exit(1);
    }
    int padding = (4 - (img->width * 3) % 4) % 4;
    char header[54] = {
        0x42, 0x4d, // "BM"
        0, 0, 0, 0, // size
        0, 0,       // unused
        0, 0,       // unused
        54, 0, 0, 0, // offset to pixels
        40, 0, 0, 0, // header size
        0, 0, 0, 0, // width
        0, 0, 0, 0, // height
        1, 0,       // planes
        24, 0,      // bits per pixel
        0, 0, 0, 0, // compression
        0, 0, 0, 0, // image size
        0, 0, 0, 0, // horizontal resolution
        0, 0, 0, 0, // vertical resolution
        0, 0, 0, 0, // colors in color table
        0, 0, 0, 0, // important color count
    };
    *(int*)&header[2] = 54 + (img->width * img->height * 3) + (padding * img->height);
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    fwrite(header, sizeof(char), 54, f);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fwrite(&img->pixels[j][i].b, sizeof(unsigned char), 1, f);
            fwrite(&img->pixels[j][i].g, sizeof(unsigned char), 1, f);
            fwrite(&img->pixels[j][i].r, sizeof(unsigned char), 1, f);
        }
        for (int j = 0; j < padding; j++) {
            fwrite("\0", sizeof(char), 1, f);
        }
    }
    fclose(f);
}

void grayscale(struct image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned char gray = (img->pixels[j][i].r + img->pixels[j][i].g + img->pixels[j][i].b) / 3;
            img->pixels[j][i].r = gray;
            img->pixels[j][i].g = gray;
            img->pixels[j][i].b = gray;
        }
    }
}

void quantize(struct image *img, int levels) {
    int max_value = 255 / (levels - 1);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned char gray = (img->pixels[j][i].r + img->pixels[j][i].g + img->pixels[j][i].b) / 3;
            unsigned char new_value = max_value * (gray / max_value);
            img->pixels[j][i].r = new_value;
            img->pixels[j][i].g = new_value;
            img->pixels[j][i].b = new_value;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: image_editor <input_file> <output_file>\n");
        exit(1);
    }
    struct image img;
    load_image(&img, argv[1]);

    grayscale(&img);

    quantize(&img, 8);

    save_image(&img, argv[2]);

    return 0;
}