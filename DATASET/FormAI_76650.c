//FormAI DATASET v1.0 Category: Image Editor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Define a struct for storing image information
typedef struct {
    int width;
    int height;
    int pixels[100][100]; //Assume image will not exceed 100x100
} Image;

//Function to read image data from file and store in the Image struct
Image read_image(const char* filename) {
    Image img;
    FILE* file = fopen(filename, "rb");
    if(!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    //Read width and height from first two bytes of file
    fread(&img.width, sizeof(int), 1, file);
    fread(&img.height, sizeof(int), 1, file);
    //Read pixel data row by row
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            fread(&img.pixels[i][j], sizeof(int), 1, file);
        }
    }
    fclose(file);
    return img;
}

//Function to write image data to file
void write_image(const char* filename, Image img) {
    FILE* file = fopen(filename, "wb");
    if(!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    //Write width and height as first two bytes of file
    fwrite(&img.width, sizeof(int), 1, file);
    fwrite(&img.height, sizeof(int), 1, file);
    //Write pixel data row by row
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            fwrite(&img.pixels[i][j], sizeof(int), 1, file);
        }
    }
    fclose(file);
}

//Function to flip image vertically
void flip_vertically(Image *img) {
    for(int i = 0; i < img->height/2; i++) {
        for(int j = 0; j < img->width; j++) {
            //Swap 2 rows of pixels
            int temp = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[img->height-i-1][j];
            img->pixels[img->height-i-1][j] = temp;
        }
    }
}

//Function to convert image to grayscale
void grayscale(Image *img) {
    for(int i = 0; i < img->height; i++) {
        for(int j = 0; j < img->width; j++) {
            //Calculate grayscale value by taking average of red, green and blue values
            int red = (img->pixels[i][j] >> 16) & 0xFF;
            int green = (img->pixels[i][j] >> 8) & 0xFF;
            int blue = img->pixels[i][j] & 0xFF;
            int gray = (red + green + blue)/3;
            //Set red, green and blue values to grayscale value
            img->pixels[i][j] = (gray << 16) | (gray << 8) | gray;
        }
    }
}

int main() {
    //Read image data from file "image.bin"
    Image img = read_image("image.bin");
    //Flip image vertically
    flip_vertically(&img);
    //Convert image to grayscale
    grayscale(&img);
    //Write transformed image data to file "image_transformed.bin"
    write_image("image_transformed.bin", img);
    return 0;
}