//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x,y;
    unsigned char r,g,b;
} pixel;

int main(int argc, char *argv[]) {
    if(argc != 5) {
        fprintf(stderr, "Usage: %s <input file> <output file> <brightness> <contrast>\n", argv[0]);
        return -1;
    }

    FILE *f = fopen(argv[1], "rb");
    if(f == NULL) {
        perror(argv[1]);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    size_t width = sqrt(size/3);
    fseek(f, 0, SEEK_SET);

    pixel *image = calloc(width*width, sizeof(pixel));
    if(image == NULL) {
        perror("calloc failed");
        fclose(f);
        return -1;
    }

    fread(image, size, 1, f);
    fclose(f);

    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);

    for(size_t i = 0; i < width*width; i++) {
        int r = image[i].r+brightness;
        int g = image[i].g+brightness;
        int b = image[i].b+brightness;

        if(r < 0) r = 0;
        if(g < 0) g = 0;
        if(b < 0) b = 0;
        if(r > 255) r = 255;
        if(g > 255) g = 255;
        if(b > 255) b = 255;

        int lum = 0.2126*r+0.7152*g+0.0722*b;
        int lum2 = (lum-128)*contrast+128;
        int dr = lum2-lum;

        r += dr;
        g += dr;
        b += dr;

        if(r < 0) r = 0;
        if(g < 0) g = 0;
        if(b < 0) b = 0;
        if(r > 255) r = 255;
        if(g > 255) g = 255;
        if(b > 255) b = 255;

        image[i].r = r;
        image[i].g = g;
        image[i].b = b;
    }

    FILE *f_out = fopen(argv[2], "wb");
    if(f_out == NULL) {
        perror(argv[2]);
        return -1;
    }

    fwrite(image, size, 1, f_out);
    fclose(f_out);

    free(image);

    printf("Done!\n");

    return 0;
}