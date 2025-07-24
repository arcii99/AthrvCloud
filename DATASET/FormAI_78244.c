//FormAI DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the size of the image */
#define SIZE 10

/* Define the maximum value for a pixel */
#define MAX_PIXEL_VALUE 255

/* Define a structure for a pixel */
struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

/* Function to generate a random pixel */
void random_pixel(struct pixel *p) {
    p->red = rand() % (MAX_PIXEL_VALUE+1);
    p->green = rand() % (MAX_PIXEL_VALUE+1);
    p->blue = rand() % (MAX_PIXEL_VALUE+1);
}

/* Function to print an image */
void print_image(struct pixel *image) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("(%3u,%3u,%3u) ", image[i*SIZE+j].red,
                   image[i*SIZE+j].green, image[i*SIZE+j].blue);
        }
        printf("\n");
    }
}

/* Function to negate an image */
void negate_image(struct pixel *image) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            image[i*SIZE+j].red = MAX_PIXEL_VALUE - image[i*SIZE+j].red;
            image[i*SIZE+j].green = MAX_PIXEL_VALUE - image[i*SIZE+j].green;
            image[i*SIZE+j].blue = MAX_PIXEL_VALUE - image[i*SIZE+j].blue;
        }
    }
}

/* Function to zoom in on an image */
void zoom_in_image(struct pixel *orig_image, struct pixel *new_image) {
    int i, j, x, y;
    for(i=0; i<SIZE/2; i++) {
        for(j=0; j<SIZE/2; j++) {
            for(x=0; x<2; x++) {
                for(y=0; y<2; y++) {
                    new_image[(i*2+x)*SIZE*2 + (j*2+y)].red =
                        orig_image[i*SIZE+j].red;
                    new_image[(i*2+x)*SIZE*2 + (j*2+y)].green =
                        orig_image[i*SIZE+j].green;
                    new_image[(i*2+x)*SIZE*2 + (j*2+y)].blue =
                        orig_image[i*SIZE+j].blue;
                }
            }
        }
    }
}

int main() {
    struct pixel image[SIZE*SIZE];
    struct pixel new_image[SIZE*SIZE*4];
    int i;

    /* Generate a random image */
    srand(0);
    for(i=0; i<SIZE*SIZE; i++) {
        random_pixel(&image[i]);
    }

    /* Print the image */
    printf("Original image:\n");
    print_image(image);

    /* Negate the image */
    negate_image(image);
    printf("Negated image:\n");
    print_image(image);

    /* Zoom in on the image */
    zoom_in_image(image, new_image);
    printf("Zoomed-in image:\n");
    print_image(new_image);

    return 0;
}