//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Sherlock Holmes
//The Adventure of Basic Image Processing
//By Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    //Welcome message
    printf("Greetings! I am Sherlock Holmes, and we shall venture into the mystery of Basic Image Processing.\n");

    // Ask the user to input the file name of the image
    char filename[100];
    printf("Enter the file name of the image you want to process (include the extension): ");
    scanf("%s", filename);

    // Open the file for reading and writing
    FILE *fptr;
    fptr = fopen(filename, "rb+");
    if (fptr == NULL) {
        printf("The file does not exist. Please try again.\n");
        return 1;
    }

    //Read and display image header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fptr);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];
    printf("Image Width: %d pixels\n", width);
    printf("Image Height: %d pixels\n", height);
    printf("Bit Depth: %d bits per pixel\n", bitDepth);

    // Ask the user for the desired function to perform
    printf("What task would you like to perform on the image?\n");
    printf("1. Flip Image Vertically\n");
    printf("2. Flip Image Horizontally\n");
    printf("3. Adjust Brightness/Contrast\n");
    int option;
    scanf("%d", &option);

    // To flip an image vertically or horizontally
    unsigned char imgHeight[height][width*3];
    int padding = 0;
    if((3*width)%4!=0){
        padding=4-(3*width)%4;
    }
    for(int i=0; i<height; i++){
        fread(imgHeight[i], sizeof(unsigned char), 3*width, fptr);
        fseek(fptr, padding, SEEK_CUR);
    }

    // Image flip function
    if(option==1){
        for(int i=0; i<height/2; i++){
            for(int j=0; j<width*3; j++){
                unsigned char temp = imgHeight[i][j];
                imgHeight[i][j] = imgHeight[height-i-1][j];
                imgHeight[height-i-1][j] = temp;
            }
        }
    }
    else if(option==2){
        for(int i=0; i<height; i++){
            for(int j=0; j<width*3/2; j+=3){
                unsigned char temp1 = imgHeight[i][j];
                unsigned char temp2 = imgHeight[i][j+1];
                unsigned char temp3 = imgHeight[i][j+2];
                imgHeight[i][j] = imgHeight[i][width*3-j-3];
                imgHeight[i][j+1] = imgHeight[i][width*3-j-2];
                imgHeight[i][j+2] = imgHeight[i][width*3-j-1];
                imgHeight[i][width*3-j-3] = temp1;
                imgHeight[i][width*3-j-2] = temp2;
                imgHeight[i][width*3-j-1] = temp3;
            }
        }
    }

    // To adjust brightness and contrast
    if(option==3){
        unsigned char imgOutput[height][width*3];
        int brightness = 50;
        int contrast = 50;

        // Ask user to adjust brightness and contrast
        printf("What is the desired brightness? (-255 to 255, default is 50): ");
        scanf("%d", &brightness);

        printf("What is the desired contrast? (0 to 100, default is 50): ");
        scanf("%d", &contrast);

        // Ensure brightness and contrast values are within acceptable range
        if (brightness > 255) {
            brightness = 255;
        }
        else if (brightness < -255) {
            brightness = -255;
        }

        if (contrast > 100) {
            contrast = 100;
        }
        else if (contrast < 0) {
            contrast = 0;
        }

        // Adjust brightness and contrast
        double change = (double)contrast / 50.0;
        change = pow(change, 4.0);

        for(int i=0; i<height; i++){
            for(int j=0; j<width*3; j++){
                int pixel = (int)imgHeight[i][j] + brightness;
                pixel = (pixel - 128) * change + 128;

                if (pixel > 255) {
                    pixel = 255;
                }
                else if (pixel < 0) {
                    pixel = 0;
                }

                imgOutput[i][j] = (unsigned char)pixel;
            }
        }

        // Write the adjusted image into file
        fseek(fptr, sizeof(unsigned char) * 54, SEEK_SET);
        for(int i=0; i<height; i++){
            fwrite(imgOutput[i], sizeof(unsigned char), 3*width, fptr);
            fseek(fptr, padding, SEEK_CUR);
        }

        printf("Brightness/Contrast adjustment is successful!\n");
    }

    // Write the flipped image into file
    fseek(fptr, sizeof(unsigned char) * 54, SEEK_SET);
    for(int i=0; i<height; i++){
        fwrite(imgHeight[i], sizeof(unsigned char), 3*width, fptr);
        fseek(fptr, padding, SEEK_CUR);
    }

    printf("Image processing is successful!\n");

    //Close the file
    fclose(fptr);

    return 0;
}