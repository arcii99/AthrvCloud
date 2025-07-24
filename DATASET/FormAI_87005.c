//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main(){
    int width, height, maxval;
    FILE *f;
    f = fopen("image.ppm", "r"); // Reading the input file which is in PPM format
    fscanf(f, "P3\n%d %d\n%d\n", &width, &height, &maxval);
    unsigned char *image = malloc(width * height * 3); // Allocating memory to store image data
    for (int i = 0; i < width * height * 3; i++) {
        fscanf(f, "%hhu", &image[i]); // Reading raw image data (RGB values)
    }
    fclose(f);

    // Converting image to ASCII art
    int index = 0;
    for (int i = 0; i < height; i+=2){
        for (int j = 0; j < width; j++){
            index = (i * width) + j;
            if (image[index] > maxval/4){ // If pixel is bright, print '#'
                printf("#");
            } else if (image[index] > maxval/8){ // If pixel is less bright, print '='
                printf("=");
            } else if (image[index] > maxval/12){ // If pixel is even less bright, print '-'
                printf("-");
            } else { // If pixel is dark, print ' '
                printf(" ");
            }
        }
        printf("\n");
        for (int j = 0; j < width; j++){
            index = ((i+1) * width) + j;
            if (image[index] > maxval/4){ // If pixel is bright, print '@'
                printf("@");
            } else if (image[index] > maxval/8){ // If pixel is less bright, print '+'
                printf("+");
            } else if (image[index] > maxval/12){ // If pixel is even less bright, print '.'
                printf(".");
            } else { // If pixel is dark, print ' '
                printf(" ");
            }
        }
        printf("\n");
    }

    free(image); // Freeing allocated memory
    return 0;
}