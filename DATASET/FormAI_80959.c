//FormAI DATASET v1.0 Category: Image compression ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// function to compress an image
void compress_image(char image[MAX_SIZE][MAX_SIZE], int width, int height) {
    int i, j, count;
    char current_char;
    for (i = 0; i < height; i++) {
        current_char = image[i][0];
        count = 1;
        for (j = 1; j < width; j++) {
            if (image[i][j] == current_char) {
                count++;
            } else {
                printf("%d%c", count, current_char);
                current_char = image[i][j];
                count = 1;
            }
        }
        printf("%d%c", count, current_char);
        if(i != height-1){
            printf("\n");
        }
    }
}

int main() {
    char image[MAX_SIZE][MAX_SIZE];
    int width, height, i, j;

    // initialize image to empty spaces
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            image[i][j] = ' ';
        }
    }

    // take input from user for image dimensions
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // take input from user for image
    printf("Enter the image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf(" %c", &image[i][j]);
        }
    }

    // call function to compress image
    compress_image(image, width, height);

    return 0;
}