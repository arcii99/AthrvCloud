//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the most basic image processing program you'll ever see!\n");
    printf("Let's start by flipping an image.\n");

    int image[50][50]; // our image is 50x50 pixels
    // code to populate the image

    // flip image horizontally
    for(int i=0; i<50; i++) {
        for(int j=0; j<25; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][49-j];
            image[i][49-j] = temp;
        }
    }
    printf("Image flipped horizontally!\n");

    // flip image vertically
    for(int i=0; i<25; i++) {
        for(int j=0; j<50; j++) {
            int temp = image[i][j];
            image[i][j] = image[49-i][j];
            image[49-i][j] = temp;
        }
    }
    printf("Image flipped vertically!\n");

    printf("Now, let's change the brightness and contrast of the image.\n");

    // code to change brightness and contrast

    printf("Wow, look at that transformation! Our image is now a masterpiece.\n");

    return 0;
}