//FormAI DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>

int main() {
  FILE *imageFile;
  unsigned char *imageData;
  int imageSize;

  // Open the image file in binary mode
  imageFile = fopen("image.bmp", "rb");

  // Calculate the size of the image
  fseek(imageFile, 0, SEEK_END);
  imageSize = ftell(imageFile);
  rewind(imageFile);

  // Allocate memory for the image data
  imageData = (unsigned char *)malloc(imageSize * sizeof(char));

  // Read the image data into memory
  fread(imageData, sizeof(char), imageSize, imageFile);

  // Close the image file
  fclose(imageFile);

  // Do something with the image data...

  return 0;
}