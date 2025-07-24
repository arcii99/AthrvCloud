//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flip_horizontally(int image[][4], int rows, int cols) {
   int i, j, temp;

   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols / 2; j++) {
         temp = image[i][j];
         image[i][j] = image[i][cols - j - 1];
         image[i][cols - j - 1] = temp;
      }
   }
}

// Function to change the brightness of the image
void change_brightness(int image[][4], int rows, int cols, int brightness) {
   int i, j;

   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         image[i][j] += brightness;
         if (image[i][j] > 255)
            image[i][j] = 255;
         if (image[i][j] < 0)
            image[i][j] = 0;
      }
   }
}

// Function to change the contrast of the image
void change_contrast(int image[][4], int rows, int cols, float contrast) {
   int i, j;
   float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         image[i][j] = factor * (image[i][j] - 128) + 128;
         if (image[i][j] > 255)
            image[i][j] = 255;
         if (image[i][j] < 0)
            image[i][j] = 0;
      }
   }
}

int main() {
   int image[4][4] = {{180, 120, 50, 200}, {50, 10, 190, 250}, {100, 240, 30, 70}, {220, 130, 190, 80}};
   int rows = 4, cols = 4, brightness = 50;
   float contrast = 50.0;

   printf("\nBefore flipping the image horizontally:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }

   flip_horizontally(image, rows, cols);
   printf("\nAfter flipping the image horizontally:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }

   printf("\nBefore changing the brightness:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }

   change_brightness(image, rows, cols, brightness);
   printf("\nAfter changing the brightness:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }

   printf("\nBefore changing the contrast:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }

   change_contrast(image, rows, cols, contrast);
   printf("\nAfter changing the contrast:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }

   return 0;
}