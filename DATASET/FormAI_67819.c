//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>

/* Define image width, height, and maximum RGB value */
#define IMG_WIDTH  640
#define IMG_HEIGHT 480
#define MAX_RGB    255

/* Define function prototypes */
void flip_image(unsigned char *img_data);
void adjust_brightness_contrast(unsigned char *img_data, int brightness, float contrast);

int main() {
    unsigned char img_data[IMG_WIDTH * IMG_HEIGHT * 3];   /* Store image data as single array of unsigned chars */

    /* TODO: Read in image data from file or generate random data */

    /* Perform image processing */
    flip_image(img_data);
    adjust_brightness_contrast(img_data, 50, 1.5);

    /* TODO: Write out processed image data to file or display on screen */

    return 0;
}

/* Function to flip image vertically */
void flip_image(unsigned char *img_data) {
    int i, j, k;   /* Loop variables */
    unsigned char temp;

    for (j = 0; j < IMG_HEIGHT / 2; j++) {
        for (i = 0; i < IMG_WIDTH; i++) {
            for (k = 0; k < 3; k++) {
                /* Swap pixels across vertical axis */
                temp = img_data[(j * IMG_WIDTH + i) * 3 + k];
                img_data[(j * IMG_WIDTH + i) * 3 + k] = img_data[((IMG_HEIGHT - j - 1) * IMG_WIDTH + i) * 3 + k];
                img_data[((IMG_HEIGHT - j - 1) * IMG_WIDTH + i) * 3 + k] = temp;
            }
        }
    }
}

/* Function to adjust brightness and contrast of image */
void adjust_brightness_contrast(unsigned char *img_data, int brightness, float contrast) {
    int i, j, k;   /* Loop variables */
    float alpha, beta;

    /* Calculate scaling factors */
    alpha = contrast;
    beta = (float)brightness / MAX_RGB;

    /* Apply brightness and contrast correction */
    for (j = 0; j < IMG_HEIGHT; j++) {
        for (i = 0; i < IMG_WIDTH; i++) {
            for (k = 0; k < 3; k++) {
                img_data[(j * IMG_WIDTH + i) * 3 + k] = (unsigned char)(alpha * img_data[(j * IMG_WIDTH + i) * 3 + k] + beta * MAX_RGB);
            }
        }
    }
}