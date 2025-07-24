//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Assuming we have an image stored in an array
    int image[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // Let's classify the image as either a square or a rectangle
    int height = 10;
    int width = 10;
    int is_square = 1;   // Assuming it's square

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j] == 0) {
                // If we encounter a black pixel, it's a rectangle
                is_square = 0;
                break;
            }
        }
    }

    if (is_square) {
        printf("The image is a square.\n");
    } else {
        printf("The image is a rectangle.\n");
    }

    // Done. Let's exit.
    return 0;
}