//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define WIDTH 80
#define HEIGHT 60

// maps a color value to ascii char
char get_ascii_char(int color_value) {
    char ascii_chars[] = " .:-=+*#%@";
    int num_chars = 10;
    int char_value = color_value*num_chars/256;
    return ascii_chars[char_value];
}

// converts a image into ascii art 
void image_to_ascii(unsigned char image[][WIDTH]) {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            char ascii_char = get_ascii_char(image[i][j]);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

// sample function to generate random image
void generate_image(unsigned char image[][WIDTH]) {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            image[i][j] = rand() % 256;
        }
    }
}

// sample driver function to test ascii art conversion
int main() {
    unsigned char image[HEIGHT][WIDTH];
    generate_image(image);
    image_to_ascii(image);
    return 0;
}