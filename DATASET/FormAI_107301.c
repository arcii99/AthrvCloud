//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    Pixel *pixels;
    size_t width;
    size_t height;
} Bitmap;

int read_bitmap(const char *filename, Bitmap *bitmap);
int write_bitmap(const char *filename, const Bitmap *bitmap);
void flip_horizontal(Bitmap *bitmap);
void flip_vertical(Bitmap *bitmap);
void adjust_brightness(Bitmap *bitmap, int value);
void adjust_contrast(Bitmap *bitmap, int value);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Bitmap bitmap = {0};
    if (!read_bitmap(argv[1], &bitmap)) {
        printf("Failed to read bitmap file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Image width: %lu\n", bitmap.width);
    printf("Image height: %lu\n", bitmap.height);

    // Flip the image horizontally.
    flip_horizontal(&bitmap);

    // Flip the image vertically.
    flip_vertical(&bitmap);

    // Adjust the brightness of the image.
    adjust_brightness(&bitmap, 50);

    // Adjust the contrast of the image.
    adjust_contrast(&bitmap, 50);

    if (!write_bitmap(argv[2], &bitmap)) {
        printf("Failed to write bitmap file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    printf("Done!\n");

    return EXIT_SUCCESS;
}

int read_bitmap(const char *filename, Bitmap *bitmap) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return 0;
    }

    // Read the bitmap header.
    unsigned char header[54] = {0};
    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        fclose(file);
        return 0;
    }

    // Extract the image metadata.
    bitmap->width = *(size_t *)(header + 18);
    bitmap->height = *(size_t *)(header + 22);
    size_t bitmap_size = *(size_t *)(header + 34);

    // Read the pixel data.
    bitmap->pixels = malloc(bitmap_size);
    if (!bitmap->pixels) {
        fclose(file);
        return 0;
    }

    if (fread(bitmap->pixels, sizeof(Pixel), bitmap_size / sizeof(Pixel), file) != bitmap_size / sizeof(Pixel)) {
        fclose(file);
        free(bitmap->pixels);
        return 0;
    }

    fclose(file);

    return 1;
}

int write_bitmap(const char *filename, const Bitmap *bitmap) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return 0;
    }

    // Write the bitmap header.
    unsigned char header[54] = {
      'B', 'M', // Signature
      0, 0, 0, 0, // File size
      0, 0, 0, 0, // Reserved
      54, 0, 0, 0, // Data offset
      40, 0, 0, 0, // Header size
      0, 0, 0, 0, // Image width
      0, 0, 0, 0, // Image height
      1, 0, // Number of color planes
      24, 0, // Bits per pixel
      0, 0, 0, 0, // Compression method
      0, 0, 0, 0, // Image size
      0, 0, 0, 0, // Horizontal resolution
      0, 0, 0, 0, // Vertical resolution
      0, 0, 0, 0, // Number of colors in palette
      0, 0, 0, 0 // Number of important colors
    };

    *(size_t *)(header + 2) = 54 + bitmap->width * bitmap->height * 3;
    *(size_t *)(header + 18) = bitmap->width;
    *(size_t *)(header + 22) = bitmap->height;
    *(size_t *)(header + 34) = bitmap->width * bitmap->height * sizeof(Pixel);

    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the pixel data.
    fwrite(bitmap->pixels, sizeof(Pixel), bitmap->width * bitmap->height, file);
    fclose(file);

    return 1;
}

void flip_horizontal(Bitmap *bitmap) {
    for (size_t y = 0; y < bitmap->height; y++) {
        for (size_t x = 0; x < bitmap->width / 2; x++) {
            Pixel tmp = bitmap->pixels[y * bitmap->width + x];
            bitmap->pixels[y * bitmap->width + x] = bitmap->pixels[y * bitmap->width + (bitmap->width - 1 - x)];
            bitmap->pixels[y * bitmap->width + (bitmap->width - 1 - x)] = tmp;
        }
    }
}

void flip_vertical(Bitmap *bitmap) {
    for (size_t y = 0; y < bitmap->height / 2; y++) {
        for (size_t x = 0; x < bitmap->width; x++) {
            Pixel tmp = bitmap->pixels[y * bitmap->width + x];
            bitmap->pixels[y * bitmap->width + x] = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x];
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x] = tmp;
        }
    }
}

void adjust_brightness(Bitmap *bitmap, int value) {
    for (size_t i = 0; i < bitmap->width * bitmap->height; i++) {
        Pixel *p = &bitmap->pixels[i];
        p->red = p->red + value > 255 ? 255 : p->red + value;
        p->green = p->green + value > 255 ? 255 : p->green + value;
        p->blue = p->blue + value > 255 ? 255 : p->blue + value;
    }
}

void adjust_contrast(Bitmap *bitmap, int value) {
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for (size_t i = 0; i < bitmap->width * bitmap->height; i++) {
        Pixel *p = &bitmap->pixels[i];
        p->red = factor * (p->red - 128) + 128;
        p->green = factor * (p->green - 128) + 128;
        p->blue = factor * (p->blue - 128) + 128;
    }
}