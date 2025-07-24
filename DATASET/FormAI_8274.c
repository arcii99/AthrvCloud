//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char message[1000];
  char watermark[] = "DigitalWatermark_123";
  char encoded_message[1100];
  char decoded_message[1000];
  int i, j, k, l;

  printf("Enter the message to encode with digital watermark:\n");
  gets(message);

  // Encoding the message
  for(i=0, j=0; message[i] != '\0'; i++, j++) {
    if (j >= strlen(watermark)) {
      j = 0;
    }
    encoded_message[i] = message[i] + watermark[j];
  }
  encoded_message[i] = '\0';

  printf("\nEncoded Message: %s\n", encoded_message);

  // Decoding the message
  for(k=0, l=0; encoded_message[k] != '\0'; k++, l++) {
    if (l >= strlen(watermark)) {
      l = 0;
    }
    decoded_message[k] = encoded_message[k] - watermark[l];
  }
  decoded_message[k] = '\0';

  printf("\nDecoded Message: %s\n", decoded_message);

  return 0;
}