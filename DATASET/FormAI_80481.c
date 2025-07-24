//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *ascii_chars = " .:-=+*#%@";
const int num_chars = 10;

void convert_to_ascii(unsigned char *image_data, int width, int height){
    int row, col;
    for (row = 0; row < height; row++){
        for(col = 0; col < width; col++){
            unsigned char pixel_value = image_data[row * width + col];
            int index = pixel_value * num_chars / 256;
            putchar(ascii_chars[index]);
        }
        putchar('\n');
    }
}

int main(){
    unsigned char image_data[] = {
        12, 34, 56, 78, 90,
        87, 65, 43, 21, 9,
        145, 167, 189, 201, 100,
        99, 88, 77, 66, 55
    };
    int width = 5, height = 4;
    convert_to_ascii(image_data, width, height);
    return 0;
}