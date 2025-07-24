//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include<stdio.h>
#include<string.h>

//Function to display the watermark message
void displayWatermark(char msg[], int len)
{
    printf("\n--------------------------------------------\n\n");
    printf("Watermark Message: ");
    for(int i=0;i<len;i++)
    {
        printf("%c",msg[i]);
    }
    printf("\n\n--------------------------------------------\n");
}

//Function to add watermark to the image
void addWatermark(char img[], char watermark[])
{
    int imgLen=strlen(img);
    int wmkLen=strlen(watermark);
    int idx=0;
    char watermarkChar;
    for(int i=0;i<imgLen;i++)
    {
        watermarkChar=watermark[idx%wmkLen]; //Get the current character of watermark
        img[i]=(img[i]&0xFE)|((watermarkChar>>idx%8)&0x01); //Set the least significant bit of the image pixel to the current bit of watermark
        idx++;
    }
}

int main()
{
    char img[100]="Image Data";
    char watermark[50]="This is a Watermark Message.";
    addWatermark(img,watermark); //Add watermark to the image
    displayWatermark(watermark,strlen(watermark)); //Display the watermark message
    return 0;
}