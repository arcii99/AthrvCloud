//FormAI DATASET v1.0 Category: Image Editor ; Style: active
#include <stdio.h>
#include <stdlib.h>

// define image size constants
#define WIDTH 500
#define HEIGHT 500

// function to create a blank image
void create_blank_image(unsigned char image[][WIDTH][3]) {
    // loop through all rows and columns
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // set all pixels to white
            image[i][j][0] = 255;
            image[i][j][1] = 255;
            image[i][j][2] = 255;
        }
    }
}

// function to apply a grayscale effect to the image
void grayscale(unsigned char image[][WIDTH][3]) {
    // loop through all rows and columns
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // calculate the grayscale value
            unsigned char gray = 0.3 * image[i][j][0] + 0.59 * image[i][j][1] + 0.11 * image[i][j][2];
            
            // set all color channels to the grayscale value
            image[i][j][0] = gray;
            image[i][j][1] = gray;
            image[i][j][2] = gray;
        }
    }
}

// function to apply a blur effect to the image
void blur(unsigned char image[][WIDTH][3]) {
    // create a temporary image to store the blurred result
    unsigned char temp_image[HEIGHT][WIDTH][3];
    
    // loop through all rows and columns (except the border)
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            // calculate the average color of the surrounding pixels
            unsigned char avg_r = (image[i-1][j-1][0] + image[i-1][j][0] + image[i-1][j+1][0] +
                                   image[i][j-1][0] + image[i][j][0] + image[i][j+1][0] +
                                   image[i+1][j-1][0] + image[i+1][j][0] + image[i+1][j+1][0]) / 9;
            unsigned char avg_g = (image[i-1][j-1][1] + image[i-1][j][1] + image[i-1][j+1][1] +
                                   image[i][j-1][1] + image[i][j][1] + image[i][j+1][1] +
                                   image[i+1][j-1][1] + image[i+1][j][1] + image[i+1][j+1][1]) / 9;
            unsigned char avg_b = (image[i-1][j-1][2] + image[i-1][j][2] + image[i-1][j+1][2] +
                                   image[i][j-1][2] + image[i][j][2] + image[i][j+1][2] +
                                   image[i+1][j-1][2] + image[i+1][j][2] + image[i+1][j+1][2]) / 9;
            
            // set the pixel in the temporary image to the average color
            temp_image[i][j][0] = avg_r;
            temp_image[i][j][1] = avg_g;
            temp_image[i][j][2] = avg_b;
        }
    }
    
    // copy the temporary image back to the original image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j][0] = temp_image[i][j][0];
            image[i][j][1] = temp_image[i][j][1];
            image[i][j][2] = temp_image[i][j][2];
        }
    }
}

// function to save the image to a file
void save_image(unsigned char image[][WIDTH][3], char* filename) {
    // open the file for writing
    FILE* file = fopen(filename, "wb");
    
    // write the header information
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    
    // loop through all rows and columns and write the pixel values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fputc(image[i][j][0], file);
            fputc(image[i][j][1], file);
            fputc(image[i][j][2], file);
        }
    }
    
    // close the file
    fclose(file);
}

int main() {
    // create a blank image
    unsigned char image[HEIGHT][WIDTH][3];
    create_blank_image(image);
    
    // apply a grayscale effect
    grayscale(image);
    
    // apply a blur effect
    blur(image);
    
    // save the image to a file
    save_image(image, "output.ppm");
    
    return 0;
}