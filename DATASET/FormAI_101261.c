//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The ASCII values to represent the image
char asciiChars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};
int numChars = 10;

//Function to convert RGB values to grayscale
int getGrayScale(int r, int g, int b) {
    return (0.2989 * r) + (0.5870 * g) + (0.1140 * b);
}

//Main function
int main(int argc, char *argv[]) {
    //Check if user provided an argument (the file path)
    if(argc < 2) {
        printf("Please provide an image file path.\n");
        return 1;
    }

    //Open the image file in binary read mode
    FILE *imageFile = fopen(argv[1], "rb");

    //Check if image file exists
    if(imageFile == NULL) {
        printf("The specified image file does not exist.\n");
        return 2;
    }

    //Read the header of the BMP image file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    //Extract image dimensions and colors from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    //Check image bit depth (must be 24 bits)
    if(bitDepth != 24) {
        printf("The image file is not a 24-bit BMP file.\n");
        fclose(imageFile);
        return 3;
    }

    //Calculate padding (if any) for each row
    int padding = (4 - (width * 3) % 4) % 4;

    //Allocate memory for image data
    unsigned char *imageData = (unsigned char*)malloc(sizeof(unsigned char) * (width * height * 3 + padding * height));

    //Read the image data into memory
    fread(imageData, sizeof(unsigned char), width * height * 3 + padding * height, imageFile);

    //Close the image file
    fclose(imageFile);

    //Loop through each pixel and convert to grayscale
    int grayImageData[height][width];
    int index = 0;
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            int r = imageData[index + 2];
            int g = imageData[index + 1];
            int b = imageData[index];
            int grayValue = getGrayScale(r, g, b);
            grayImageData[j][i] = grayValue;
            index += 3;
        }
        index += padding;
    }

    //Loop through each pixel and replace with corresponding ASCII character
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            int grayValue = grayImageData[j][i];
            int charIndex = (numChars * grayValue) / 256;
            char asciiChar = asciiChars[charIndex];
            printf("%c", asciiChar);
        }
        printf("\n");
    }

    //Free memory allocated for image data
    free(imageData);

    return 0;
}