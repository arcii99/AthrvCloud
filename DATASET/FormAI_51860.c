//FormAI DATASET v1.0 Category: Image Editor ; Style: Alan Touring
#include <stdio.h>

int main() {
    // Define variables for image size
    int width, height;

    // Declare arrays for storing image data
    unsigned char image_red[100][100];
    unsigned char image_green[100][100];
    unsigned char image_blue[100][100];

    // Read image size from user input
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    // Read image data from user input
    printf("Enter image data (RGB values, separated by spaces):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%hhu %hhu %hhu", &image_red[i][j], &image_green[i][j], &image_blue[i][j]);
        }
    }

    // Apply grayscale filter to image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char gray_value = (0.3 * image_red[i][j]) + (0.59 * image_green[i][j]) + (0.11 * image_blue[i][j]);
            image_red[i][j] = gray_value;
            image_green[i][j] = gray_value;
            image_blue[i][j] = gray_value;
        }
    }

    // Print grayscale image data
    printf("Grayscale image data:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%hhu %hhu %hhu ", image_red[i][j], image_green[i][j], image_blue[i][j]);
        }
        printf("\n");
    }

    return 0;
}