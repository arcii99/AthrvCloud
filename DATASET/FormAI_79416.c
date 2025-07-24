//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
  // Take input message from user
  char message[MAX_LEN];
  printf("Enter your message: ");
  scanf("%[^\n]s", message);

  // Take input watermark from user
  char watermark[MAX_LEN];
  printf("Enter watermark: ");
  scanf("%[^\n]s", watermark);

  // Create a new pointer to store the watermarked message
  char *watermarked_message = malloc(strlen(message) + strlen(watermark) + 1);

  // Add the watermark to the message
  sprintf(watermarked_message, "%s%s", message, watermark);

  // Print the watermarked message
  printf("Watermarked message: %s", watermarked_message);

  // Free the memory allocated to the new pointer
  free(watermarked_message);

  // Exit the program
  return 0;
}