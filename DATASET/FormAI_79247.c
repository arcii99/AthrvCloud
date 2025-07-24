//FormAI DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
  char original_string[100] = "tHiS Is A wEiRd StRiNg!@#$";
  char new_string[100] = "";

  int len = strlen(original_string);

  for (int i = 0; i < len; i++) {
    char c = original_string[i];
    if (i % 2 == 0) {
      if (c >= 'a' && c <= 'z') {
        c = c - 32;
      }
    } else {
      if (c >= 'A' && c <= 'Z') {
        c = c + 32;
      } else if (c == ' ') {
        c = '_';
      } else if (c == '!') {
        c = '?';
      } else if (c >= '0' && c <= '9') {
        c = 'X';
      } else if (c == '@') {
        c = '%';
      } else if (c == '#') {
        c = '*';
      } else if (c == '$') {
        c = '&';
      }
    }
    strncat(new_string, &c, 1);
  }

  printf("%s\n", new_string);

  return 0;
}