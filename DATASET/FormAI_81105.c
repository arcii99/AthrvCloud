//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
int generateRandomInt(int min, int max);
int getBit(int integer, int bit);
int setBit(int integer, int bit, int value);

int main() {
  char message[50] = "Hello, world!";  // The message to be watermarked
  int watermark = generateRandomInt(1000, 9999);  // Generate a random watermark value
  int messageLength = strlen(message);  // The length of the message in characters
  int bitsPerChar = 8;  // The number of bits required to represent a character in ASCII

  printf("Message: %s\n", message);
  printf("Watermark: %d\n", watermark);

  // Create a new message with the watermark embedded in it
  char watermarkedMessage[messageLength * bitsPerChar + 1];
  int watermarkedMessageIndex = 0;

  for (int i = 0; i < messageLength; i++) {
    char currentChar = message[i];

    // Embed the watermark in the least significant bit of each character
    for (int j = 0; j < bitsPerChar; j++) {
      int bit = getBit(currentChar, j);

      if (j == 0) {
        bit = getBit(watermark, 0);
      }

      watermarkedMessage[watermarkedMessageIndex++] = bit ? '1' : '0';
    }
  }

  watermarkedMessage[watermarkedMessageIndex] = '\0';

  printf("Watermarked message: %s\n", watermarkedMessage);

  // Extract the watermark from the watermarked message
  int extractedWatermark = 0;

  for (int i = 0; i < 4; i++) {
    char currentCharBinary[9];
    strncpy(currentCharBinary, &watermarkedMessage[i * bitsPerChar], bitsPerChar);
    currentCharBinary[8] = '\0';
    int currentChar = strtol(currentCharBinary, NULL, 2);

    extractedWatermark = setBit(extractedWatermark, i, getBit(currentChar, 0));
  }

  printf("Extracted watermark: %d\n", extractedWatermark);

  return 0;
}

// Generate a random integer between min and max inclusive
int generateRandomInt(int min, int max) {
  srand(time(NULL));
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// Get the value of the specified bit in the integer
int getBit(int integer, int bit) {
  return (integer >> bit) & 1;
}

// Set the value of the specified bit in the integer to the specified value
int setBit(int integer, int bit, int value) {
  if (value) {
    integer |= 1 << bit;
  } else {
    integer &= ~(1 << bit);
  }

  return integer;
}