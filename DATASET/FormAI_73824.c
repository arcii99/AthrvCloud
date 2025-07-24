//FormAI DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to invert the colors in an image
void invert_colors(int num_rows, int num_cols, int image[num_rows][num_cols]) {
    for(int i=0; i<num_rows; i++) {
        for(int j=0; j<num_cols; j++) {
            image[i][j] = 255 - image[i][j]; //Invert color values by subtracting them from 255
        }
    }
}

//Function to blur the image by averaging out the values of nearby pixels
void blur(int num_rows, int num_cols, int image[num_rows][num_cols]) {
    int new_image[num_rows][num_cols]; //Create a new image with the same dimensions as the original
    memcpy(new_image, image, sizeof(new_image)); //Copy the original image to the new image
    
    for(int i=1; i<num_rows-1; i++) {
        for(int j=1; j<num_cols-1; j++) {
            //Average out the pixel values of the surrounding 8 pixels
            int avg_value = (image[i-1][j-1] + image[i][j-1] + image[i+1][j-1] + image[i-1][j] +
                             image[i+1][j] + image[i-1][j+1] + image[i][j+1] + image[i+1][j+1]) / 8;
            new_image[i][j] = avg_value; //Set the new pixel value to the averaged out value
        }
    }
    
    memcpy(image, new_image, sizeof(image)); //Copy the new image back to the original image
}

int main() {
    int num_rows, num_cols;
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &num_rows, &num_cols);
    
    int image[num_rows][num_cols];
    printf("Enter the pixel values of the image:\n");
    for(int i=0; i<num_rows; i++) {
        for(int j=0; j<num_cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    
    printf("What do you want to do with the image?\n");
    printf("1. Invert colors\n");
    printf("2. Blur\n");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            invert_colors(num_rows, num_cols, image);
            printf("Inverted colors!\n");
            break;
        case 2:
            blur(num_rows, num_cols, image);
            printf("Blurred image!\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    printf("New image:\n");
    for(int i=0; i<num_rows; i++) {
        for(int j=0; j<num_cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}