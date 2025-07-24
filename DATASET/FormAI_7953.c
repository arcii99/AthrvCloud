//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 1000
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS -255

typedef struct {
    int rows;
    int cols;
    unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} image_t;

typedef struct {
    int start_row;
    int end_row;
    image_t *image;
} thread_args_t;

typedef struct {
    int brightness;
    float contrast;
} edit_params_t;

// Function to flip the image vertically
void flip_image_v(image_t *image) {
    int rows = image->rows;
    int cols = image->cols;
    unsigned char temp_pixel;

    for(int i = 0; i < rows / 2; i++) {
        for(int j = 0; j < cols; j++) {
            temp_pixel = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[rows-i-1][j];
            image->pixels[rows-i-1][j] = temp_pixel;
        }
    }
}

// Function to change the brightness and contrast of the image
void edit_image(image_t *image, const edit_params_t *params) {
    int rows = image->rows;
    int cols = image->cols;
    float contrast = params->contrast;
    int brightness = params->brightness;
    int pixel_value;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            pixel_value = image->pixels[i][j];
            // Apply contrast
            pixel_value = factor * (pixel_value - 128) + 128;
            // Apply brightness
            pixel_value += brightness;
            // Check pixel limits
            pixel_value = pixel_value > MAX_BRIGHTNESS ? MAX_BRIGHTNESS : pixel_value;
            pixel_value = pixel_value < MIN_BRIGHTNESS ? MIN_BRIGHTNESS : pixel_value;
            image->pixels[i][j] = pixel_value; 
        }
    }
}

// Thread function to flip image horizontally
void *flip_image_h_thread(void *arg) {
    thread_args_t *args = (thread_args_t *) arg;
    int start_row = args->start_row;
    int end_row = args->end_row;
    image_t *image = args->image;
    unsigned char temp_pixel;

    for(int i = start_row; i < end_row; i++) {
        for(int j = 0; j < image->cols / 2; j++) {
            temp_pixel = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->cols-j-1];
            image->pixels[i][image->cols-j-1] = temp_pixel;
        }
    }

    pthread_exit(NULL);
}

int main() {
    int rows, cols, brightness;
    float contrast;
    char flip_direction;
    edit_params_t edit_params;
    char filename[256];
    char output_filename[256];
    pthread_t thread1, thread2;
    thread_args_t thread1_args, thread2_args;
    image_t image;

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    // Open file
    FILE *file = fopen(filename, "rb");
    if(!file) {
        printf("Could not open file.");
        return 1;
    }

    // Read header and image data
    char header[512];
    fgets(header, 512, file);
    sscanf(header, "P5 %d %d 255 ", &cols, &rows);
    fread(image.pixels, sizeof(unsigned char), rows * cols, file);
    fclose(file);

    image.rows = rows;
    image.cols = cols;

    // User input - Brightness and Contrast
    printf("Enter the brightness value (-255 to 255): ");
    scanf("%d", &brightness);

    printf("Enter the contrast value (e.g 1.5): ");
    scanf("%f", &contrast);

    edit_params.brightness = brightness;
    edit_params.contrast = contrast;

    // Apply image edits
    edit_image(&image, &edit_params);

    // User input - Flip direction
    printf("Do you want to flip the image horizontally or vertically? (h/v) ");
    scanf(" %c", &flip_direction);

    // Check for valid input
    if(flip_direction != 'h' && flip_direction != 'v') {
        printf("Invalid input! Please try again.");
        return 1;
    }

    if(flip_direction == 'v') {
        // Flip image vertically
        flip_image_v(&image);
    } else {
        // Flip image horizontally using threads
        thread1_args.start_row = 0;
        thread1_args.end_row = rows / 2;
        thread1_args.image = &image;

        thread2_args.start_row = rows / 2;
        thread2_args.end_row = rows;
        thread2_args.image = &image;

        pthread_create(&thread1, NULL, flip_image_h_thread, (void *) &thread1_args);
        pthread_create(&thread2, NULL, flip_image_h_thread, (void *) &thread2_args);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }

    // User input - Output filename
    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    // Write edited image to file
    file = fopen(output_filename, "wb");
    if(!file) {
        printf("Could not create output file.");
        return 1;
    }

    fprintf(file, "P5 %d %d 255 ", cols, rows);
    fwrite(image.pixels, sizeof(unsigned char), rows * cols, file);

    fclose(file);

    return 0;
}