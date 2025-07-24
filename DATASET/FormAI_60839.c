//FormAI DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for image width and height
#define IMAGE_WIDTH 500
#define IMAGE_HEIGHT 500

int main()
{
    // Initialize image with random pixel values
    int image[IMAGE_WIDTH][IMAGE_HEIGHT];

    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            image[i][j] = rand() % 256;
        }
    }

    // Display original image
    printf("Original Image:\n\n");

    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    // Invert the colors of the image
    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            image[i][j] = 255 - image[i][j];
        }
    }

    // Display inverted image
    printf("Inverted Image:\n\n");

    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    // Flip the image vertically
    int temp_row[IMAGE_WIDTH];
    for(int i=0; i<IMAGE_HEIGHT/2; i++){
        memcpy(temp_row, image[i], IMAGE_WIDTH*sizeof(int));
        memcpy(image[i], image[IMAGE_HEIGHT-1-i], IMAGE_WIDTH*sizeof(int));
        memcpy(image[IMAGE_HEIGHT-1-i], temp_row, IMAGE_WIDTH*sizeof(int));
    }

    // Display flipped image
    printf("Flipped Image:\n\n");

    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;
}