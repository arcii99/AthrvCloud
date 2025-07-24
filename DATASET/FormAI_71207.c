//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the dimensions of the image
#define WIDTH 80
#define HEIGHT 40

// define the ASCII character set to use for conversion
static const char *ascii_chars = " .,:;ox%#@";

// load the image from a file
void load_image(unsigned char buffer[][WIDTH], char *filename)
{
    FILE *fp = fopen(filename, "rb");
    fread(buffer, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
}

// convert a pixel value to its ASCII representation
char pixel_to_ascii(unsigned char pixel)
{
    // calculate the index of the ASCII character to use
    int index = (int)(pixel / 25.5);

    // return the corresponding ASCII character
    return ascii_chars[index];
}

// convert the image to ASCII art and print it to the console
void print_ascii(unsigned char buffer[][WIDTH])
{
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            // convert the pixel value to its ASCII representation
            char ascii_pixel = pixel_to_ascii(buffer[y][x]);

            // print the ASCII character to the console
            printf("%c", ascii_pixel);
        }
        // print a newline character at the end of each row
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    // check if the user has provided a filename argument
    if(argc < 2) {
        printf("Please provide the path to the image file!\n");
        return 1;
    }

    // create a buffer to hold the image data
    unsigned char buffer[HEIGHT][WIDTH];

    // load the image from the file
    load_image(buffer, argv[1]);

    // print the ASCII art to the console
    print_ascii(buffer);

    return 0;
}