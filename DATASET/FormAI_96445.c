//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000], watermark[100]; // define character arrays to store message and watermark
  int encrypt; // define integer variable to represent encryption key

  printf("Enter the message to be watermarked: ");
  fgets(message, sizeof(message), stdin); // allow user to enter message

  printf("Enter the watermark: ");
  fgets(watermark, sizeof(watermark), stdin); // allow user to enter watermark

  printf("Enter the encryption key (integer value): ");
  scanf("%d", &encrypt); // allow user to enter encryption key

  // initialize index variables for loops
  int i, j;

  // add watermark at the end of the message
  for (i = 0, j = strlen(message) - 1; i < strlen(watermark); i++, j++) {
    message[j] = watermark[i];
  }

  // encrypt the message using the encryption key
  for (i = 0; i < strlen(message); i++) {
    message[i] = message[i] + encrypt;
  }

  printf("Watermarked and encrypted message: %s", message); // display the watermarked and encrypted message
  return 0;
}