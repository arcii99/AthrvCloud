//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress a string using a unique algorithm
char *compress_string(char *str) {

  int length = strlen(str);
  char *compressed_str = (char *)malloc(sizeof(char) * length);
  int i, j = 0, count = 0;

  for (i = 0; i < length; i++) {

    count++;

    // if the next character is different than the current one or it's the last character
    if (str[i] != str[i + 1] || i == length - 1) {
      // store the character and the count of repetitions
      compressed_str[j++] = str[i];
      compressed_str[j++] = (char)(count + '0');
      count = 0;
    }
  }

  return compressed_str;
}

int main() {

  char str[] = "This is a unique compression algorithm";

  // compress the string using function compress_string
  char *compressed_str = compress_string(str);
  printf("Compressed string: %s\n", compressed_str);

  // free memory
  free(compressed_str);

  return 0;
}