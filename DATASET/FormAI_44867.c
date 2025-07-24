//FormAI DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_IMAGE_WIDTH 1024
#define MAX_IMAGE_HEIGHT 1024
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

/* Function to allocate memory and initialize a new Image */
Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(width * sizeof(int));
        memset(image->pixels[i], 0, width * sizeof(int));
    }
    return image;
}

/* Function to free memory of a given Image */
void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

/* Function to read an image from file */
Image *read_image(char *filename) {
    FILE *fptr;
    char format[3];
    int width, height, max_value;
    Image *image;
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: File not found (%s)\n", filename);
        return NULL;
    }
    
    /* Read image format */
    fscanf(fptr, "%s\n", format);
    if (strcmp(format, "P2") != 0) {
        printf("Error: Unsupported format (%s)\n", format);
        return NULL;
    }
    
    /* Read image dimensions */
    fscanf(fptr, "%d %d\n", &width, &height);
    if (width > MAX_IMAGE_WIDTH || height > MAX_IMAGE_HEIGHT) {
        printf("Error: Image dimensions exceed maximum allowed\n");
        return NULL;
    }
    
    /* Read maximum pixel value */
    fscanf(fptr, "%d\n", &max_value);
    if (max_value > MAX_PIXEL_VALUE) {
        printf("Error: Maximum pixel value exceeds maximum allowed\n");
        return NULL;
    }
    
    /* Allocate memory for new image and read pixel data */
    image = create_image(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fptr, "%d", &image->pixels[i][j]);
        }
    }
    
    fclose(fptr);
    return image;
}

/* Function to write an image to file */
void write_image(Image *image, char *filename) {
    FILE *fptr;
    
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error: Unable to create file (%s)\n", filename);
        return;
    }
    
    /* Write header info */
    fprintf(fptr, "P2\n");
    fprintf(fptr, "%d %d\n", image->width, image->height);
    fprintf(fptr, "%d\n", MAX_PIXEL_VALUE);
    
    /* Write pixel data */
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(fptr, "%d ", image->pixels[i][j]);
        }
        fprintf(fptr, "\n");
    }
    
    fclose(fptr);
}

/* Function to invert the colors of a given Image */
Image *invert_colors(Image *image) {
    Image *new_image = create_image(image->width, image->height);
    
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            new_image->pixels[i][j] = MAX_PIXEL_VALUE - image->pixels[i][j];
        }
    }
    
    return new_image;
}

/* Function to flip a given Image horizontally */
Image *flip_horizontally(Image *image) {
    Image *new_image = create_image(image->width, image->height);
    
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            new_image->pixels[i][j] = image->pixels[i][image->width - 1 - j];
        }
    }
    
    return new_image;
}

/* Function to apply a given grayscale filter to a given Image */
Image *apply_grayscale_filter(Image *image) {
    Image *new_image = create_image(image->width, image->height);
    int gray_value;
    
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            gray_value = (int) (0.2989 * image->pixels[i][j] 
                              + 0.5870 * image->pixels[i][j] 
                              + 0.1140 * image->pixels[i][j]);
            new_image->pixels[i][j] = gray_value;
        }
    }
    
    return new_image;
}

/* Function to apply a given threshold filter to a given Image */
Image *apply_threshold_filter(Image *image, int threshold) {
    Image *new_image = create_image(image->width, image->height);
    
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->pixels[i][j] > threshold) {
                new_image->pixels[i][j] = MAX_PIXEL_VALUE;
            } else {
                new_image->pixels[i][j] = 0;
            }
        }
    }
    
    return new_image;
}

/* Function to display a given Image */
void display_image(Image *image) {
    printf("Image dimensions: %d x %d\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d ", image->pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    Image *image, *new_image;
    int threshold;
    
    /* Read input image filename from user */
    printf("Enter input image filename: ");
    fgets(filename, MAX_FILE_NAME_LENGTH, stdin);
    filename[strlen(filename) - 1] = '\0'; // Remove newline character
    
    /* Read input image from file */
    image = read_image(filename);
    if (image == NULL) {
        return 1;
    }
    
    /* Invert colors */
    new_image = invert_colors(image);
    write_image(new_image, "inverted.pgm");
    free_image(new_image);
    
    /* Flip horizontally */
    new_image = flip_horizontally(image);
    write_image(new_image, "flipped.pgm");
    free_image(new_image);
    
    /* Apply grayscale filter */
    new_image = apply_grayscale_filter(image);
    write_image(new_image, "grayscale.pgm");
    free_image(new_image);
    
    /* Apply threshold filter */
    printf("Enter threshold value (0-255): ");
    scanf("%d", &threshold);
    new_image = apply_threshold_filter(image, threshold);
    write_image(new_image, "threshold.pgm");
    free_image(new_image);
    
    /* Display original image */
    display_image(image);
    
    /* Free memory */
    free_image(image);
    
    return 0;
}