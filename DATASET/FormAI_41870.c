//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("Enter the text you want to watermark:\n");
  char text[250];
  fgets(text, 250, stdin);
  printf("\n");

  printf("Enter the watermark value:\n");
  char watermark[50];
  fgets(watermark, 50, stdin);

  // Calculate checksum of watermark
  int sum = 0;
  for(int i = 0; i < strlen(watermark) - 1; i++) {
    sum += watermark[i];
  }
  
  // Apply watermark to text by adding sum to each character
  for(int i = 0; i < strlen(text); i++) {
    text[i] += sum;
  }

  // Print the watermarked text
  printf("Watermarked text: \n%s\n", text);

  // Retrieve watermark by subtracting sum from each character
  for(int i = 0; i < strlen(text); i++) {
    text[i] -= sum;
  }
  
  // Print the retrieved watermark
  printf("Retrieved watermark: \n%s", text);

  return 0;
}