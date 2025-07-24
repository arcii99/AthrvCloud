//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>

//The image size in pixels.
#define WIDTH 100
#define HEIGHT 50

//The width (in characters) of the output image.
#define OUTPUT_WIDTH 150

int main(){

    //Open the image and convert it to grayscale.
    FILE *img_ptr = fopen("image.jpg", "rb");
    unsigned char img_data[WIDTH * HEIGHT];
    fread(img_data, 1, WIDTH * HEIGHT, img_ptr);
    fclose(img_ptr);

    //Create the output string which will contain the ASCII art.
    char output[OUTPUT_WIDTH * HEIGHT];

    //Convert each pixel to an ASCII character and put it in the output string.
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            int index = y * WIDTH + x;
            char pixel = img_data[index] < 128 ? '@' : ' ';
            output[y * OUTPUT_WIDTH + x] = pixel;
        }
        output[y * OUTPUT_WIDTH + WIDTH] = '\n';
    }

    //Print the ASCII art.
    printf("%s", output);

    return 0;
}