//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX 255

void flip_horizontal(unsigned char img[][WIDTH]);
void flip_vertical(unsigned char img[][WIDTH]);
void adjust_brightness(unsigned char img[][WIDTH], int value);
void adjust_contrast(unsigned char img[][WIDTH], float value);

int main()
{
    // Initialize an example image
    unsigned char image[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i < HEIGHT/2 && j < WIDTH/2)
                image[i][j] = MAX;
            else
                image[i][j] = 0;
        }
    }

    // Display the original image
    printf("Original Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    // Flip the image horizontally
    flip_horizontal(image);
    printf("\nFlipped Horizontally:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    // Flip the image vertically
    flip_vertical(image);
    printf("\nFlipped Vertically:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    // Adjust brightness
    adjust_brightness(image, 50);
    printf("\nBrightness Increased:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    // Adjust contrast
    adjust_contrast(image, 1.5);
    printf("\nContrast Increased:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void flip_horizontal(unsigned char img[][WIDTH]) {
    unsigned char temp;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH/2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][WIDTH-1-j];
            img[i][WIDTH-1-j] = temp;
        }
    }
}

void flip_vertical(unsigned char img[][WIDTH]) {
    unsigned char temp;
    for (int i = 0; i < HEIGHT/2; i++) {
        for (int j = 0; j < WIDTH; j++) {
            temp = img[i][j];
            img[i][j] = img[HEIGHT-1-i][j];
            img[HEIGHT-1-i][j] = temp;
        }
    }
}

void adjust_brightness(unsigned char img[][WIDTH], int value) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int new_value = img[i][j] + value;
            if (new_value > MAX)
                img[i][j] = MAX;
            else if (new_value < 0)
                img[i][j] = 0;
            else
                img[i][j] = new_value;
        }
    }
}

void adjust_contrast(unsigned char img[][WIDTH], float value) {
    float factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int new_value = factor * (img[i][j] - 128) + 128;
            if (new_value > MAX)
                img[i][j] = MAX;
            else if (new_value < 0)
                img[i][j] = 0;
            else
                img[i][j] = new_value;
        }
    }
}