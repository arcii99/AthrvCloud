//FormAI DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Define Image struct
typedef struct Image {
    int width;
    int height;
    int *pixels;
} Image;

// Declare function prototypes
int get_file_size(char *file_name);
void read_file_into_buffer(char *file_name, char *buffer, int buffer_size);
void write_buffer_to_file(char *file_name, char *buffer, int buffer_size);
Image *create_image(int width, int height);
void destroy_image(Image *image);
Image *read_image_from_file(char *file_name);
void write_image_to_file(char *file_name, Image *image);
Image *invert_colors(Image *image);
Image *grayscale(Image *image);

// Main function
int main() {
    char file_name[256];
    printf("Enter the name of the image file you want to edit: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = '\0'; // Remove trailing new line character

    // Read image from file
    Image *image = read_image_from_file(file_name);
    if (image == NULL) {
        perror("Error reading image file");
        exit(errno);
    }

    // Edit image
    Image *edited_image = invert_colors(image);
    destroy_image(image);
    if (edited_image == NULL) {
        perror("Error editing image");
        exit(errno);
    }

    // Write edited image to file
    char edited_file_name[256];
    sprintf(edited_file_name, "edited-%s", file_name);
    write_image_to_file(edited_file_name, edited_image);
    destroy_image(edited_image);

    return 0;
}

/**
 * Returns the size of a file in bytes.
 */
int get_file_size(char *file_name) {
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        return -1;
    }
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fclose(file);
    return size;
}

/**
 * Reads a file into a buffer.
 */
void read_file_into_buffer(char *file_name, char *buffer, int buffer_size) {
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        return;
    }
    fread(buffer, buffer_size, 1, file);
    fclose(file);
}

/**
 * Writes a buffer to a file.
 */
void write_buffer_to_file(char *file_name, char *buffer, int buffer_size) {
    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        return;
    }
    fwrite(buffer, buffer_size, 1, file);
    fclose(file);
}

/**
 * Creates a new image with the given width and height.
 */
Image *create_image(int width, int height) {
    Image *image = (Image *) malloc(sizeof(Image));
    if (image == NULL) {
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->pixels = (int *) malloc(sizeof(int) * width * height);
    if (image->pixels == NULL) {
        free(image);
        return NULL;
    }
    return image;
}

/**
 * Destroys an image and frees its memory.
 */
void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

/**
 * Reads an image from a file.
 */
Image *read_image_from_file(char *file_name) {
    // Open file
    int file_size = get_file_size(file_name);
    if (file_size == -1) {
        return NULL;
    }
    char *buffer = (char *) malloc(sizeof(char) * file_size);
    if (buffer == NULL) {
        return NULL;
    }
    read_file_into_buffer(file_name, buffer, file_size);

    // Parse image header
    int header_size = 18; // BMP header size is always 18 bytes
    int width = *(int *) (buffer + 18);
    int height = *(int *) (buffer + 22);

    // Create image
    Image *image = create_image(width, height);
    if (image == NULL) {
        return NULL;
    }

    // Copy pixel data into image
    int *pixels = image->pixels;
    int pixel_offset = *(int *) (buffer + 10); // Offset to pixel data in file
    int bytes_per_pixel = 3; // BMP uses 24-bit color
    char *pixel_data = buffer + pixel_offset;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int b = pixel_data[3*(width*i + j)];
            int g = pixel_data[3*(width*i + j) + 1];
            int r = pixel_data[3*(width*i + j) + 2];
            pixels[width*(height-i-1) + j] = (r << 16) | (g << 8) | b; // Store pixel in 32-bit format (R-G-B-A)
        }
    }

    // Clean up
    free(buffer);
    return image;
}

/**
 * Writes an image to a file.
 */
void write_image_to_file(char *file_name, Image *image) {
    // Calculate file size
    int header_size = 54; // BMP header size
    int padding = (4 - (image->width * 3) % 4) % 4; // Padding required to align rows on 4-byte boundaries
    int pixel_data_size = (image->width * 3 + padding) * image->height;
    int file_size = header_size + pixel_data_size;

    // Create file buffer
    char *buffer = (char *) malloc(sizeof(char) * file_size);
    if (buffer == NULL) {
        return;
    }

    // Write BMP header
    buffer[0] = 'B';
    buffer[1] = 'M';
    *(int *) (buffer + 2) = file_size;
    *(int *) (buffer + 10) = header_size;
    *(int *) (buffer + 14) = 40;
    *(int *) (buffer + 18) = image->width;
    *(int *) (buffer + 22) = image->height;
    *(short *) (buffer + 26) = 1;
    *(short *) (buffer + 28) = 24;
    *(int *) (buffer + 30) = 0;
    *(int *) (buffer + 34) = pixel_data_size;
    *(int *) (buffer + 38) = 11811;
    *(int *) (buffer + 42) = 11811;
    *(int *) (buffer + 46) = 0;
    *(int *) (buffer + 50) = 0;

    // Write pixel data
    int *pixels = image->pixels;
    char *pixel_data = buffer + header_size;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int pixel = pixels[image->width*(image->height-i-1) + j]; // Get pixel in 32-bit format (R-G-B-A)
            pixel_data[3*(image->width*i + j)] = pixel & 0xff;
            pixel_data[3*(image->width*i + j) + 1] = (pixel >> 8) & 0xff;
            pixel_data[3*(image->width*i + j) + 2] = (pixel >> 16) & 0xff;
        }
        for (int j = 0; j < padding; j++) {
            pixel_data[3*(image->width*i + image->width + j)] = 0; // Add padding byte(s) at end of each row
        }
    }

    // Write buffer to file
    write_buffer_to_file(file_name, buffer, file_size);

    // Clean up
    free(buffer);
}

/**
 * Inverts the colors of an image.
 */
Image *invert_colors(Image *image) {
    Image *edited_image = create_image(image->width, image->height);
    if (edited_image == NULL) {
        return NULL;
    }
    int *pixels = image->pixels;
    int *edited_pixels = edited_image->pixels;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int pixel = pixels[image->width*i + j];
            edited_pixels[image->width*i + j] = ~pixel; // Bitwise complement of each color component
        }
    }
    return edited_image;
}

/**
 * Converts an image to grayscale.
 */
Image *grayscale(Image *image) {
    Image *edited_image = create_image(image->width, image->height);
    if (edited_image == NULL) {
        return NULL;
    }
    int *pixels = image->pixels;
    int *edited_pixels = edited_image->pixels;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int pixel = pixels[image->width*i + j];
            int r = (pixel >> 16) & 0xff;
            int g = (pixel >> 8) & 0xff;
            int b = pixel & 0xff;
            int gray = (r + g + b) / 3; // Average of color components
            edited_pixels[image->width*i + j] = (gray << 16) | (gray << 8) | gray; // Set all color components to gray value
        }
    }
    return edited_image;
}