//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_FILENAME_LENGTH 256

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel data[MAX_WIDTH][MAX_HEIGHT];
} Image;

void readImage(Image *image, char *filename) {
    char fullFilename[MAX_FILENAME_LENGTH] = "images/";
    strcat(fullFilename, filename);
    FILE *file = fopen(fullFilename, "rb");
    if (file == NULL) {
        printf("Failed to read the file.\n");
        exit(1);
    }
    fscanf(file, "P6\n%d %d\n255\n", &image->width, &image->height);
    fread(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void writeImage(Image *image, char *filename) {
    char fullFilename[MAX_FILENAME_LENGTH] = "output/";
    strcat(fullFilename, filename);
    FILE *file = fopen(fullFilename, "wb");
    if (file == NULL) {
        printf("Failed to write the file.\n");
        exit(1);
    }
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void greyscaleImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char pixelValue = (image->data[i][j].red + image->data[i][j].green + image->data[i][j].blue) / 3;
            image->data[i][j].red = pixelValue;
            image->data[i][j].green = pixelValue;
            image->data[i][j].blue = pixelValue;
        }
    }
}

void invertImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i][j].red = 255 - image->data[i][j].red;
            image->data[i][j].green = 255 - image->data[i][j].green;
            image->data[i][j].blue = 255 - image->data[i][j].blue;
        }
    }
}

void brightnessContrastImage(Image *image, int brightness, float contrast) {
    float contrastFactor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i][j].red = (contrastFactor * (image->data[i][j].red - 128)) + 128 + brightness;
            image->data[i][j].green = (contrastFactor * (image->data[i][j].green - 128)) + 128 + brightness;
            image->data[i][j].blue = (contrastFactor * (image->data[i][j].blue - 128)) + 128 + brightness;
        }
    }
}

void blurImage(Image *image, int radius) {
    float kernel[2*radius+1][2*radius+1];
    float sigma = 1.0 * radius / 3.0;
    float normalizer = 0.0;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            kernel[i+radius][j+radius] = exp(-(i*i+j*j)/(2*sigma*sigma));
            normalizer += kernel[i+radius][j+radius];
        }
    }
    for (int i = 0; i < 2*radius+1; i++) {
        for (int j = 0; j < 2*radius+1; j++) {
            kernel[i][j] /= normalizer;
        }
    }
    Image blurredImage = *image;
    for (int i = radius; i < image->height-radius; i++) {
        for (int j = radius; j < image->width-radius; j++) {
            float totalRed = 0.0;
            float totalGreen = 0.0;
            float totalBlue = 0.0;
            for (int k = -radius; k <= radius; k++) {
                for (int l = -radius; l <= radius; l++) {
                    float weight = kernel[k+radius][l+radius];
                    totalRed += image->data[i+k][j+l].red * weight;
                    totalGreen += image->data[i+k][j+l].green * weight;
                    totalBlue += image->data[i+k][j+l].blue * weight;
                }
            }
            blurredImage.data[i][j].red = (unsigned char) totalRed;
            blurredImage.data[i][j].green = (unsigned char) totalGreen;
            blurredImage.data[i][j].blue = (unsigned char) totalBlue;
        }
    }
    *image = blurredImage;
}


int main() {
    Image image;
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the image: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;
    readImage(&image, filename);
    printf("Original image loaded.\n");

    int operation = -1;
    while (operation != 0) {
        printf("\n");
        printf("Select an operation:\n");
        printf("1. Greyscale\n");
        printf("2. Invert colors\n");
        printf("3. Adjust brightness and contrast\n");
        printf("4. Blur\n");
        printf("0. Save and exit\n");
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                greyscaleImage(&image);
                printf("Greyscale applied.\n");
                break;
            case 2:
                invertImage(&image);
                printf("Colors inverted.\n");
                break;
            case 3:
                printf("Enter brightness adjustment: ");
                int brightness;
                scanf("%d", &brightness);
                printf("Enter contrast adjustment (positive values increase contrast, negative values decrease contrast): ");
                float contrast;
                scanf("%f", &contrast);
                brightnessContrastImage(&image, brightness, contrast);
                printf("Brightness and contrast adjusted.\n");
                break;
            case 4:
                printf("Enter blur radius (in pixels): ");
                int radius;
                scanf("%d", &radius);
                blurImage(&image, radius);
                printf("Image blurred.\n");
                break;
            case 0:
                break;
            default:
                printf("Invalid operation.\n");
        }
    }

    writeImage(&image, filename);
    printf("Image saved as '%s'.\n", filename);
    return 0;
}