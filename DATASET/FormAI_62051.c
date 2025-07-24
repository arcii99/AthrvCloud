//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>

int main() {
    int i, j;
    int img[10][10] = {
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0}
    };

    int white_pixels_count = 0;
    int black_pixels_count = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (img[i][j] == 0) {
                black_pixels_count++;
            } else {
                white_pixels_count++;
            }
        }
    }

    // Start of puzzle
    if (white_pixels_count == 0) {
        printf("This image is all black pixels. It could be a picture of the night sky. ");
    } else if (black_pixels_count == 0) {
        printf("This image is all white pixels. It could be a picture of a blank wall. ");
    } else if (white_pixels_count > 10 && black_pixels_count > 10) {
        printf("This image has lots of both black and white pixels. It could be a picture of a zebra with spots.");
    } else {
        printf("This image has an average amount of black and white pixels. It could be a picture of a panda or a dalmatian.");
    } 
    // End of puzzle

    return 0;
}