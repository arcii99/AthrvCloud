//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void grayscale(unsigned char* img, int width, int height);
char ascii_pixel(unsigned char val);
void dump_to_file(char* filename, char* data);

// Main function
int main(int argc, char** argv) {
    // Read image file
    char* filename = argv[1];
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Get image dimensions
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for image data
    int size = 3 * width * height;
    unsigned char* img = (unsigned char*) malloc(size);

    // Read image data
    fread(img, sizeof(unsigned char), size, fp);
    fclose(fp);

    // Convert image to grayscale
    grayscale(img, width, height);

    // Convert image to ASCII art
    char* ascii = (char*) malloc(width*height);
    int idx = 0;

    for (int i = 0; i < size; i += 3) {
        unsigned char val = img[i];
        ascii[idx] = ascii_pixel(val);
        idx++;
    }

    // Dump ASCII art to file
    char* output_file = "output.txt";
    dump_to_file(output_file, ascii);

    // Free memory
    free(img);
    free(ascii);

    return 0;
}

// Convert image to grayscale
void grayscale(unsigned char* img, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char r = img[i];
        unsigned char g = img[i + 1];
        unsigned char b = img[i + 2];
        unsigned char val = 0.21*r + 0.72*g + 0.07*b;
        img[i] = img[i+1] = img[i+2] = val;
    }
}

// Convert pixel value to ASCII character
char ascii_pixel(unsigned char val) {
    const char* ascii_chars = " .:-=+*#%@";
    int length = strlen(ascii_chars);
    int index = round(val/255.0 * (length-1));
    return ascii_chars[index];
}

// Dump data to file
void dump_to_file(char* filename, char* data) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    fputs(data, fp);
    fclose(fp);
}