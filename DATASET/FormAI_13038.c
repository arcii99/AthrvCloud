//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_WIDTH 256
#define MAX_IMAGE_HEIGHT 256
#define MAX_ASCII_CHARS 64

// Define the grayscale color spectrum to map the ASCII characters to.
const char * GRAYSCALE_SCALE = " .:-=+*#%@";
const int NUM_GRAYSCALE_LEVELS = 10;

// Struct to hold the image data.
typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_WIDTH][MAX_IMAGE_HEIGHT];
} Image;

// Function to load the image data from a file.
Image loadImageFromFile(const char * filename) {
    Image img = {0};

    FILE * fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file '%s'", filename);
        exit(1);
    }

    char p6[3];
    fgets(p6, 4, fp);

    if (strcmp(p6, "P6\n") != 0) {
        printf("Error: Invalid image format");
        exit(1);
    }

    int width, height, maxval;
    fscanf(fp, "%d%d%d", &width, &height, &maxval);

    if (maxval != 255) {
        printf("Error: Unsupported image type");
        exit(1);
    }

    img.width = width;
    img.height = height;

    unsigned char tempPixel;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            fread(&tempPixel, sizeof(unsigned char), 1, fp);
            img.pixels[i][j] = tempPixel;
            fread(&tempPixel, sizeof(unsigned char), 1, fp);
            img.pixels[i][j] = (img.pixels[i][j] + tempPixel) / 2;
            fread(&tempPixel, sizeof(unsigned char), 1, fp);
            img.pixels[i][j] = (img.pixels[i][j] + tempPixel) / 3;
        }
    }

    fclose(fp);

    return img;
}

// Function to map the grayscale values to ASCII characters.
char mapGrayscaleToChar(int grayscaleVal) {
    int index = (int) ((float) grayscaleVal / 256.0 * (float) NUM_GRAYSCALE_LEVELS);
    return GRAYSCALE_SCALE[index];
}

// Function to convert the image to ASCII art.
void convertImageToAscii(const Image * img, char * output, int maxOutputSize) {
    char * outPtr = output;

    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            int grayscaleVal = (int) img->pixels[i][j];
            char asciiChar = mapGrayscaleToChar(grayscaleVal);
            *outPtr++ = asciiChar;
        }
        if ((outPtr - output) + 1 >= maxOutputSize) {
            printf("Output buffer too small\n");
            exit(1);
        }
        *outPtr++ = '\n';
    }

    if ((outPtr - output) >= maxOutputSize) {
        printf("Output buffer too small\n");
        exit(1);
    }

    *outPtr++ = '\0';
}

int main(int argc, const char ** argv) {
    if (argc != 3) {
        printf("USAGE: %s <input image file> <output text file>\n\n", argv[0]);
        printf("Converts a PPM image to ASCII art and writes it to a text file.\n");
        printf("The output file will contain ASCII art that approximates the input image.\n");
        printf("The ASCII characters used are based on the grayscale values of the image pixels.\n");
        printf("The output file size will be the same as the image dimensions.\n");
        printf("Example usage: %s input.ppm output.txt\n", argv[0]);
        exit(1);
    }

    // Load the image data.
    Image img = loadImageFromFile(argv[1]);

    // Allocate an output buffer
    char * output = (char *) malloc(MAX_IMAGE_WIDTH * (MAX_IMAGE_HEIGHT + 1) * sizeof(char));
    if (output == NULL) {
        printf("Error: Failed to allocate output buffer\n");
        exit(1);
    }

    // Convert the image to ASCII art.
    convertImageToAscii(&img, output, MAX_IMAGE_WIDTH * (MAX_IMAGE_HEIGHT + 1));

    // Write the output to a file.
    FILE * fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Could not open output file '%s'", argv[2]);
        exit(1);
    }

    fprintf(fp, "%s", output);
    fclose(fp);

    free(output);
    return 0;
}