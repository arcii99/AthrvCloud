//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image struct
typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function to read image from file
Image* read_image(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read header information
    char magic[3];
    int width, height, maxval;
    fscanf(fp, "%2s\n", magic);
    if (strcmp(magic, "P6") != 0) {
        printf("Error: invalid file format\n");
        fclose(fp);
        return NULL;
    }
    fscanf(fp, "%d %d\n%d\n", &width, &height, &maxval);

    // Allocate memory for image data
    Image* image = malloc(sizeof(Image));
    if (!image) {
        printf("Error: could not allocate memory\n");
        fclose(fp);
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    if (!image->data) {
        printf("Error: could not allocate memory\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    // Read image data
    size_t bytes_read = fread(image->data, 1, width * height * 3, fp);
    if (bytes_read != width * height * 3) {
        printf("Error: could not read image data\n");
        fclose(fp);
        free(image->data);
        free(image);
        return NULL;
    }

    fclose(fp);
    return image;
}

// Function to write image to file
void write_image(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }

    // Write header information
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);

    // Write image data
    size_t bytes_written = fwrite(image->data, 1, image->width * image->height * 3, fp);
    if (bytes_written != image->width * image->height * 3) {
        printf("Error: could not write image data\n");
        fclose(fp);
        return;
    }

    fclose(fp);
}

// Function to apply a cyberpunk style filter to the image
void cyberpunk_filter(Image* image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        // Boost red and blue channels
        image->data[i] = (unsigned char) (image->data[i] * 1.5);
        image->data[i + 2] = (unsigned char) (image->data[i + 2] * 1.5);

        // Invert green channel
        image->data[i + 1] = (unsigned char) (255 - image->data[i + 1]);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Read image from file
    Image* image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Apply filter
    cyberpunk_filter(image);

    // Write image to file
    write_image(argv[2], image);

    // Free memory
    free(image->data);
    free(image);

    return 0;
}