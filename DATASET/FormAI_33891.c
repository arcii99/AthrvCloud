//FormAI DATASET v1.0 Category: Image Classification system ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// define macros for image width and height
#define img_width 5
#define img_height 5

// function to classify the input image
int classify_image(int image[img_height][img_width]) {
    // initialize classification variable
    int image_class = -1;

    // compute mean of pixel values
    int total_pixels = 0;
    int pixel_sum = 0;
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            total_pixels++;
            pixel_sum += image[i][j];
        }
    }
    double pixel_mean = (double) pixel_sum / (double) total_pixels;

    // classify image based on brightness
    if (pixel_mean < 50.0) {
        image_class = 0;
    } else if (pixel_mean < 100.0) {
        image_class = 1;
    } else if (pixel_mean < 150.0) {
        image_class = 2;
    } else {
        image_class = 3;
    }

    // return classification result
    return image_class;
}

int main() {
    // initialize example image
    int example_image[img_height][img_width] = {
        {34, 65, 98, 107, 87},
        {76, 90, 112, 134, 113},
        {97, 123, 147, 155, 123},
        {85, 110, 132, 123, 78},
        {58, 78, 95, 76, 42}
    };

    // classify example image
    int image_class = classify_image(example_image);

    // print classification result
    switch (image_class) {
        case 0:
            printf("This image is very dark.\n");
            break;
        case 1:
            printf("This image is somewhat dark.\n");
            break;
        case 2:
            printf("This image is somewhat bright.\n");
            break;
        case 3:
            printf("This image is very bright.\n");
            break;
        default:
            printf("Error: Invalid image classification.\n");
            return 1;
    }

    return 0;
}