//FormAI DATASET v1.0 Category: Image compression ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct pixel {
   int red;
   int green;
   int blue;
};

void compressImage(struct pixel image[], int size) {
   int compressedImage[size];
   
   for(int i = 0; i < size; i++) {
      compressedImage[i] = (image[i].red + image[i].green + image[i].blue) / 3;
      printf("%d ", compressedImage[i]);
   }
}

int main() {
   struct pixel image[] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};
   int size = sizeof(image) / sizeof(image[0]);
   
   printf("Original Image:\n");
   for(int i = 0; i < size; i++) {
      printf("(%d, %d, %d) ", image[i].red, image[i].green, image[i].blue);
   }
   
   printf("\nCompressed Image:\n");
   compressImage(image, size);
   
   return 0;
}