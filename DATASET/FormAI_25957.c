//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char asciiChars[11] = {' ', '.', ':', '+', '*', '?', 'X', '%', '#', '@'};

void convertImageToAscii(char* imagePath, char* asciiImagePath, int imageWidth, int imageHeight) {
  FILE* imageFile = fopen(imagePath, "rb");

  fseek(imageFile, 0, SEEK_END);
  long imageSize = ftell(imageFile);
  rewind(imageFile);

  unsigned char* imageBuffer = (unsigned char*)malloc(imageSize * sizeof(unsigned char));
  fread(imageBuffer, sizeof(unsigned char), imageSize, imageFile);
  fclose(imageFile);

  FILE* asciiImageFile = fopen(asciiImagePath, "w");

  for (int i = 0; i < imageSize; i += 3) {
    int pixelValue = (imageBuffer[i] + imageBuffer[i + 1] + imageBuffer[i + 2]) / 3;
    int asciiIndex = pixelValue / 25;
    fputc(asciiChars[asciiIndex], asciiImageFile);

    if ((i + 3) % (imageWidth * 3) == 0) {
      fputc('\n', asciiImageFile);
    }
  }

  fclose(asciiImageFile);
  free(imageBuffer);
}

int main(int argc, char** argv) {
  char* imagePath = "example.jpg";
  char* asciiImagePath = "surrealist_ascii_art.txt";
  int imageWidth = 250;
  int imageHeight = 250;

  convertImageToAscii(imagePath, asciiImagePath, imageWidth, imageHeight);

  return 0;
}