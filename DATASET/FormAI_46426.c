//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000 // Maximum length of file path and file name

// Read the image file from disk
void read_image(char* file_path, int** image, int* rows, int* cols) {
    FILE* fp = fopen(file_path, "r");
    int i, j;

    if (fp == NULL) {
        printf("Error opening file: %s\n", file_path);
        exit(1);
    }

    // Read image dimensions
    fscanf(fp, "%d %d", rows, cols);

    // Allocate memory for image array
    *image = (int*)malloc(*rows * (*cols) * sizeof(int));

    // Read pixel values
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            fscanf(fp, "%d", (*image) + i*(*cols) + j);
        }
    }

    fclose(fp);
}

// Write the image to disk
void write_image(char* file_path, int* image, int rows, int cols) {
    FILE* fp = fopen(file_path, "w");
    int i, j;

    if (fp == NULL) {
        printf("Error opening file: %s\n", file_path);
        exit(1);
    }

    fprintf(fp, "%d %d\n", rows, cols);

    // Write pixel values
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(fp, "%d ", *(image + i*cols + j));
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Flip the image horizontally
void flip_horizontal(int* image, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols/2; j++) {
            // Swap the pixels on the left and right sides of the image
            int temp = *(image + i*cols + j);
            *(image + i*cols + j) = *(image + i*cols + cols-1-j);
            *(image + i*cols + cols-1-j) = temp;
        }
    }
}

// Rotate the image 90 degrees clockwise
void rotate_clockwise(int** image, int* rows, int* cols) {
    int i, j;

    // Allocate memory for rotated image array
    int* rotated_image = (int*)malloc(*cols * (*rows) * sizeof(int));

    for (i = 0; i < *cols; i++) {
        for (j = 0; j < *rows; j++) {
            // Rotate the pixel by 90 degrees clockwise
            *(rotated_image + i*(*rows) + j) = *(*image + (*rows-j-1)*(*cols) + i);
        }
    }

    // Free memory used by original image array
    free(*image);

    // Update image dimensions
    int temp = *rows;
    *rows = *cols;
    *cols = temp;

    // Update image pointer to point to rotated image array
    *image = rotated_image;
}

int main() {
    char file_path[MAX_LENGTH];
    int* image = NULL;
    int rows, cols;
    int option;

    // Read image file path from user
    printf("Enter the file path of the image: ");
    scanf("%s", file_path);

    // Read image file from disk
    read_image(file_path, &image, &rows, &cols);

    // User menu
    printf("\nMenu:\n");
    printf("1. Flip image horizontally\n");
    printf("2. Rotate image 90 degrees clockwise\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1: flip_horizontal(image, rows, cols);
                break;
        case 2: rotate_clockwise(&image, &rows, &cols);
                break;
        default: printf("Invalid choice");
                 exit(1);
    }

    // Write modified image to disk
    write_image(file_path, image, rows, cols);

    printf("Image successfully modified and saved to disk.\n");

    // Free memory used by image array
    free(image);

    return 0;
}