//FormAI DATASET v1.0 Category: Image Editor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of characters for file name
#define MAX_FILENAME_LENGTH 50

// Define maximum image size
#define MAX_IMAGE_SIZE 500

// Define pixel structure
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

// Define image structure
typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

// Function to read image from file
Image readImageFromFile(char* fileName) {
    Image img;
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("Error while opening file: %s\n", fileName);
        exit(1);
    }
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P3") != 0) {
        printf("Invalid file format. Only P3 format is supported.\n");
        exit(1);
    }
    fscanf(file, "%d %d", &img.width, &img.height);
    int maxColor;
    fscanf(file, "%d", &maxColor);
    if (maxColor != 255) {
        printf("Invalid color range. Only 255 color range is supported.\n");
        exit(1);
    }
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fscanf(file, "%d %d %d", &img.pixels[i][j].red, &img.pixels[i][j].green, &img.pixels[i][j].blue);
        }
    }
    fclose(file);
    return img;
}

// Function to write image to file
void writeImageToFile(char* fileName, Image img) {
    FILE* file = fopen(fileName, "wb");
    if (!file) {
        printf("Error while opening file: %s\n", fileName);
        exit(1);
    }
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", img.width, img.height);
    fprintf(file, "255\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fprintf(file, "%d %d %d ", img.pixels[i][j].red, img.pixels[i][j].green, img.pixels[i][j].blue);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to invert image colors
void invertColors(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j].red = 255 - img->pixels[i][j].red;
            img->pixels[i][j].green = 255 - img->pixels[i][j].green;
            img->pixels[i][j].blue = 255 - img->pixels[i][j].blue;
        }
    }
}

// Function to grayscale image
void grayscaleImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int average = (img->pixels[i][j].red + img->pixels[i][j].green + img->pixels[i][j].blue) / 3;
            img->pixels[i][j].red = average;
            img->pixels[i][j].green = average;
            img->pixels[i][j].blue = average;
        }
    }
}

// Function to apply sepia filter to image
void sepiaFilter(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int tr = (int)(0.393 * img->pixels[i][j].red + 0.769 * img->pixels[i][j].green + 0.189 * img->pixels[i][j].blue);
            int tg = (int)(0.349 * img->pixels[i][j].red + 0.686 * img->pixels[i][j].green + 0.168 * img->pixels[i][j].blue);
            int tb = (int)(0.272 * img->pixels[i][j].red + 0.534 * img->pixels[i][j].green + 0.131 * img->pixels[i][j].blue);
            img->pixels[i][j].red = tr > 255 ? 255 : tr;
            img->pixels[i][j].green = tg > 255 ? 255 : tg;
            img->pixels[i][j].blue = tb > 255 ? 255 : tb;
        }
    }
}

int main() {
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter image file name: ");
    scanf("%s", fileName);
    Image img = readImageFromFile(fileName);
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Invert colors\n");
        printf("2. Grayscale image\n");
        printf("3. Apply sepia filter\n");
        printf("4. Save image to file\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                invertColors(&img);
                printf("Colors inverted.\n");
                break;
            case 2:
                grayscaleImage(&img);
                printf("Image grayscaled.\n");
                break;
            case 3:
                sepiaFilter(&img);
                printf("Sepia filter applied.\n");
                break;
            case 4:
                char outputFile[MAX_FILENAME_LENGTH];
                printf("Enter output file name: ");
                scanf("%s", outputFile);
                writeImageToFile(outputFile, img);
                printf("Image saved to file: %s\n", outputFile);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);
    return 0;
}