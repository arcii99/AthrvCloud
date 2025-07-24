//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>

void flipImage(int img[][3], int height, int width){
   //function to flip image
   int temp;
   for(int i=0;i<height;i++){
      for(int j=0;j<width/2;j++){
         temp=img[i][j];
         img[i][j]=img[i][width-j-1];
         img[i][width-j-1]=temp;
      }
   }
}

void adjustBrightness(int img[][3], int height, int width, int brightness){
   //function to adjust brightness
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
         img[i][j]+=brightness;
         if(img[i][j]<0){
            img[i][j]=0;
         }
         else if(img[i][j]>255){
            img[i][j]=255;
         }
      }
   }
}

void adjustContrast(int img[][3], int height, int width, float contrast){
   //function to adjust contrast
   float factor=(259*(contrast+255))/(255*(259-contrast));
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
         img[i][j]=(int)(factor*(img[i][j]-128)+128);;
         if(img[i][j]<0){
            img[i][j]=0;
         }
         else if(img[i][j]>255){
            img[i][j]=255;
         }
      }
   }
}

int main(){
   //sample image
   int img[3][3]={
      {100,150,200},
      {50,100,150},
      {0,50,100}
   };
   int height=3;
   int width=3;
   
   //original image
   printf("Original Image:\n");
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
         printf("%d ",img[i][j]);
      }
      printf("\n");
   }
   
   //flip image
   flipImage(img,height,width);
   printf("Flipped Image:\n");
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
         printf("%d ",img[i][j]);
      }
      printf("\n");
   }
   
   //adjust brightness
   int brightness=30;
   adjustBrightness(img,height,width,brightness);
   printf("Brightness Adjusted Image:\n");
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
         printf("%d ",img[i][j]);
      }
      printf("\n");
   }
   
   //adjust contrast
   float contrast=1.5;
   adjustContrast(img,height,width,contrast);
   printf("Contrast Adjusted Image:\n");
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
         printf("%d ",img[i][j]);
      }
      printf("\n");
   }
}