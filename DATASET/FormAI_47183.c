//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a compression function that takes in a string and compresses it using a unique algorithm
char* compress(char* message) {
  int len = strlen(message);
  char* compressed = (char*)malloc(sizeof(char) * (len + 1));
  int count = 0;
  int index = 0;
  
  for (int i = 0; i < len; i++) {
    if (message[i] == message[i + 1]) {
      count++;
    } else {
      count++;
      compressed[index] = count + '0';
      compressed[++index] = message[i];
      count = 0;
      index++;
    }
  }

  // add a null terminator to the compressed string
  compressed[index] = '\0';

  return compressed;
}

int main() {
  // test the compression function with a sample message
  char message[] = "Happily compressing strings with my unique algorithm!";
  char* compressed = compress(message);
  
  printf("Original message: %s\n", message);
  printf("Compressed message: %s\n", compressed);

  // free the memory allocated to the compressed string
  free(compressed);

  return 0; 
}