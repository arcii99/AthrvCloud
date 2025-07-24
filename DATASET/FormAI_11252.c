//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum image size
#define MAX_SIZE 1000

// Define a structure for storing RGB values for each pixel
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

// Define a structure for storing the image data and its dimensions
typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_SIZE][MAX_SIZE];
} Image;

// Function to read an image from a file
void readImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Failed to open file: %s\n", filename);
        exit(1);
    }

    // Read the image width and height from the file
    fscanf(file, "%d %d", &image->width, &image->height);

    // Read the RGB values for each pixel from the file
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fscanf(file, "%d %d %d", &image->pixels[i][j].red, &image->pixels[i][j].green, &image->pixels[i][j].blue);
        }
    }

    fclose(file);
}

// Function to write an image to a file
void writeImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Failed to open file: %s\n", filename);
        exit(1);
    }

    // Write the image width and height to the file
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write the RGB values for each pixel to the file
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d %d %d ", image->pixels[i][j].red, image->pixels[i][j].green, image->pixels[i][j].blue);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to invert the colors of an image
void invertColors(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i][j].red = 255 - image->pixels[i][j].red;
            image->pixels[i][j].green = 255 - image->pixels[i][j].green;
            image->pixels[i][j].blue = 255 - image->pixels[i][j].blue;
        }
    }
}

// Function to grayscale an image
void grayscale(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int avg = (image->pixels[i][j].red + image->pixels[i][j].green + image->pixels[i][j].blue) / 3;
            image->pixels[i][j].red = avg;
            image->pixels[i][j].green = avg;
            image->pixels[i][j].blue = avg;
        }
    }
}

int main() {
    Image image;
    int choice;
    char filename[MAX_SIZE];

    printf("Enter the filename of the image to process: ");
    scanf("%s", filename);

    readImage(&image, filename);

    while (true) {
        printf("\n");
        printf("1. Invert Colors\n");
        printf("2. Grayscale\n");
        printf("3. Save Changes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invertColors(&image);
                printf("Colors inverted.\n");
                break;
            case 2:
                grayscale(&image);
                printf("Image grayscaled.\n");
                break;
            case 3:
                printf("Enter the filename to save the changes: ");
                scanf("%s", filename);
                writeImage(&image, filename);
                printf("Changes saved.\n");
                break;
            case 4:
                printf("Exiting image editor...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}