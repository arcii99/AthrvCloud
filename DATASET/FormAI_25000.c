//FormAI DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

char* async_compress(char* input) {
  char* output = (char*)malloc(MAX_SIZE);
  int i = 0, j = 0, count = 1;

  while (input[i]) {
    if (input[i] == input[i + 1]) {
      count++;
    } else {
      output[j++] = input[i];
      output[j++] = count + '0';
      count = 1;
    }

    i++;
  }

  output[j] = '\0';
  return output;
}

int main() {
  char input[MAX_SIZE];

  printf("Enter the string to compress: ");
  fgets(input, MAX_SIZE, stdin);

  unsigned int len = strlen(input);
  if (input[len - 1] == '\n') {
    input[len - 1] = '\0';
  }

  char* compressed = async_compress(input);
  printf("Compressed String: %s\n", compressed);

  free(compressed);
  return 0;
}