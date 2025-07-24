//FormAI DATASET v1.0 Category: Image Classification system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 256

int main() {
    // initialize image data
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width, height;

    // read image from file
    FILE* file = fopen("image.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &width, &height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }
    fclose(file);

    // classify image
    int class = 0;
    // C code for image classification goes here...

    // output result
    printf("Class: %d\n", class);

    return 0;
}