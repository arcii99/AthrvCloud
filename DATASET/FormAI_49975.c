//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *string);

int main() {
  char string[] = "Hello, world! This is a happy compression algorithm!";
  
  printf("Original String: %s\n", string);
  
  compress(string);
  
  printf("Compressed String: %s\n", string);
  
  return 0;
}

void compress(char *string) {
  int length = strlen(string);
  char *compressed = (char*) calloc(length, sizeof(char));
  int j = 0;
  
  for(int i = 0; i < length;) {
    int count = 1;
    compressed[j] = string[i];
    i++;
    while(string[i] == compressed[j] && i < length) {
      count++;
      i++;
    }
    if(count > 1) {
      compressed[j + 1] = '0' + count;
      j++;
    }
    j++;
  }
  
  strcpy(string, compressed);
  free(compressed);
}