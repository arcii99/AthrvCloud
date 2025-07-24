//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>

int main() {
  char message[100];
  unsigned int checksum = 0;
  int i, length;

  printf("Welcome! Let's create a Checksum for your message!\n");
  
  // Get message from user
  printf("\nEnter your message: ");
  scanf("%s", message);

  // Calculate length of message
  for (length = 0; message[length] != '\0'; ++length);

  // Calculate checksum
  for (i = 0; i < length; ++i) {
    checksum += (unsigned int) message[i] * (i + 1);
  }

  printf("\nYour Checksum is: %u\n", checksum);
  printf("\nCongratulations! Your Checksum is ready!\n");

  return 0;
}