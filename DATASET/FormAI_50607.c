//FormAI DATASET v1.0 Category: Image compression ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVELS 10

typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct Image {
    int width;
    int height;
    Pixel **pixels;
} Image;

Image *create_image(int width, int height) {
    // Allocate memory for the image
    Image *image = (Image *) malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error: Could not allocate memory");
        return NULL;
    }

    // Set the image width and height
    image->width = width;
    image->height = height;

    // Allocate memory for the pixels
    image->pixels = (Pixel **) malloc(sizeof(Pixel *) * height);
    if (image->pixels == NULL) {
        printf("Error: Could not allocate memory");
        free(image);
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        image->pixels[i] = (Pixel *) malloc(sizeof(Pixel) * width);
        if (image->pixels[i] == NULL) {
            printf("Error: Could not allocate memory");
            destroy_image(image);
            return NULL;
        }
    }

    return image;
}

void destroy_image(Image *image) {
    // Free up memory allocated for the pixels
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }

    // Free up memory allocated for the image
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, int red, int green, int blue) {
    // Ensure that the pixel coordinates are within bounds
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }

    // Set the pixel value
    image->pixels[y][x].red = red;
    image->pixels[y][x].green = green;
    image->pixels[y][x].blue = blue;
}

void get_pixel(Image *image, int x, int y, int *red, int *green, int *blue) {
    // Ensure that the pixel coordinates are within bounds
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        *red = 0;
        *green = 0;
        *blue = 0;
        return;
    }

    // Get the pixel value
    *red = image->pixels[y][x].red;
    *green = image->pixels[y][x].green;
    *blue = image->pixels[y][x].blue;
}

void compress_image(Image *image, int level, int x1, int y1, int x2, int y2) {
    // Base case: if the level is 0, set all pixels within the given
    // rectangle to the average color value
    if (level == 0) {
        int red_sum = 0, green_sum = 0, blue_sum = 0;

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                int red, green, blue;
                get_pixel(image, x, y, &red, &green, &blue);
                red_sum += red;
                green_sum += green;
                blue_sum += blue;
            }
        }

        int num_pixels = (x2 - x1 + 1) * (y2 - y1 + 1);
        int avg_red = red_sum / num_pixels;
        int avg_green = green_sum / num_pixels;
        int avg_blue = blue_sum / num_pixels;

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                set_pixel(image, x, y, avg_red, avg_green, avg_blue);
            }
        }

        return;
    }

    // Find the midpoints of the x and y coordinates
    int x_mid = (x1 + x2) / 2;
    int y_mid = (y1 + y2) / 2;

    // Compress the four quadrants recursively
    compress_image(image, level - 1, x1, y1, x_mid, y_mid);
    compress_image(image, level - 1, x_mid + 1, y1, x2, y_mid);
    compress_image(image, level - 1, x1, y_mid + 1, x_mid, y2);
    compress_image(image, level - 1, x_mid + 1, y_mid + 1, x2, y2);
}

int main() {
    // Create a test image
    Image *image = create_image(8, 8);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (x >= y) {
                set_pixel(image, x, y, 255, 0, 0);
            } else {
                set_pixel(image, x, y, 0, 255, 0);
            }
        }
    }

    // Compress the image recursively
    compress_image(image, 3, 0, 0, 7, 7);

    // Print the compressed image
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            int red, green, blue;
            get_pixel(image, x, y, &red, &green, &blue);
            printf("(%d, %d, %d) ", red, green, blue);
        }
        printf("\n");
    }

    // Free up memory allocated for the image
    destroy_image(image);

    return 0;
}