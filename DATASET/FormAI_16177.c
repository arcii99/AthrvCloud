//FormAI DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define message length limit */
#define MAX_MESSAGE_LENGTH 200

/* Define image size */
#define IMAGE_WIDTH 32
#define IMAGE_HEIGHT 32

/* Define RGB pixel structure */
typedef struct Pixel {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

/* Function to read image from file */
void readImageFile(Pixel* imagePixels, char* filepath) {
  /* Open file for reading */
  FILE* file = fopen(filepath, "rb");
  if (!file) {
    printf("Could not open image file %s\n", filepath);
    exit(1);
  }

  /* Read the image data */
  fseek(file, 54, SEEK_SET);
  fread(imagePixels, sizeof(Pixel), IMAGE_WIDTH * IMAGE_HEIGHT, file);

  /* Close file */
  fclose(file);
}

/* Function to save image to file */
void saveImageFile(Pixel* imagePixels, char* filepath) {
  /* Open file for writing */
  FILE* file = fopen(filepath, "wb");
  if (!file) {
    printf("Could not open output file %s\n", filepath);
    exit(1);
  }

  /* Write image header */
  unsigned char headers[54] = { 0 };
  headers[0] = 'B';
  headers[1] = 'M';
  int filesize = 54 + 3 * IMAGE_WIDTH * IMAGE_HEIGHT;
  headers[2] = (unsigned char)(filesize);
  headers[3] = (unsigned char)(filesize >> 8);
  headers[4] = (unsigned char)(filesize >> 16);
  headers[5] = (unsigned char)(filesize >> 24);
  headers[10] = (unsigned char)(54);
  headers[14] = (unsigned char)(40);
  headers[18] = (unsigned char)(IMAGE_WIDTH);
  headers[19] = (unsigned char)(IMAGE_WIDTH >> 8);
  headers[20] = (unsigned char)(IMAGE_WIDTH >> 16);
  headers[21] = (unsigned char)(IMAGE_WIDTH >> 24);
  headers[22] = (unsigned char)(IMAGE_HEIGHT);
  headers[23] = (unsigned char)(IMAGE_HEIGHT >> 8);
  headers[24] = (unsigned char)(IMAGE_HEIGHT >> 16);
  headers[25] = (unsigned char)(IMAGE_HEIGHT >> 24);
  headers[26] = (unsigned char)(1);
  headers[28] = (unsigned char)(24);
  fwrite(headers, sizeof(unsigned char), 54, file);

  /* Write the image data */
  fseek(file, 54, SEEK_SET);
  fwrite(imagePixels, sizeof(Pixel), IMAGE_WIDTH * IMAGE_HEIGHT, file);

  /* Close file */
  fclose(file);
}

/* Function to retrieve bit from byte */
unsigned char getBit(unsigned char byte, int position) {
  return (byte >> (7 - position)) & 1;
}

/* Function to set bit in byte */
unsigned char setBit(unsigned char byte, int position, unsigned char bitVal) {
  if (bitVal) {
    return byte | (1 << (7 - position));
  } else {
    return byte & ~(1 << (7 - position));
  }
}

/* Function to hide message in image */
void hideMessage(Pixel* imagePixels, char* message) {
  /* Convert message to binary */
  int messageLength = strlen(message);
  char binaryMessage[MAX_MESSAGE_LENGTH * 8];
  for (int i = 0; i < messageLength; i++) {
    for (int j = 0; j < 8; j++) {
      binaryMessage[i * 8 + j] = ((message[i] >> j) & 1) + '0';
    }
  }
  int binaryMessageLength = messageLength * 8;

  /* Hide message length in first 32 pixels */
  for (int i = 0; i < 32; i++) {
    Pixel pixel = imagePixels[i];
    for (int j = 0; j < 3; j++) {
      int bitVal;
      if (i * 3 + j < binaryMessageLength) {
        bitVal = binaryMessage[i * 3 + j] - '0';
      } else if (i * 3 + j == binaryMessageLength) {
        bitVal = messageLength >> 24;
      } else if (i * 3 + j == binaryMessageLength + 1) {
        bitVal = (messageLength >> 16) & 0xFF;
      } else if (i * 3 + j == binaryMessageLength + 2) {
        bitVal = (messageLength >> 8) & 0xFF;
      } else {
        bitVal = messageLength & 0xFF;
      }
      if (j == 0) {
        pixel.red = setBit(pixel.red, 0, bitVal);
      } else if (j == 1) {
        pixel.green = setBit(pixel.green, 0, bitVal);
      } else {
        pixel.blue = setBit(pixel.blue, 0, bitVal);
      }
    }
    imagePixels[i] = pixel;
  }

  /* Hide message bits in remaining pixels */
  for (int i = 32; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
    Pixel pixel = imagePixels[i];
    for (int j = 0; j < 3; j++) {
      if (i * 3 + j < binaryMessageLength) {
        int bitVal = binaryMessage[i * 3 + j] - '0';
        if (j == 0) {
          pixel.red = setBit(pixel.red, 0, bitVal);
        } else if (j == 1) {
          pixel.green = setBit(pixel.green, 0, bitVal);
        } else {
          pixel.blue = setBit(pixel.blue, 0, bitVal);
        }
      }
    }
    imagePixels[i] = pixel;
  }
}

/* Function to reveal message hidden in image */
char* revealMessage(Pixel* imagePixels) {
  /* Get message length from first 32 pixels */
  int messageLength = 0;
  for (int i = 0; i < 32; i++) {
    Pixel pixel = imagePixels[i];
    int bitVal = getBit(pixel.red, 0);
    messageLength = (messageLength << 1) | bitVal;
    bitVal = getBit(pixel.green, 0);
    messageLength = (messageLength << 1) | bitVal;
    bitVal = getBit(pixel.blue, 0);
    messageLength = (messageLength << 1) | bitVal;
    if (i == 31) {
      messageLength = messageLength << 8;
    }
  }

  /* Extract message bits from remaining pixels */
  char* message = (char*)malloc((messageLength + 1) * sizeof(char));
  int charIndex = 0;
  char currentChar = 0;
  int currentCharBits = 0;
  for (int i = 32; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
    Pixel pixel = imagePixels[i];
    int bitVal = getBit(pixel.red, 0);
    currentChar = (currentChar << 1) | bitVal;
    currentCharBits++;
    if (currentCharBits == 8) {
      message[charIndex] = currentChar;
      charIndex++;
      currentChar = 0;
      currentCharBits = 0;
    }
    if (charIndex >= messageLength) {
      break;
    }

    bitVal = getBit(pixel.green, 0);
    currentChar = (currentChar << 1) | bitVal;
    currentCharBits++;
    if (currentCharBits == 8) {
      message[charIndex] = currentChar;
      charIndex++;
      currentChar = 0;
      currentCharBits = 0;
    }
    if (charIndex >= messageLength) {
      break;
    }

    bitVal = getBit(pixel.blue, 0);
    currentChar = (currentChar << 1) | bitVal;
    currentCharBits++;
    if (currentCharBits == 8) {
      message[charIndex] = currentChar;
      charIndex++;
      currentChar = 0;
      currentCharBits = 0;
    }
    if (charIndex >= messageLength) {
      break;
    }
  }
  message[messageLength] = '\0';
  return message;
}

/* Main function */
int main() {
  /* Read image file */
  Pixel imagePixels[IMAGE_WIDTH * IMAGE_HEIGHT];
  readImageFile(imagePixels, "example.bmp");

  /* Hide message in image */
  hideMessage(imagePixels, "This is a steganography example.");

  /* Save image file */
  saveImageFile(imagePixels, "output.bmp");

  /* Reveal message from image */
  Pixel revealedPixels[IMAGE_WIDTH * IMAGE_HEIGHT];
  readImageFile(revealedPixels, "output.bmp");
  char* revealedMessage = revealMessage(revealedPixels);
  printf("Revealed message: %s\n", revealedMessage);
  free(revealedMessage);

  return 0;
}