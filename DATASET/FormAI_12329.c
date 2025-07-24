//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include<stdio.h>

// Function for embedding the watermark into the image
void embedWatermark(int image[], int watermark[], int imageSize, int watermarkSize) {
  int watermarkIndex = 0;

  for (int i = 0; i < imageSize; i++) {
    if (watermarkIndex < watermarkSize) {
      image[i] = (image[i] & 0xFE) | (watermark[watermarkIndex] >> 7);
      watermark[watermarkIndex] <<= 1;
      watermarkIndex++;
    } else {
      break;
    }
  }
}

// Function for extracting the watermark from the image
void extractWatermark(int image[], int watermark[], int imageSize, int watermarkSize) {
  int watermarkIndex = 0;

  for (int i = 0; i < imageSize; i++) {
    if (watermarkIndex < watermarkSize) {
      watermark[watermarkIndex] <<= 1;
      watermark[watermarkIndex] |= (image[i] & 0x01);
      watermarkIndex++;
    } else {
      break;
    }
  }
}

int main() {
  int image[] = {255, 255, 255, 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 255, 255, 0}; // Sample image data
  int watermark[] = {1, 0, 1, 0, 1, 0, 1, 0, 0, 1}; // Sample watermark data
  int imageSize = sizeof(image)/sizeof(image[0]); // Calculate image size
  int watermarkSize = sizeof(watermark)/sizeof(watermark[0]); // Calculate watermark size

  printf("Original Image: ");
  for (int i = 0; i < imageSize; i++) {
    printf("%d ", image[i]);
  }

  printf("\n");

  // Embed the watermark into the image
  embedWatermark(image, watermark, imageSize, watermarkSize);

  printf("Image with Watermark: ");
  for (int i = 0; i < imageSize; i++) {
    printf("%d ", image[i]);
  }

  printf("\n");

  // Extract the watermark from the image
  extractWatermark(image, watermark, imageSize, watermarkSize);

  printf("Extracted Watermark: ");
  for (int i = 0; i < watermarkSize; i++) {
    printf("%d ", watermark[i]);
  }

  printf("\n");

  return 0;
}