//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>

// Function to check if a given pixel is black or white
int isBlack(int pixel){
    if(pixel <= 127){
        return 1;
    }
    return 0;
}

// Function to set the least significant bit of a number to a given value
int setLSB(int num, int value){
    if(value == 1){
        return (num | 1);
    }
    else{
        return (num & (~1));
    }
}

// Function to get the least significant bit of a number
int getLSB(int num){
    return (num & 1);
}

// Function to embed a watermark in an image
void embedWatermark(int watermark, int* image, int size){
    int i;
    for(i = 0; i < size; i++){
        if(isBlack(image[i]) == 1){
            image[i] = setLSB(image[i], getLSB(watermark));
            watermark = watermark >> 1;
            if(watermark == 0){
                break;
            }
        }
    }
}

// Function to extract a watermark from an image
int extractWatermark(int* image, int size){
    int watermark = 0;
    int i;
    for(i = 0; i < size; i++){
        if(isBlack(image[i]) == 1){
            watermark = watermark | getLSB(image[i]);
            if(i < (size - 1)){
                watermark = watermark << 1;
            }
        }
    }
    return watermark;
}

int main(){
    // Example usage of the watermarking functions
    int image[8] = {0, 100, 200, 50, 150, 250, 75, 175};
    int size = 8;
    int watermark = 117;

    printf("Before watermarking:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", image[i]);
    }

    embedWatermark(watermark, image, size);
    int extractedWatermark = extractWatermark(image, size);

    printf("\n\nAfter watermarking:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", image[i]);
    }

    printf("\n\nExtracted watermark: %d\n", extractedWatermark);

    return 0;
}