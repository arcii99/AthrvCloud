//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>

/* Define the height and width of the image */
#define HEIGHT 10
#define WIDTH 10

/* Define the maximum brightness and contrast value of the image */
#define MAX_BRIGHTNESS 255
#define MAX_CONTRAST 100

/* Define the image array */
int image[HEIGHT][WIDTH];

/* Function to flip the image horizontally */
void flipHorizontal() {
    int temp;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH/2; j++) {
            /* Swap the pixels in the row */
            temp = image[i][j];
            image[i][j] = image[i][WIDTH-1-j];
            image[i][WIDTH-1-j] = temp;
        }
    }
}

/* Function to change the brightness of the image */
void changeBrightness(int value) {
    /* Loop through the image and apply the brightness change */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            /* Add the brightness value to the pixel */
            image[i][j] += value;

            /* Check if the brightness value exceeds the maximum */
            if (image[i][j] > MAX_BRIGHTNESS) {
                image[i][j] = MAX_BRIGHTNESS;
            }
        }
    }
}

/* Function to change the contrast of the image */
void changeContrast(int value) {
    float factor = (259.0 * (value + MAX_CONTRAST)) / (255.0 * (259.0 - value));

    /* Loop through the image and apply the contrast change */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            /* Apply the contrast formula to the pixel */
            image[i][j] = (int) (factor * (image[i][j] - 128) + 128);

            /* Check if the contrast value exceeds the maximum */
            if (image[i][j] > MAX_BRIGHTNESS) {
                image[i][j] = MAX_BRIGHTNESS;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

/* Main function */
int main() {
    /* Initialize the image array with random values */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % MAX_BRIGHTNESS;
        }
    }

    /* Flip the image horizontally */
    flipHorizontal();

    /* Change the brightness of the image */
    changeBrightness(50);

    /* Change the contrast of the image */
    changeContrast(50);

    /* Print the modified image */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}