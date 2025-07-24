//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>

/* This program demonstrates a simple example of digital watermarking using
   bit manipulation techniques. */

int main(void) {
  char message[] = "This is a cheerful message!";
  int watermark = 0b11110000;  // Digital watermark to be embedded
  
  // Iterate through each character of the message and embed the watermark
  for (int i = 0; message[i] != '\0'; i++) {
    message[i] ^= watermark;
  }
  
  // Print the watermarked message
  printf("Watermarked Message:\n%s\n", message);
  
  // Extract the watermark from the watermarked message
  watermark = 0;
  for (int i = 0; message[i] != '\0'; i++) {
    watermark |= (message[i] & 0b00001111); // Extract lower 4 bits of each character
  }
  
  // Print the extracted watermark
  printf("Extracted Watermark: %X\n", watermark);
  
  return 0;
}