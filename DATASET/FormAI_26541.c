//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>

typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void apply_greyscale(Pixel *pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        unsigned char grey_value = (pixels[i].r + pixels[i].g + pixels[i].b) / 3;
        pixels[i].r = grey_value;
        pixels[i].g = grey_value;
        pixels[i].b = grey_value;
    }
}

void apply_sepia(Pixel *pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        int tr = pixels[i].r * 0.393 + pixels[i].g * 0.769 + pixels[i].b * 0.189;
        int tg = pixels[i].r * 0.349 + pixels[i].g * 0.686 + pixels[i].b * 0.168;
        int tb = pixels[i].r * 0.272 + pixels[i].g * 0.534 + pixels[i].b * 0.131;
        pixels[i].r = tr > 255 ? 255 : tr;
        pixels[i].g = tg > 255 ? 255 : tg;
        pixels[i].b = tb > 255 ? 255 : tb;
    }
}

void print_image(Pixel *pixels, int num_pixels) {
    printf("P3\n");
    printf("# CREATOR: Medieval Image Editor\n");
    printf("%d %d\n", num_pixels, 1);
    printf("255\n");

    for (int i = 0; i < num_pixels; i++) {
        printf("%d %d %d ", pixels[i].r, pixels[i].g, pixels[i].b);
    }
    printf("\n");
}

int main() {
    Pixel pixels[6] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {127, 127, 127}, {0, 0, 0}};

    printf("ORIGINAL IMAGE:\n");
    print_image(pixels, 6);

    apply_greyscale(pixels, 6);
    printf("\nGREYSCALE IMAGE:\n");
    print_image(pixels, 6);

    apply_sepia(pixels, 6);
    printf("\nSEPIA IMAGE:\n");
    print_image(pixels, 6);

    return 0;
}