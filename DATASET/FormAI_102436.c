//FormAI DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to classify the image
int classifyImage(int image[][3]) {
    int i, j, sum = 0;

    // Loop through the 2D array to calculate the sum of all pixel values
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum += image[i][j];
        }
    }

    // If the sum is less than 45, return 0 (black image)
    if (sum < 45) {
        return 0;
    }
    // If the sum is greater than or equal to 45 and less than 135, return 1 (gray image)
    else if (sum >= 45 && sum < 135) {
        return 1;
    }
    // If the sum is greater than or equal to 135, return 2 (white image)
    else {
        return 2;
    }
}

int main() {
    int image[3][3] = {
        {255, 255, 255},
        {0, 0, 0},
        {128, 128, 128}
    };

    // Output the classification of the image
    printf("The classification of the image is: %d", classifyImage(image));

    return 0;
}