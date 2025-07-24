//FormAI DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 100
#define WIDTH 100

//Function to generate a grayscale image with random values
void generate_grayscale_image(int image[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 255;
        }
    }
}

//Function to flip the image vertically
void flip_image_vertically(int image[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT / 2; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int temp = image[i][j];
            image[i][j] = image[HEIGHT - i - 1][j];
            image[HEIGHT - i - 1][j] = temp;
        }
    }
}

//Function to add a surrealistic effect to the image
void add_surrealistic_effect(int image[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int r = rand() % 3;
            if(r == 0) {
                image[i][j] = (image[i][j] + 100) % 255;
            } else if(r == 1) {
                image[i][j] = (image[i][j] + 200) % 255;
            } else {
                image[i][j] = (image[i][j] - 50 + 255) % 255;
            }
        }
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    generate_grayscale_image(image);
    flip_image_vertically(image);
    add_surrealistic_effect(image);
    //Print the image to the console
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}