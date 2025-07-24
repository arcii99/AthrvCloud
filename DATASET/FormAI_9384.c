//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Alan Touring
#include <stdio.h>

int main() {
  char text[1000], word[100];
  int i, j, found, count = 0;

  printf("Enter text: ");
  fgets(text, 1000, stdin);

  printf("Enter word to count: ");
  scanf("%s", word);

  for (i = 0; text[i] != '\0'; i++) {
    found = 1;
    for (j = 0; word[j] != '\0'; j++) {
      if (text[i + j] != word[j]) {
        found = 0;
        break;
      }
    }

    if (found == 1) {
      count++;
    }
  }

  printf("Total occurrences of '%s' = %d\n", word, count);

  return 0;
}