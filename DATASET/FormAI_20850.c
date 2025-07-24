//FormAI DATASET v1.0 Category: Image compression ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int compress_image(char* image_data, int image_size) {
    int compressed_image_size = 0;
    for(int i = 0; i < image_size; i += 2) {
        int pixel = (int)image_data[i] << 8 | (int)image_data[i + 1];
        if(pixel >= 128) {
            compressed_image_size += printf("Pixel %d is greater than or equal to 128, compressing...\n", pixel);
            compressed_image_size += printf("01");
        } else {
            compressed_image_size += printf("Pixel %d is less than 128, compressing...\n", pixel);
            compressed_image_size += printf("00");
        }
    }
    return compressed_image_size;
}

int main() {
    char* image_data = "\x00\x80\x7F\xFF\x80\x00";
    int image_size = 6;
    int compressed_size = compress_image(image_data, image_size);
    printf("\nCompressed Image Size: %d bits\n", compressed_size);
    return 0;
}