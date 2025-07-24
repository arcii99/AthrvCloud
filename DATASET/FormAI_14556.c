//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Converts image to ASCII art
char* imageToAscii(char* path, int width, int height) {
    FILE *imageFile;
    imageFile = fopen(path, "rb");
    if (imageFile == NULL) {
        printf("Error: Invalid file path!\n");
        return NULL;
    }

    unsigned char *imageData = malloc(width * height);
    fread(imageData, width * height, 1, imageFile);
    fclose(imageFile);

    // Mapping ASCII characters based on brightness level
    const char *brightnessToChar = " .,-~:;=!*#$@";
    int brightnessRange = 255 / strlen(brightnessToChar);

    char* asciiArt = malloc((width + 1) * height); //allocate space for ASCII art

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int brightness = imageData[i * width + j];
            int charIndex = brightness / brightnessRange;
            asciiArt[i * (width+1) + j] = brightnessToChar[charIndex];
        }
        asciiArt[(i+1) * (width+1) - 1] = '\n'; //new line character at end of each row
    }
    asciiArt[(width+1) * height] = '\0'; //null terminator
    free(imageData); //free imageData
    return asciiArt;
}

int main() {
    char* ascii = imageToAscii("image1.jpg", 50, 25); //pass file path, width, and height
    if (ascii != NULL) {
        printf("%s", ascii); //prints ASCII art to console
        free(ascii); //free memory allocated for ASCII art
    }
    return 0;
}