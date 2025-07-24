//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    // Welcome Message
    printf("Welcome to the Fractal Generation program, Mr. Holmes!\n");
    printf("I hope this will keep your mind engaged.\n");

    // Ask for user input
    int level;
    printf("How complex do you want your fractal to be, Mr. Holmes?: ");
    scanf("%d", &level);

    // Calculate the width and height of the image
    int width = pow(2, level);
    int height = pow(2, level);

    // Allocate memory for the image
    int **image = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(int));
    }

    // Generate the fractal (using the Barnsley Fern algorithm)
    int x = 0;
    int y = 0;
    for (int i = 0; i < pow(2, level); i++) {
        int r = rand() % 100;

        if (r == 0) {
            x = 0;
            y = floor(y/2);
        } else if (r >= 1 && r <= 7) {
            x = floor(0.5 * x);
            y = floor(0.5 * y);
        } else if (r >= 8 && r <= 15) {
            x = floor(0.5 * x) + pow(2, level-1);
            y = floor(0.5 * y);
        } else {
            x = floor(0.5 * x) + pow(2, level-1);
            y = floor(0.5 * y) + pow(2, level-1);
        }

        image[y][x] = 1;
    }

    // Output the image
    printf("\nHere is your fractal, Mr. Holmes:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    // Farewell message
    printf("I hope you enjoyed this little exercise, Mr. Holmes.\n");
    printf("Your mind always fascinates me.\n");
    printf("Until next time!\n");

    return 0;
}