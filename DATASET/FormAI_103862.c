//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void flip_image(unsigned char image[], int width, int height);
void change_brightness(unsigned char image[], int width, int height, int brightness);
void change_contrast(unsigned char image[], int width, int height, float contrast);

int main()
{
    // Retro style image represented as a one-dimensional array of pixels
    // Each pixel has 3 values (R,G,B) between 0 and 255
    unsigned char image[] = {
        10, 20, 30, 40, 50, 60, 70, 80, 90,
        100, 110, 120, 130, 140, 150, 160, 170, 180,
        190, 200, 210, 220, 230, 240, 250, 0, 31
    };

    // Width and height of the image
    int width = 3;
    int height = 3;

    // Flip the image horizontally
    flip_image(image, width, height);

    // Increase brightness by 20
    change_brightness(image, width, height, 20);

    // Decrease contrast by 0.2
    change_contrast(image, width, height, 0.2);

    return 0;
}

// Flip the image horizontally
void flip_image(unsigned char image[], int width, int height)
{
    printf("Flipping image horizontally...\n");

    unsigned char tmp[width * 3];
    for (int row = 0; row < height; row++) {
        int left = row * width * 3;
        int right = (row + 1) * width * 3 - 3;
        for (int col = 0; col < width / 2; col++) {
            memcpy(tmp, &image[left + col * 3], 3);
            memcpy(&image[left + col * 3], &image[right - col * 3], 3);
            memcpy(&image[right - col * 3], tmp, 3);
        }
    }

    printf("Image flipped horizontally.\n");
}

// Increase or decrease brightness by a fixed amount
void change_brightness(unsigned char image[], int width, int height, int brightness)
{
    printf("Changing image brightness by %d...\n", brightness);

    for (int i = 0; i < width * height * 3; i++) {
        int val = image[i] + brightness;
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        image[i] = val;
    }

    printf("Image brightness changed.\n");
}

// Increase or decrease contrast by a percentage
void change_contrast(unsigned char image[], int width, int height, float contrast)
{
    printf("Changing image contrast by %.2f...\n", contrast);

    // Calculate grayscale value of each pixel
    float gray[width * height];
    for (int i = 0; i < width * height; i++) {
        int r = image[i * 3];
        int g = image[i * 3 + 1];
        int b = image[i * 3 + 2];
        gray[i] = 0.2126 * r + 0.7152 * g + 0.0722 * b;
    }

    // Find min and max grayscale value
    float min = gray[0];
    float max = gray[0];
    for (int i = 0; i < width * height; i++) {
        if (gray[i] < min) min = gray[i];
        if (gray[i] > max) max = gray[i];
    }

    // Adjust contrast
    float scale = (max - min) / 255;
    float shift = min;
    for (int i = 0; i < width * height * 3; i++) {
        int val = (image[i] - shift) / scale * contrast + 0.5 + shift;
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        image[i] = val;
    }

    printf("Image contrast changed.\n");
}