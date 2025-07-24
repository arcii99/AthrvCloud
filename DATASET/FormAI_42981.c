//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a curious compression algorithm that replaces all consecutive repeating characters 
   with a single character followed by the number of repetitions */

char *compress(char *str) {
  int len = strlen(str);
  char *compressed = (char *)malloc(len + 1);
  int i, j;

  for (i = 0, j = 0; i < len; i++) {
    compressed[j++] = str[i];
    int count = 1;
    while (i + 1 < len && str[i] == str[i + 1]) {
      count++;
      i++;
    }
    if (count >= 2) {
      char buffer[10];
      sprintf(buffer, "%d", count);
      int buf_len = strlen(buffer);
      for (int k = 0; k < buf_len; k++) {
        compressed[j++] = buffer[k];
      }
    }
  }

  compressed[j] = '\0';
  return compressed;
}

int main() {
  char original_str[100];
  printf("Enter a string: ");
  fgets(original_str, 100, stdin);
  original_str[strcspn(original_str, "\n")] = '\0';

  char *compressed_str = compress(original_str);
  printf("Compressed string: %s\n", compressed_str);
  free(compressed_str);

  return 0;
}