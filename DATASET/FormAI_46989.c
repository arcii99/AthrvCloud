//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>

#define WIDTH 50
#define HEIGHT 50

// converts pixel to character by comparing its brightness to a set of predefined values
char get_char(int pixel_value) {
    const char *brightness_char = " .:-=+*#%@";
    int brightness_levels = strlen(brightness_char) - 1;
    int brightness = (int)(((double)pixel_value / 255.0) * (double)brightness_levels);
    return brightness_char[brightness];
}

// converts a portion of the image to ascii art 
void convert_to_ascii(char *output, int *image, int x, int y, int width, int height, int level) {
    if (level < 1) {
        return;
    }

    // calculate brightness of each pixel and convert it to a character
    for (int j = y; j < y + height; j++) {
        for (int i = x; i < x + width; i++) {
            char c = get_char(image[i + j * WIDTH]);
            output[i - x + (j - y) * width] = c;
        }
    }
    
    // print the ascii art to the console
    printf("%.*s\n", width, output);
    
    // recursively divide the image into smaller sections and convert them to ascii art
    int new_width = width / 2;
    int new_height = height / 2;
    convert_to_ascii(output, image, x, y, new_width, new_height, level - 1);
    convert_to_ascii(output, image, x + new_width, y, new_width, new_height, level - 1);
    convert_to_ascii(output, image, x, y + new_height, new_width, new_height, level - 1);
    convert_to_ascii(output, image, x + new_width, y + new_height, new_width, new_height, level - 1);
}

int main() {
    // test image, random grayscale values
    int image[WIDTH * HEIGHT];
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }

    char output[WIDTH * HEIGHT + HEIGHT + 1];
    output[0] = '\0';
    convert_to_ascii(output, image, 0, 0, WIDTH, HEIGHT, 4);
    return 0;
}