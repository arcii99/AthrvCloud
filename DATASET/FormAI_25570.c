//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* str) {
  int len = strlen(str);
  char* compressed = malloc(len * sizeof(*compressed)); // allocate space for compressed string
  int idx = 0;
  int count = 1;

  for (int i = 0; i < len; i++) {
    if (str[i] == str[i+1]) {
      count++; // if next character is the same, increment count
    }
    else {
      compressed[idx++] = str[i];
      compressed[idx++] = '0' + count;
      count = 1; // reset count to 1
    }
  }

  compressed[idx] = '\0';
  return compressed;
}

int main() {
  char* str = "aabbbccdddd";
  char* compressed = compress(str);

  printf("Original string: %s\n", str);
  printf("Compressed string: %s\n", compressed);

  free(compressed);

  return 0;
}