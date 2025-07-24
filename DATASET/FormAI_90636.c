//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

void translate(char alien[], int size) {
  if (size % 3 != 0) {
    printf("Invalid alien language\n");
    return;
  }

  for (int i = 0; i < size; i += 3) {
    if (alien[i] != 'p' || alien[i+1] != 'q' || alien[i+2] != 'r') {
      printf("Invalid alien language\n");
      return;
    }
  }

  char english[size/3];
  for (int i = 0; i < size; i += 3) {
    english[i/3] = 'a' + (alien[i+2] - '1');
  }
  english[size/3] = '\0';

  printf("English translation: %s\n", english);
}

int main() {
  char alien_lang1[] = {'p', 'q', 'r', 'p', 'q', 'r', 'p', 'q', 'r', 'p', 'q', 'r', 'p', 'q', 'r', '2'};
  char alien_lang2[] = {'p', 'q', 'p', 'q', 'r', 'p', 'q', 'r', 'p', 'q', 'r'};

  printf("Translation 1:\n");
  translate(alien_lang1, sizeof(alien_lang1)/sizeof(alien_lang1[0]));
  printf("\n");

  printf("Translation 2:\n");
  translate(alien_lang2, sizeof(alien_lang2)/sizeof(alien_lang2[0]));
  printf("\n");

  return 0;
}