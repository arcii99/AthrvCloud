//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
  char text[] = "The quick brown fox jumps over the lazy dog";
  char find[] = "fox";
  char replace[] = "cat";
  char result[100];
  int i, j, k, n;
  int len_find = strlen(find);
  int len_replace = strlen(replace);
  int len_text = strlen(text);

  i = 0;
  j = 0;
  while (i < len_text) {
    if (text[i] == find[j]) {
      n = i;
      while ((text[i] == find[j]) && (j < len_find)) {
        i++;
        j++;
      }
      if (j == len_find) {
        j = 0;
        for (k = 0; k < len_replace; k++) {
          result[n + k] = replace[k];
        }
        n += len_replace;
      }
      else {
        for (k = 0; k <= i - n; k++) {
          result[n + k] = text[n + k];
        }
        n += (i - n + 1);
      }
    }
    else {
      result[i] = text[i];
      n = i++;
    }
  }
  result[i] = '\0';
  printf("The original text: %s\n", text);
  printf("The modified text: %s\n", result);

  return 0;
}