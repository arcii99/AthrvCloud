//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>

int main() {
  // Happy message
  printf("Hello there! Let's add a digital watermark to your image!\n");

  // Ask for user input
  printf("Please enter your image file name: ");
  char fileName[50];
  scanf("%s", fileName);

  // Open image file
  FILE *imageFile = fopen(fileName, "rb+");
  if (imageFile == NULL) {
    printf("Oops! Something went wrong. Could not open file %s.\n", fileName);
    return 1;
  }

  // Get image size
  fseek(imageFile, 0L, SEEK_END);
  int imageSize = ftell(imageFile);

  // Generate watermark
  char watermark[10] = "HAPPYBOT";
  int watermarkSize = sizeof(watermark);

  // Add watermark to image
  fseek(imageFile, 0L, SEEK_SET);
  for (int i = 0; i < imageSize; i += watermarkSize) {
    fseek(imageFile, i, SEEK_SET);
    fwrite(watermark, 1, watermarkSize, imageFile);
  }

  // Close file and display success message
  fclose(imageFile);
  printf("Done! Your image now has a digital watermark!\n");

  return 0;
}