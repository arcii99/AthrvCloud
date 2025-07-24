//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40

void convert(char *image, char *ascii) {
    int i,j;
    char ascii_char[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            int idx = *(image + (i * WIDTH) + j);
            int ascii_idx = (idx * 9) / 255;
            *(ascii + (i * WIDTH) + j) = ascii_char[ascii_idx];
        }
    }
}

int main(int argc, char *argv[]) {
    char *image_name = argv[1];
    char *ascii_name = argv[2];

    FILE *img_file = fopen(image_name, "rb");
    if(img_file == NULL) {
        printf("Error opening image file %s\n", image_name);
        return 1;
    }

    char *image_data = (char *) malloc(WIDTH * HEIGHT);
    fread(image_data, 1, WIDTH * HEIGHT, img_file);
    fclose(img_file);

    char *ascii_data = (char *) malloc(WIDTH * HEIGHT);
    convert(image_data, ascii_data);

    FILE *ascii_file = fopen(ascii_name, "wb");
    fwrite(ascii_data, 1, WIDTH * HEIGHT, ascii_file);
    fclose(ascii_file);

    free(image_data);
    free(ascii_data);

    return 0;
}