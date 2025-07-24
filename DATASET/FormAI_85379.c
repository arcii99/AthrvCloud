//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This C program demonstrates a unique encryption method using ASCII values

int main(void) {
  char string[100]; // Initialize string to store user input
  int key; // Initialize variable to store key value
  int i; // Initialize loop counter variable
  int length; // Initialize variable to store length of string
  char encrypted[100]; // Initialize string to store encrypted message

  printf("Welcome to an exciting program that encrypts your message with a unique encryption method!\n");
  printf("Please enter your message: ");
  scanf("%s", string); // Scan user input for message
  length = strlen(string); // Get length of message

  printf("\nPlease enter a key value: ");
  scanf("%d", &key); // Scan user input for key

  // Loop through each character in the message and encrypt it
  for(i = 0; i < length; i++) {
    encrypted[i] = string[i] + key; // Add key value to ASCII value of character
  }

  printf("\nYour message has been encrypted! Here is the result: %s\n", encrypted);

  // Decrypt the message back to the original message using the same key
  for(i = 0; i < length; i++) {
    string[i] = encrypted[i] - key; // Subtract key value from ASCII value of character
  }

  printf("\nHere is your original message: %s\n", string);

  return 0;
}