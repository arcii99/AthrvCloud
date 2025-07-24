//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>

void convertToAscii(int* image, int rows, int cols){
    int i, j;
    const char* asciiChars = " .:oO8@";
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            int brightness = (image[i*cols + j] >> 16 & 0xff) + (image[i*cols + j] >> 8 & 0xff) + (image[i*cols + j] & 0xff);
            brightness /= 3;
            int asciiIndex = brightness * strlen(asciiChars) / 255;
            printf("%c%c", asciiChars[asciiIndex], asciiChars[asciiIndex]);
        }
        printf("\n");
    }
}

int main(){
    int image[4][4] = {
        {0xFF0000, 0xFF7F00, 0xFFFF00, 0x00FF00},
        {0x00FF7F, 0x00FFFF, 0x007FFF, 0x0000FF},
        {0x7F00FF, 0xFF00FF, 0x7F7F7F, 0xFFFFFF},
        {0x000000, 0xFFFFFF, 0x808080, 0xCC9966}
    };
    convertToAscii(&image[0][0], 4, 4);
    return 0;
}