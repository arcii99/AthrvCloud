//FormAI DATASET v1.0 Category: Image Classification system ; Style: recursive
#include <stdio.h>

// Function to classify the image based on pixel values
void classify_image(int pixels[100][100], int row, int col)
{
    if (row == 0 || col == 0) {
        return; // base case
    } else {
        int pixel_value = pixels[row][col];
        if (pixel_value == 0) {
            printf("The image contains a black pixel at row %d and column %d\n", row, col);
        } else if (pixel_value == 255) {
            printf("The image contains a white pixel at row %d and column %d\n", row, col);
        } else {
            printf("The image contains a colored pixel at row %d and column %d\n", row, col);
        }
        classify_image(pixels, row - 1, col); // recursive call for left pixel
        classify_image(pixels, row, col - 1); // recursive call for top pixel
    }
}

int main()
{
    int pixels[100][100] = {{125, 0, 255}, {255, 125, 0}, {0, 255, 125}};
    int rows = 3, cols = 3;
    printf("Classifying image based on pixel values...\n");
    classify_image(pixels, rows - 1, cols - 1);
    return 0;
}