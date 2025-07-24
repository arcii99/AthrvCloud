//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// define the WIDTH and HEIGHT of the image
#define WIDTH 200
#define HEIGHT 200

// function to get the ASCII character based on the pixel value
char getASCII(unsigned char pixel) {
    //  return a space for pixel values less than 85
    if (pixel < 85) {
        return ' '; 
    }
    // return a dot for pixel values between 85 and 170
    else if (pixel >= 85 && pixel < 170) {
        return '.'; 
    }
    // return a dollar for pixel values greater than or equal to 170
    else {
        return '$';
    }
}

int main() {
    // open the image file in binary mode for reading
    FILE *imageFile = fopen("image.bin", "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file\n");
        return 1;
    }

    // create a buffer to hold the image data
    unsigned char buffer[WIDTH * HEIGHT];

    // read the image data into the buffer
    fread(buffer, sizeof(unsigned char), WIDTH * HEIGHT, imageFile);

    // close the image file
    fclose(imageFile);

    // print the ASCII art version of the image to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", getASCII(buffer[y * WIDTH + x]));
        }
        printf("\n");
    }

    // exit the program
    return 0;
}