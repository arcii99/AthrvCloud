//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to embed watermark
void embedWatermark(int *img, int imgWidth, int imgHeight, int *wm, int wmSize){
    int imgSize = imgWidth * imgHeight;
    int row, col, bit, wmIndex = 0;

    for(int i = 0; i < imgSize; i++){
        row = i / imgWidth;
        col = i % imgWidth;

        if(wmIndex < wmSize){
            for(int j = 0; j < 8; j++){
                bit = (wm[wmIndex] >> j) & 1;
                if(bit == 1){
                    img[i] |= (1 << j); //Set 1 bit of lsb to 1
                }else{
                    img[i] &= ~(1 << j); //Set 1 bit of lsb to 0
                }
            }
            wmIndex++;
        }else{
            break; //Embedding Done
        }
    }
}

//Function to extract watermark
void extractWatermark(int *img, int imgWidth, int imgHeight, int *wm, int wmSize){
    int imgSize = imgWidth * imgHeight;
    int row, col, bit, wmIndex = 0;
    int wmValue = 0;

    for(int i = 0; i < imgSize; i++){
        row = i / imgWidth;
        col = i % imgWidth;

        for(int j = 0; j < 8; j++){
            bit = img[i] & (1 << j);
            if(bit == 1){
                wmValue |= (1 << wmIndex);
            }
            wmIndex++;

            if(wmIndex == wmSize){
                break; //Extraction Done
            }
        }

        if(wmIndex == wmSize){
            break; //Extraction Done
        }
    }

    //Convert wmValue to binary array
    for(int i = wmSize-1; i >= 0; i--){
        wm[i] = wmValue & 1;
        wmValue >>= 1;
    }
}

//Main Function
int main(){
    //Initialize Image and Watermark
    int imgWidth = 8, imgHeight = 8; //8x8 Image
    int wmSize = 16; //16 bits Watermark

    int img[imgWidth * imgHeight];
    for(int i = 0; i < imgWidth * imgHeight; i++){
        img[i] = rand() % 256; //Random Image Pixel values from 0 to 255
    }

    int wm[wmSize];
    for(int i = 0; i < wmSize; i++){
        wm[i] = rand() % 2; //Random 0 or 1 for Watermark bits
    }

    //Embed Watermark
    embedWatermark(img, imgWidth, imgHeight, wm, wmSize);

    //Extract Watermark
    int extractedWm[wmSize];
    extractWatermark(img, imgWidth, imgHeight, extractedWm, wmSize);

    //Compare Original and Extracted Watermark
    int errorCount = 0;
    for(int i = 0; i < wmSize; i++){
        if(wm[i] != extractedWm[i]){
            errorCount++;
        }
    }

    //Print Results
    printf("Original Watermark:\n");
    for(int i = 0; i < wmSize; i++){
        printf("%d ", wm[i]);
    }

    printf("\n\nExtracted Watermark:\n");
    for(int i = 0; i < wmSize; i++){
        printf("%d ", extractedWm[i]);
    }

    printf("\n\nError Count = %d\n", errorCount);

    return 0;
}