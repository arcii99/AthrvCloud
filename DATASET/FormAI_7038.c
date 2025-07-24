//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 10000
#define MAX_MESSAGE_SIZE 1000

typedef struct {
   int rows;
   int cols;
   int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void encodeMessage(Image* img, char* message, int len) {
   int messageIndex = 0;
   int bitIndex = 0;
   int pixelVal;
   int pixelBit;
   for (int r = 0; r < img->rows; r++) {
      for (int c = 0; c < img->cols; c++) {
         if (messageIndex >= len) {
            return;
         }
         pixelVal = img->pixels[r][c];
         pixelBit = (pixelVal & 0x01);
         if (pixelBit != ((message[messageIndex] >> bitIndex) & 0x01)) {
            if (pixelBit == 1) {
               img->pixels[r][c]--;
            } else {
               img->pixels[r][c]++;
            }
         }
         bitIndex++;
         if (bitIndex >= 8) {
            messageIndex++;
            bitIndex = 0;
         }
      }
   }
}

void decodeMessage(Image* img, int len) {
   char message[MAX_MESSAGE_SIZE];
   int messageIndex = 0;
   int bitIndex = 0;
   int pixelVal;
   int pixelBit;
   for (int r = 0; r < img->rows; r++) {
      for (int c = 0; c < img->cols; c++) {
         if (messageIndex >= len) {
            printf("Decoded message: %s\n", message);
            return;
         }
         pixelVal = img->pixels[r][c];
         pixelBit = (pixelVal & 0x01);
         message[messageIndex] |= (pixelBit << bitIndex);
         bitIndex++;
         if (bitIndex >= 8) {
            messageIndex++;
            bitIndex = 0;
         }
      }
   }
}

int main() {
   Image img;
   char message[MAX_MESSAGE_SIZE] = "I love you more than any image could ever show.";
   int messageLen = strlen(message);
   
   // Set up the image with a heart shape
   img.rows = 10;
   img.cols = 10;
   memset(img.pixels, 0, sizeof(img.pixels));
   for (int r = 0; r < img.rows; r++) {
      for (int c = 0; c < img.cols; c++) {
         if ((r == 0 && c == 4) || (r == 0 && c == 5) ||
            (r == 1 && c == 3) || (r == 1 && c == 6) ||
            (r == 2 && c == 2) || (r == 2 && c == 7) ||
            (r == 3 && c == 2) || (r == 3 && c == 7) ||
            (r == 4 && c == 3) || (r == 4 && c == 6) ||
            (r == 5 && c == 4) || (r == 5 && c == 5)) {
            img.pixels[r][c] = 255;
         }
      }
   }
   
   // Encode the message
   encodeMessage(&img, message, messageLen);
   
   // Decode the message
   decodeMessage(&img, messageLen);
   
   return 0;
}