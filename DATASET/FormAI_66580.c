//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_VALUE 255

char c[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int main() {
    FILE *image_file;

    image_file = fopen("image.jpg", "rb"); // Replace "image.jpg" with the name of your image file

    if (!image_file) {
        printf("Error: could not open image file\n");
        return 1;
    }

    unsigned char image[WIDTH * HEIGHT];

    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, image_file);

    fclose(image_file);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel_value = image[i * WIDTH + j];
            int ascii_value = pixel_value / (MAX_VALUE / 10);
            printf("%c", c[ascii_value]);
        }
        printf("\n");
        usleep(10000); // Sleep for 10 milliseconds to slow down the output
    }

    return 0;
}