//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>

int main() {

    int width, height;
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    int art[height][width]; // 2D array to hold the pixel art

    printf("Enter the pixel art (use 0 and 1 for off and on pixels):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &art[i][j]);
        }
    }

    printf("Here's your pixel art:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (art[i][j] == 1) {
                printf("*"); // print asterisk for on pixels
            } else {
                printf(" "); // print space for off pixels
            }
        }
        printf("\n"); // go to next line after each row
    }

    return 0;
}