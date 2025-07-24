//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char message[1000] = "Surrealism is a cultural movement that began in the early 1920s in France, and is best known for its visual artwork and writings. One of the key tools used in this movement is the concept of the 'unconscious mind', and the idea that it can be harnessed to create new and unexpected connections and meanings. In this program, we will use a similar method to create a unique digital watermarking technique.";

  int watermark[] = { 5, 13, 27, 32, 45, 61, 77, 83, 92, 99 }; // indexes of characters to mark
  int count = sizeof(watermark)/sizeof(int); // number of characters to mark

  int watermarkChar = 33; // ASCII code for '!'
  int nonWatermarkChar = 42; // ASCII code for '*'

  int i;
  for(i=0; i<count; i++) {
    message[watermark[i]] = watermarkChar; // mark character with watermark
  }

  for(i=0; i<strlen(message); i++) {
    if(message[i] != watermarkChar) { // if character is not already marked
      message[i] = nonWatermarkChar; // mark it with non-watermark character
    }
  }

  printf("%s\n", message); // output the marked message

  return 0;
}