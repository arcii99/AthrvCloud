//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip the given image
void flip_image(int *image, int rows, int cols) {
    int temp;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            temp = *(image + i*cols + j);
            *(image + i*cols + j) = *(image + i*cols + (cols-j-1));
            *(image + i*cols + (cols-j-1)) = temp;
        }
    }
}

// Function to change the brightness and contrast of the given image
void change_brightness_contrast(int *image, int rows, int cols, float brightness, float contrast) {
    float pixel_value;

    // calculate the middle point of the pixel range
    int mid_pixel_value = pow(2, sizeof(int)*8-1) - 1;
    
    // loop through all the pixels
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            
            // calculate the new pixel value
            pixel_value = (*(image + i*cols + j) - mid_pixel_value)*contrast + mid_pixel_value + brightness;
            
            // make sure the pixel value is within range
            if(pixel_value < 0) {
                pixel_value = 0;
            }
            if(pixel_value > pow(2, sizeof(int)*8)-1) {
                pixel_value = pow(2, sizeof(int)*8)-1;
            }

            // update the pixel value
            *(image + i*cols + j) = (int)pixel_value;
        }
    }
}

int main() {
    // read the input image
    FILE *fp;
    fp = fopen("input.pgm", "r");
    
    char format[1024];
    int rows, cols, max_val;
    
    fscanf(fp, "%s", format);
    fscanf(fp, "%d %d %d", &cols, &rows, &max_val);
    
    int *image = (int*)malloc(rows*cols*sizeof(int));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            fscanf(fp, "%d", image + i*cols + j);
        }
    }
    fclose(fp);

    // flip the image
    flip_image(image, rows, cols);

    // change the brightness and contrast of the image
    float brightness = 50.0;
    float contrast = 1.5;
    change_brightness_contrast(image, rows, cols, brightness, contrast);

    // write the output image
    fp = fopen("output.pgm", "w");
    fprintf(fp, "%s\n", format);
    fprintf(fp, "%d %d\n", cols, rows);
    fprintf(fp, "%d\n", max_val);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            fprintf(fp, "%d ", *(image + i*cols + j));
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    free(image);

    return 0;
}