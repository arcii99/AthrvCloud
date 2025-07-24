//FormAI DATASET v1.0 Category: Image compression ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct image {
    char format[3];             // image format, can be P5 or P6
    int width;                  // image width
    int height;                 // image height
    int max_value;              // maximum pixel value
    unsigned char **pixels;     // pixels of the image
};

struct image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    struct image *img = (struct image*) malloc(sizeof(struct image));
    if(img == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }

    // read image format
    fscanf(fp, "%s\n", img->format);

    // read image width, height and max value
    fscanf(fp, "%d %d\n%d\n", &img->width, &img->height, &img->max_value);

    // allocate memory for pixels
    img->pixels = (unsigned char**) malloc(sizeof(unsigned char*) * img->height);
    if(img->pixels == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < img->height; i++) {
        img->pixels[i] = (unsigned char*) malloc(sizeof(unsigned char) * img->width * 3);
        if(img->pixels[i] == NULL) {
            fprintf(stderr, "Error: memory allocation failed\n");
            exit(1);
        }
    }

    // read pixel values
    if(strcmp(img->format, "P6") == 0) {
        fread(img->pixels[0], 1, img->width * img->height * 3, fp);
    }
    else if(strcmp(img->format, "P5") == 0) {
        for(int i = 0; i < img->height; i++) {
            fread(img->pixels[i], 1, img->width, fp);
        }

        // convert grayscale pixels to RGB pixels
        for(int i = 0; i < img->height; i++) {
            for(int j = 0; j < img->width; j++) {
                img->pixels[i][j * 3] = img->pixels[i][j];
                img->pixels[i][j * 3 + 1] = img->pixels[i][j];
                img->pixels[i][j * 3 + 2] = img->pixels[i][j];
            }
        }
    }
    else {
        fprintf(stderr, "Error: unsupported image format\n");
        exit(1);    
    }

    fclose(fp);
    return img;
}

void write_image(struct image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // write image format, width, height and max value
    fprintf(fp, "%s\n%d %d\n%d\n", img->format, img->width, img->height, img->max_value);

    // write pixel values
    if(strcmp(img->format, "P6") == 0) {
        fwrite(img->pixels[0], 1, img->width * img->height * 3, fp);
    }
    else if(strcmp(img->format, "P5") == 0) {
        unsigned char *grayscale_pixels = (unsigned char*) malloc(sizeof(unsigned char) * img->width * img->height);
        if(grayscale_pixels == NULL) {
            fprintf(stderr, "Error: memory allocation failed\n");
            exit(1);
        }

        // convert RGB pixels to grayscale pixels
        for(int i = 0; i < img->height; i++) {
            for(int j = 0; j < img->width; j++) {
                grayscale_pixels[i * img->width + j] = (img->pixels[i][j * 3] + img->pixels[i][j * 3 + 1] + img->pixels[i][j * 3 + 2]) / 3;
            }
        }

        fwrite(grayscale_pixels, 1, img->width * img->height, fp);
        free(grayscale_pixels);
    }
    else {
        fprintf(stderr, "Error: unsupported image format\n");
        exit(1);
    }

    fclose(fp);
}

struct image *compress_image(struct image *img, int quality) {
    struct image *compressed_img = (struct image*) malloc(sizeof(struct image));
    if(compressed_img == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }

    // copy image format, width, height and max value
    strcpy(compressed_img->format, img->format);
    compressed_img->width = img->width;
    compressed_img->height = img->height;
    compressed_img->max_value = img->max_value;

    // allocate memory for compressed pixels
    compressed_img->pixels = (unsigned char**) malloc(sizeof(unsigned char*) * compressed_img->height);
    if(compressed_img->pixels == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < compressed_img->height; i++) {
        compressed_img->pixels[i] = (unsigned char*) malloc(sizeof(unsigned char) * compressed_img->width * 3);
        if(compressed_img->pixels[i] == NULL) {
            fprintf(stderr, "Error: memory allocation failed\n");
            exit(1);
        }
    }

    // compress pixel values
    double q = 1.0 * quality / 100;
    for(int i = 0; i < compressed_img->height; i++) {
        for(int j = 0; j < compressed_img->width; j++) {
            unsigned char r = img->pixels[i][j * 3];
            unsigned char g = img->pixels[i][j * 3 + 1];
            unsigned char b = img->pixels[i][j * 3 + 2];
            unsigned char y = 0.299 * r + 0.587 * g + 0.114 * b;
            unsigned char u = -0.169 * r - 0.331 * g + 0.5 * b + 128;
            unsigned char v = 0.5 * r - 0.419 * g - 0.081 * b + 128;
            int yq = round(q * (y - 128)) + 128;
            int uq = round(q * (u - 128)) + 128;
            int vq = round(q * (v - 128)) + 128;
            compressed_img->pixels[i][j * 3] = yq;
            compressed_img->pixels[i][j * 3 + 1] = uq;
            compressed_img->pixels[i][j * 3 + 2] = vq;
        }
    }

    return compressed_img;
}

struct image *decompress_image(struct image *compressed_img, int quality) {
    struct image *img = (struct image*) malloc(sizeof(struct image));
    if(img == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }

    // copy image format, width, height and max value
    strcpy(img->format, compressed_img->format);
    img->width = compressed_img->width;
    img->height = compressed_img->height;
    img->max_value = compressed_img->max_value;

    // allocate memory for pixels
    img->pixels = (unsigned char**) malloc(sizeof(unsigned char*) * img->height);
    if(img->pixels == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < img->height; i++) {
        img->pixels[i] = (unsigned char*) malloc(sizeof(unsigned char) * img->width * 3);
        if(img->pixels[i] == NULL) {
            fprintf(stderr, "Error: memory allocation failed\n");
            exit(1);
        }
    }

    // decompress pixel values
    double q = 1.0 * quality / 100;
    for(int i = 0; i < img->height; i++) {
        for(int j = 0; j < img->width; j++) {
            int yq = compressed_img->pixels[i][j * 3];
            int uq = compressed_img->pixels[i][j * 3 + 1];
            int vq = compressed_img->pixels[i][j * 3 + 2];
            unsigned char y = round(yq / q) + 128;
            unsigned char u = round(uq / q) + 128;
            unsigned char v = round(vq / q) + 128;
            unsigned char r = y + 1.403 * (v - 128);
            unsigned char g = y - 0.344 * (u - 128) - 0.714 * (v - 128);
            unsigned char b = y + 1.773 * (u - 128);
            img->pixels[i][j * 3] = r;
            img->pixels[i][j * 3 + 1] = g;
            img->pixels[i][j * 3 + 2] = b;
        }
    }

    return img;
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Usage: %s input_image output_image quality\n", argv[0]);
        exit(1);
    }

    char *input_image = argv[1];
    char *output_image = argv[2];
    int quality = atoi(argv[3]);

    if(quality < 1 || quality > 100) {
        fprintf(stderr, "Error: quality must be between 1 and 100\n");
        exit(1);
    }

    struct image *img = read_image(input_image);
    struct image *compressed_img = compress_image(img, quality);
    struct image *decompressed_img = decompress_image(compressed_img, quality);
    write_image(decompressed_img, output_image);

    for(int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);

    for(int i = 0; i < compressed_img->height; i++) {
        free(compressed_img->pixels[i]);
    }
    free(compressed_img->pixels);
    free(compressed_img);

    for(int i = 0; i < decompressed_img->height; i++) {
        free(decompressed_img->pixels[i]);
    }
    free(decompressed_img->pixels);
    free(decompressed_img);

    return 0;
}