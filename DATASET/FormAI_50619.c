//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// Struct to hold image data
typedef struct {
    char* filepath;
    char* ascii_art;
} ImageData;

// Function to convert image to ASCII art
void* convert_to_ascii(void* arg) {
    ImageData* data = (ImageData*) arg;
    FILE *fp;
    char* pixel_val = " .:-=+*#%@";
    int ascii_len = strlen(pixel_val);
    
    // Open image file
    fp = fopen(data->filepath, "rb");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", data->filepath);
        pthread_exit(NULL);
    }

    // Find the image dimensions (assuming it is a square image)
    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    int dim = sqrt(image_size/3);
    rewind(fp);
    printf("Converting image: %s to ASCII art (dimensions: %d x %d)...\n", data->filepath, dim, dim);

    // Allocate memory for the ASCII art string
    data->ascii_art = (char*) malloc(dim * dim + dim + 1);
    char* ptr = data->ascii_art;

    // Read the pixel values and convert to ASCII art
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            int r, g, b;
            r = fgetc(fp);
            g = fgetc(fp);
            b = fgetc(fp);
            *ptr++ = pixel_val[(int)((0.2126*r + 0.7152*g + 0.0722*b) / 256.0 * ascii_len)];
        }
        *ptr++ = '\n';
    }
    *ptr++ = '\0';

    // Close the image file
    fclose(fp);

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [image filepaths]\n", argv[0]);
        return 0;
    }

    int num_images = argc - 1;
    pthread_t threads[num_images];
    ImageData image_data[num_images];

    // Convert each image to ASCII art in a separate thread
    for (int i = 0; i < num_images; i++) {
        image_data[i].filepath = argv[i+1];
        pthread_create(&threads[i], NULL, convert_to_ascii, (void*) &image_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_images; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the ASCII art for each image
    for (int i = 0; i < num_images; i++) {
        printf("%s:\n%s\n", image_data[i].filepath, image_data[i].ascii_art);
        free(image_data[i].ascii_art);
    }

    return 0;
}