//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The following is a C Compression Algorithm named "Elementary Watson" inspired by 
the Great Sherlock Holmes' keen observation skills. */

char* elementary_watson(char* uncompressed) {
  int len = strlen(uncompressed);
  int compressed_len = 0;
  int i, j = 0;

  // Storing the uncompressed string in an array
  char* comp_str = (char*)malloc(sizeof(char) * (len + 1));

  for(i = 0; i < len; i++) {
    int count = 1;
    while(i < len - 1 && uncompressed[i] == uncompressed[i + 1]) {
      count++;
      i++;
    }
    if(count == 1) {
      comp_str[j] = uncompressed[i];
    } else {
      char count_str[10];
      sprintf(count_str, "%d", count);
      for(int x = 0; x < strlen(count_str); x++) {
        comp_str[j++] = count_str[x];
      }
      comp_str[j] = uncompressed[i];
    }
    j++;
  }
  compressed_len = strlen(comp_str);

  printf("Uncompressed String: %s and its Length: %d\n", uncompressed, len);
  printf("Compressed String: %s and its Length: %d\n", comp_str, compressed_len);

  return comp_str;
}

int main() {
  char* uncompressed = "aabbbccccaddee";
  elementary_watson(uncompressed);

  return 0;
}