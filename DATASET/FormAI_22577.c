//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

char alien_dict[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

void translate(char *s) {
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      printf(" ");
    } else {
      printf("%c", alien_dict[s[i] - 'a']);
    }
  }
}

int main() {
  int t;
  scanf("%d\n", &t);

  for (int i = 1; i <= t; i++) {
    char s[101];
    fgets(s, 101, stdin);
    printf("Case #%d: ", i);
    translate(s);
    printf("\n");
  }

  return 0;
}