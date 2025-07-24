//FormAI DATASET v1.0 Category: Image compression ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   printf("Wow, I am so surprised to be writing an image compression program!\n");
   printf("But I'm ready to impress you with my skills!\n");
   printf("First, I'm going to load an image file.\n");

   // Let's pretend we have a 10x10 pixel image of colors
   int image[10][10] = {
        {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
        {255, 0, 0, 0, 0, 0, 0, 0, 0, 255},
        {255, 0, 255, 255, 255, 255, 255, 255, 0, 255},
        {255, 0, 255, 0, 0, 0, 0, 255, 0, 255},
        {255, 0, 255, 0, 255, 255, 0, 255, 0, 255},
        {255, 0, 255, 0, 255, 255, 0, 255, 0, 255},
        {255, 0, 255, 0, 0, 0, 0, 255, 0, 255},
        {255, 0, 255, 255, 255, 255, 255, 255, 0, 255},
        {255, 0, 0, 0, 0, 0, 0, 0, 0, 255},
        {255, 255, 255, 255, 255, 255, 255, 255, 255, 255}
    };

    // Now we need to compress the image by removing duplicate rows
    printf("Let's compress the image by removing duplicate rows!\n");
    int compressed_image[10][10];
    int num_unique_rows = 0;
    for (int i = 0; i < 10; i++) {
        int row_already_exists = 0;
        // Check if this row already exists in the compressed image
        for (int j = 0; j < num_unique_rows; j++) {
            if (memcmp(image[i], compressed_image[j], sizeof(image[i])) == 0) {
                row_already_exists = 1;
                break;
            }
        }
        // If it's a new row, add it to compressed image
        if (!row_already_exists) {
            memcpy(compressed_image[num_unique_rows], image[i], sizeof(image[i]));
            num_unique_rows++;
        }
    }

    // Let's print the compressed image to make sure it worked
    printf("Wow, we compressed the image to %d unique rows!\n", num_unique_rows);
    for (int i = 0; i < num_unique_rows; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", compressed_image[i][j]);
        }
        printf("\n");
    }

    printf("That's it for the image compression program! I hope you're impressed!\n");
    return 0;
}