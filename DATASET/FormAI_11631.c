//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50
#define MAX_PIXEL_VALUE 255

char ascii[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
// The above array contains the ASCII characters to replace the image pixels with.
// Each character corresponds to a pixel value in the range [0, 9].

// Struct for Image data
typedef struct {
    int width;
    int height;
    int data[MAX_WIDTH*MAX_HEIGHT];
} Image;

// Initializes an image with all pixels set to 0.
void init_image(Image* image, int width, int height)
{
    image->width = width;
    image->height = height;
    for(int i=0; i<width*height; i++)
        image->data[i] = 0;
}

// Replaces each pixel value in the image with an appropriate ASCII character.
void convert_to_ascii(Image* image)
{
    int index;
    for(int i=0; i<image->height; i++) {
        for(int j=0; j<image->width; j++) {
            index = (int)((float)(image->data[i*image->width+j])/(float)(MAX_PIXEL_VALUE+1) * 10);
            printf("%c", ascii[index]);
        }
        printf("\n");
    }
}

int main()
{
    Image image;
    init_image(&image, MAX_WIDTH, MAX_HEIGHT);
    // Code to initialize Image with pixel values would go here.
    // For example, you might read in an image file and store the pixel values in image.data.
    // For the sake of this example, let's just set some random pixel values.
    for(int i=0; i<image.height; i++) {
        for(int j=0; j<image.width; j++) {
            image.data[i*image.width+j] = rand() % (MAX_PIXEL_VALUE+1);
        }
    }
    // Print the ASCII representation of the image.
    convert_to_ascii(&image);
    return 0;
}