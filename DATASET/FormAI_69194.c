//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 1024

typedef struct {
    int height;
    int width;
    unsigned char data[MAX_PIXELS][MAX_PIXELS];
} gray_image;

/*
Function to flip the image horizontally
*/
void flip_image_horizontal(gray_image *image) {
    int row, col;
    unsigned char temp;
    for(row=0; row < image->height; row++) {
        for(col=0; col < (image->width/2); col++) {
            temp = image->data[row][col];
            image->data[row][col] = image->data[row][image->width-col-1];
            image->data[row][image->width-col-1] = temp;
        }
   }
}

/*
Function to adjust the brightness and contrast of an image
*/
void brightness_contrast(gray_image *image, int brightness, float contrast) {
    int row, col;
    float pixel_value;
    for(row=0; row < image->height; row++) {
        for(col=0; col < image->width; col++) {
            pixel_value = (float)image->data[row][col];
            pixel_value = pixel_value * contrast + brightness;
            if(pixel_value > 255) {
                pixel_value = 255;
            }
            if(pixel_value < 0) {
                pixel_value = 0;
            }
            image->data[row][col] = (unsigned char)pixel_value;
        }
    }
}

int main() {
    FILE *fp;
    int i, j;
    char filename[100];
    gray_image image;
    int brightness;
    float contrast;
    
    // Prompt user for image filename
    printf("Enter input image filename: ");
    scanf("%s", filename);
    
    // Open image file for reading
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening input file");
        return 1;
    }
    
    // Read image dimensions and pixel values from file
    fscanf(fp, "%d %d", &image.height, &image.width);
    for(i=0; i < image.height; i++) {
        for(j=0; j < image.width; j++) {
            fscanf(fp, "%hhu", &(image.data[i][j]));
        }
    }
    
    // Close input file
    fclose(fp);
    
    // Flip image horizontally
    flip_image_horizontal(&image);
    
    // Prompt user for brightness and contrast values
    printf("Enter brightness value (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Enter contrast value (0.1 to 10.0): ");
    scanf("%f", &contrast);
    
    // Adjust brightness/contrast of image
    brightness_contrast(&image, brightness, contrast);
    
    // Write processed image to output file
    fp = fopen("output.pgm", "wb");
    if(fp == NULL) {
        printf("Error opening output file");
        return 1;
    }
    fprintf(fp, "P5\n%d %d\n255\n", image.height, image.width);
    for(i=0; i < image.height; i++) {
        for(j=0; j < image.width; j++) {
            fputc(image.data[i][j], fp);
        }
    }
    fclose(fp);
    
    return 0;
}