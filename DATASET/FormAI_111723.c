//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Ken Thompson's Unique Compression Algorithm
char *compress(char *text) {
  int count = 1;
  char *result = malloc(strlen(text) + 1);
  char *p = result;
  char c = *text;

  while (*text) {
    if (c != *++text) {
      if (count == 1) {
        *p++ = c;
      } else {
        *p++ = count + '0';
        *p++ = c;
      }

      c = *text;
      count = 1;
      
      if (p - result >= strlen(text)) {
        break;
      }
    } else {
      count++;
    }
  }

  *p = '\0';
  return result;
}

int main() {
  char *input = "aaabbbccccdddeeeee";
  char *output = compress(input);

  printf("Input: %s\n", input);
  printf("Output: %s\n", output);

  free(output);
  return 0;
}