//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
/** 
 * This program performs basic image processing tasks like flipping an image, changing brightness and contrast.
 * Input image format: RGB24 (24-bit uncompressed BMP)
 * Output image format: RGB24 (24-bit uncompressed BMP)
 * Minimum 50 lines. 
 * Be creative!
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Image;

/**
 * Function to load an image from a BMP file
 */
Image* load_image(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    // Read BMP header
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        printf("Error reading BMP header from file %s\n", filename);
        fclose(file);
        return NULL;
    }

    // Check if valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Invalid BMP file %s\n", filename);
        fclose(file);
        return NULL;
    }

    // Extract image parameters
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];
    if (bpp != 24) {
        printf("Invalid BMP file %s: only 24-bit RGB BMPs are supported\n", filename);
        fclose(file);
        return NULL;
    }

    // Allocate memory for image
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);

    // Read image data
    unsigned char* data = malloc(sizeof(unsigned char) * width * height * 3);
    if (fread(data, sizeof(unsigned char), width * height * 3, file) != width * height * 3) {
        printf("Error reading BMP data from file %s\n", filename);
        free(image->pixels);
        free(image);
        fclose(file);
        free(data);
        return NULL;
    }

    // Convert BMP data to pixel array
    for (int i = 0; i < width * height; i++) {
        image->pixels[i].b = data[i * 3];
        image->pixels[i].g = data[i * 3 + 1];
        image->pixels[i].r = data[i * 3 + 2];
    }

    // Cleanup
    fclose(file);
    free(data);

    return image;
}

/**
 * Function to save an image to a BMP file
 */
int save_image(char* filename, Image* image) {
    int width = image->width;
    int height = image->height;
    unsigned char* data = malloc(sizeof(unsigned char) * width * height * 3);

    // Convert pixel array to BMP data
    for (int i = 0; i < width * height; i++) {
        data[i * 3] = image->pixels[i].b;
        data[i * 3 + 1] = image->pixels[i].g;
        data[i * 3 + 2] = image->pixels[i].r;
    }

    // Open file for writing
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file %s for writing\n", filename);
        free(data);
        return 0;
    }

    // BMP header
    unsigned char header[54] = {
        'B', 'M',           // magic number
        0, 0, 0, 0,         // size of BMP file (set later)
        0, 0,               // reserved
        0, 0,               // reserved
        54, 0, 0, 0,        // offset to start of image data
        40, 0, 0, 0,        // size of BMP info header
        0, 0, 0, 0,         // width (set later)
        0, 0, 0, 0,         // height (set later)
        1, 0,               // number of color planes
        24, 0,              // bits per pixel
        0, 0, 0, 0,         // compression type
        0, 0, 0, 0,         // size of image data (set later)
        72, 0, 0, 0,        // horizontal resolution (pixels per meter)
        72, 0, 0, 0,        // vertical resolution (pixels per meter)
        0, 0, 0, 0,         // number of colors in palette
        0, 0, 0, 0          // number of important colors
    };

    // Update header with image parameters
    *(int*)&header[2] = 54 + width * height * 3;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(int*)&header[34] = width * height * 3;

    // Write BMP header
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write image data
    fwrite(data, sizeof(unsigned char), width * height * 3, file);

    // Cleanup
    fclose(file);
    free(data);
    return 1;
}

/**
 * Function to flip an image horizontally
 */
Image* flip_image_horizontally(Image* image) {
    int width = image->width;
    int height = image->height;
    Image* flipped = malloc(sizeof(Image));
    flipped->width = width;
    flipped->height = height;
    flipped->pixels = malloc(sizeof(Pixel) * width * height);

    // Flip image horizontally
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            flipped->pixels[y * width + x] = image->pixels[y * width + width - x - 1];
        }
    }

    return flipped;
}

/**
 * Function to adjust the brightness of an image
 */
Image* adjust_brightness(Image* image, int amount) {
    int width = image->width;
    int height = image->height;
    Image* adjusted = malloc(sizeof(Image));
    adjusted->width = width;
    adjusted->height = height;
    adjusted->pixels = malloc(sizeof(Pixel) * width * height);

    // Adjust brightness of image
    for (int i = 0; i < width * height; i++) {
        Pixel p = image->pixels[i];
        p.r += amount;
        p.g += amount;
        p.b += amount;
        adjusted->pixels[i] = p;
    }

    return adjusted;
}

/**
 * Function to adjust the contrast of an image
 */
Image* adjust_contrast(Image* image, float amount) {
    int width = image->width;
    int height = image->height;
    Image* adjusted = malloc(sizeof(Image));
    adjusted->width = width;
    adjusted->height = height;
    adjusted->pixels = malloc(sizeof(Pixel) * width * height);

    // Calculate contrast adjustment factor
    float factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));

    // Adjust contrast of image
    for (int i = 0; i < width * height; i++) {
        Pixel p = image->pixels[i];
        p.r = clamp((int)(factor * (p.r - 128) + 128), 0, 255);
        p.g = clamp((int)(factor * (p.g - 128) + 128), 0, 255);
        p.b = clamp((int)(factor * (p.b - 128) + 128), 0, 255);
        adjusted->pixels[i] = p;
    }

    return adjusted;
}

/**
 * Utility function to clamp a value between a minimum and maximum.
 */
int clamp(int value, int min, int max) {
    if (value < min) {
        return min;
    }
    else if (value > max) {
        return max;
    }
    else {
        return value;
    }
}

int main() {
    Image* input = load_image("input.bmp");
    if (!input) {
        return 1;
    }

    Image* flipped = flip_image_horizontally(input);
    Image* brightness = adjust_brightness(input, 50);
    Image* contrast = adjust_contrast(input, 1.5);

    save_image("flipped.bmp", flipped);
    save_image("brightness.bmp", brightness);
    save_image("contrast.bmp", contrast);

    free(input->pixels);
    free(input);

    free(flipped->pixels);
    free(flipped);

    free(brightness->pixels);
    free(brightness);

    free(contrast->pixels);
    free(contrast);

    return 0;
}