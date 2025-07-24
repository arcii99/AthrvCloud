//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define IMAGE_SIZE 1000
#define WATERMARK_SIZE 64

// function to implement Digital Watermarking
void addWatermark(char image[IMAGE_SIZE][IMAGE_SIZE], char waterMark[WATERMARK_SIZE]){

    int i, j, k = 0;
    int n = strlen(waterMark);

    for(i=0; i<IMAGE_SIZE; i++){
        for(j=0; j<IMAGE_SIZE; j++){
            if(k<n){
                int newPixelValue = image[i][j] + (int)(waterMark[k]); // covert watermark value to integer and add it to the pixel value
                if(newPixelValue>255){
                    newPixelValue = 255;
                }
                image[i][j] = (char)newPixelValue; // update the pixel value
                k++;
            }
            else{
                break;
            }
        }

        if(k>=n){
            break;
        }
    }

    if(k<n){ // if the watermark is not completely added
        printf("\nError: Not enough pixels to accommodate the watermark!\n");
    }
}

// function to extract Digital Watermarking
void extractWatermark(char image[IMAGE_SIZE][IMAGE_SIZE], char waterMark[WATERMARK_SIZE]){

    int i, j, k = 0;
    int n = strlen(waterMark);
    char extractedBits[n];

    for(i=0; i<IMAGE_SIZE; i++){
        for(j=0; j<IMAGE_SIZE; j++){
            if(k<n){
                int bitValue = image[i][j] - ((int)waterMark[k]); // subtract watermark value from pixel value to extract the bit
                if(bitValue<0){ 
                    bitValue = 255 + bitValue; // if the bit extracted is negative, add 255 to get the correct bit value
                }
                extractedBits[k] = (char)bitValue; // store the extracted bit
                k++;
            }
            else{
                break;
            }
        }

        if(k>=n){
            break;
        }
    }

    if(k<n){ // if the watermark is not completely extracted
        printf("\nError: Not enough pixels to accommodate the watermark!\n");
    }
    else{ // if the watermark is completely extracted
        printf("\nThe extracted watermark is: %s\n", extractedBits);
    }
}

int main(){

    char image[IMAGE_SIZE][IMAGE_SIZE];
    for(int i=0; i<IMAGE_SIZE; i++){
        for(int j=0; j<IMAGE_SIZE; j++){
            image[i][j] = (char)(rand()%256); // initialize random pixel values
        }
    }

    char waterMark[WATERMARK_SIZE] = "This is a sample digital watermark!"; // initialize the watermark string

    printf("\nThe original watermark is: %s\n", waterMark);

    addWatermark(image, waterMark); // implement digital watermarking

    extractWatermark(image, waterMark); // extract the original watermark from the image

    return 0;
}