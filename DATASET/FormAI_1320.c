//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>

int main() {

    // Initialize variables
    int image[100][100];
    int height, width;

    // Prompt user for image dimensions
    printf("Enter image height: ");
    scanf("%d", &height);

    printf("Enter image width: ");
    scanf("%d", &width);

    // Prompt user for pixel values
    printf("Enter pixel values (0 - 255):\n");
    for(int i = 0; i < height; i++) {
        printf("Row %d:\n", i+1);
        for(int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Classify image
    int count_black = 0, count_white = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(image[i][j] < 128) {
                count_black++;
            } else {
                count_white++;
            }
        }
    }

    // Output classification
    if(count_black > count_white) {
        printf("This image is mostly black\n");
    } else {
        printf("This image is mostly white\n");
    }

    return 0;
}