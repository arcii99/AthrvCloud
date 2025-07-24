//FormAI DATASET v1.0 Category: Image Classification system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define number of rows and columns in image
#define ROWS 10
#define COLS 10

// Define function to classify image
int classify_image(char image[ROWS][COLS]) {
    int count_black = 0;
    int count_white = 0;
    // Count number of black and white pixels
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (image[i][j] == 'B') {
                count_black++;
            } else {
                count_white++;
            }
        }
    }
    // Classify image as mostly black or mostly white
    if (count_black > count_white) {
        return 1; // Black image
    } else {
        return 0; // White image
    }
}

// Main function to test image classification
int main() {
    // Define sample images
    char image1[ROWS][COLS] = {
        {'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W'},
        {'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W'}
    };
    char image2[ROWS][COLS] = {
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
    };
    // Classify sample images
    int result1 = classify_image(image1);
    int result2 = classify_image(image2);
    // Print results
    if (result1 == 1) {
        printf("Image 1 is mostly black.\n");
    } else {
        printf("Image 1 is mostly white.\n");
    }
    if (result2 == 1) {
        printf("Image 2 is mostly black.\n");
    } else {
        printf("Image 2 is mostly white.\n");
    }
    return 0;
}