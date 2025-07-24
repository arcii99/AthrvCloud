//FormAI DATASET v1.0 Category: Image Classification system ; Style: minimalist
#include<stdio.h>

int main(){
    // The image contains 4 pixels and each pixel has 3 values representing R,G,B
    int image[4][3]={{255,0,0},{0,255,0},{0,0,255},{255,255,0}};

    // Initialize variables to keep track of the color with the highest value
    int red=0, green=0, blue=0;

    // Loop through each pixel in the image array
    for(int i=0;i<4;i++){
        // Check if the value of R in this pixel is higher than the previous pixels
        if(image[i][0]>red){
            red = image[i][0];
        }

        // Check if the value of G in this pixel is higher than the previous pixels
        if(image[i][1]>green){
            green = image[i][1];
        }

        // Check if the value of B in this pixel is higher than the previous pixels
        if(image[i][2]>blue){
            blue = image[i][2];
        }
    }

    // Determine what color had the highest value and print the result
    if(red>green && red>blue){
        printf("The image is classified as a Red Image");
    }
    else if(green>red && green>blue){
        printf("The image is classified as a Green Image");
    }
    else{
        printf("The image is classified as a Blue Image");
    }

    return 0;
}