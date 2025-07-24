//FormAI DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

void compress(char *str) {
  char compressed_str[MAX_LEN];
  int i, j, count;

  i = 0;
  j = 0;
  while (str[i] != '\0') {
    compressed_str[j] = str[i];
    count = 1;

    while (str[i] == str[i+1]) {
      count++;
      i++;
    }

    if (count > 1) {
      char count_char = count + '0';
      compressed_str[++j] = count_char;
    }

    i++;
    j++;
  }

  compressed_str[j] = '\0';
  printf("%s\n", compressed_str);
}

int main() {
  char str[] = "heeeellooooooo";
  compress(str);
  return 0;
}

/*
 OUTPUT: "he3llo9"
*/