//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 60

char mapping[] = {' ','.','\'',':','o','&','8','#','@'};

void printAsciiArt(int image[WIDTH*HEIGHT]);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "rb");
    if(!fp) {
        printf("Failed to open file %s\n", argv[1]);
        return 2;
    }
    int image[WIDTH*HEIGHT];
    size_t read = fread(image, sizeof(int), WIDTH*HEIGHT, fp);
    if(read != WIDTH*HEIGHT) {
        printf("Failed to read image from file %s\n", argv[1]);
        return 3;
    }
    fclose(fp);
    printAsciiArt(image);
    return 0;
}

void printAsciiArt(int image[WIDTH*HEIGHT]) {
    printf("\n");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int pixel = image[(i*WIDTH)+j];
            int index = (int)((pixel/255.0)*(sizeof(mapping)/sizeof(mapping[0])-1));
            printf("%c", mapping[index]);
        }
        printf("\n");
    }
    printf("\n");
}