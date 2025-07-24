//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Flips the given image */
void flipImage(int *image, int width, int height) {
    int temp;
    for(int i = 0; i < height/2; i++) {
        for(int j = 0; j < width; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + (height-i-1)*width + j);
            *(image + (height-i-1)*width + j) = temp;
        }
    }
}

/* Adjusts the brightness of the given image */
void adjustBrightness(int *image, int width, int height, int brightnessLevel) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            *(image + i*width + j) += brightnessLevel;
            if(*(image + i*width + j) > 255) {
                *(image + i*width + j) = 255;
            } else if(*(image + i*width + j) < 0) {
                *(image + i*width + j) = 0;
            }
        }
    }
}

/* Adjusts the contrast of the given image */
void adjustContrast(int *image, int width, int height, float contrastLevel) {
    float factor = (259 * (contrastLevel + 255)) / (255 * (259 - contrastLevel));

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            *(image + i*width + j) = factor * (*(image + i*width + j) - 128) + 128;
            if(*(image + i*width + j) > 255) {
                *(image + i*width + j) = 255;
            } else if(*(image + i*width + j) < 0) {
                *(image + i*width + j) = 0;
            }
        }
    }
}

int main() {
    int width, height, *image;
    char filename[100];
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Unable to open file\n");
        return 0;
    }
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);
    image = (int*) malloc(width * height * sizeof(int));
    fread(image, sizeof(int), width * height, file);

    printf("What do you want to do with the image?\n");
    printf("1. Flip the image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            flipImage(image, width, height);
            printf("Image flipped successfully!\n");
            break;
        case 2:
            int brightnessLevel;
            printf("Enter the brightness level (between -255 and 255): ");
            scanf("%d", &brightnessLevel);
            adjustBrightness(image, width, height, brightnessLevel);
            printf("Brightness adjusted successfully!\n");
            break;
        case 3:
            float contrastLevel;
            printf("Enter the contrast level (between 0 and 255): ");
            scanf("%f", &contrastLevel);
            adjustContrast(image, width, height, contrastLevel);
            printf("Contrast adjusted successfully!\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    // Save the modified image to file
    fclose(file);
    file = fopen("modified_image.bin", "wb");
    fwrite(image, sizeof(int), width * height, file);
    fclose(file);

    free(image);
    return 0;
}