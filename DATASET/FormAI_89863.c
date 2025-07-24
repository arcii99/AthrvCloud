//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a cheerful compression algorithm
void cheerCompress(char* str) {
  int len = strlen(str);
  char* compressed = (char*)malloc((2*len+1)*sizeof(char));

  // iterate over the string and compress it
  int idx = 0;
  int count = 1;
  for(int i=1;i<=len;i++) {
    if(str[i] == str[i-1]) {
      count++;
    } else {
      compressed[idx++] = str[i-1];
      compressed[idx++] = count + '0';
      count = 1;
    }
  }
  compressed[idx] = '\0';

  // print the compressed version
  printf("Compressed string: %s\n", compressed);

  // free the memory
  free(compressed);
}

int main() {
  // declare a sample string to compress
  char str[] = "Hello, world! This is a cheerful compression algorithm example!";

  // compress the string
  cheerCompress(str);

  return 0;
}