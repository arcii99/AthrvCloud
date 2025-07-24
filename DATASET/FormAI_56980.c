//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>

int main() {
    // Define variables
    FILE *fp;
    int WIDTH = 100;
    int HEIGHT = 100;
    char ascii_chars[] = {' ', '.', ':', '+', '*', '?', 'X', 'O', '8', '%'};

    // Open Image File
    fp = fopen("image.png", "rb");
    if(fp == NULL) {
        printf("Error opening image file!");
        return 1;
    }

    // Read Image Data
    unsigned char image[WIDTH*HEIGHT];
    fread(image, sizeof(unsigned char), WIDTH*HEIGHT, fp);

    // Close Image File
    fclose(fp);

    // Convert Image to ASCII Art
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            // Calculate Index
            int index = i*WIDTH + j;
            
            // Set Pixel Value
            int pixel = image[index];
            
            // Map Pixel Value to ASCII Character
            int ascii_index = (pixel/25);
            printf("%c", ascii_chars[ascii_index]);
        }
        printf("\n");
    }

    return 0;
}