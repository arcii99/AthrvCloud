//FormAI DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#define BITS 8

void printImage(unsigned char image[], int row, int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            printf("%d ",image[i*col + j]);
        printf("\n");
    }
}

void encode(unsigned char image[], char message[]){
    int i,j,k=0,l=0,m,n;
    char c;
    int len = strlen(message);

    for(i=0;i<len;i++){
        c = message[i];
        for(j=0;j<BITS;j++){
            m = k/BITS;
            n = k%BITS;
            if(n==0){
                k++;
                l++;
            }
            image[m*8 + l-1] &= ~(1<<n);
            image[m*8 + l-1] |= ((c&(1<<j))>>j)<<n;
            k++;
        }
    }
}

int main(){
    unsigned char image[] = {23,45,67,89,12,34,56,78,90,87,65,43,21,83,70,56};
    char message[] = "elementary, my dear Watson";
    int row=4, col=4;
    printf("Original Image:\n");
    printImage(image,row,col);

    //apply image steganography
    encode(image,message);

    printf("\nImage after encoding:\n");
    printImage(image,row,col);
    return 0;
}