//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: puzzling
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Word Frequency Counter!\n");
  printf("Please enter a sentence (maximum 100 characters):\n");

  char sentence[101];
  fgets(sentence, 101, stdin);
  printf("You entered: %s\n", sentence);

  int count[26] = {0};
  char c;
  int i = 0;
  while (sentence[i]) {
    c = tolower(sentence[i]);
    if (c >= 'a' && c <= 'z') {
      count[c-'a']++;
    }
    i++;
  }

  printf("Here are the results:\n");
  for (i = 0; i < 26; i++) {
    if (count[i] > 0) {
      printf("%c: %d\n", 'a'+i, count[i]);
    }
  }

  printf("Did you notice anything peculiar about the output?\n");
  printf("Perhaps the frequencies are in a particular order...\n");
  printf("Try re-entering the sentence with a twist!\n");

  fgets(sentence, 101, stdin);
  printf("You entered: %s\n", sentence);

  int freq[26] = {0};
  i = 0;
  while (sentence[i]) {
    c = tolower(sentence[i]);
    if (c >= 'a' && c <= 'z') {
      freq[c-'a']++;
    }
    i++;
  }

  int maxfreq = 0;
  for (i = 0; i < 26; i++) {
    if (freq[i] > maxfreq) {
      maxfreq = freq[i];
    }
  }

  printf("Now let's see how the frequencies vary!\n");
  printf("Note: The '-' symbol denotes a frequency of zero.\n");

  for (i = maxfreq; i > 0; i--) {
    printf("%2d |", i);
    for (int j = 0; j < 26; j++) {
      if (freq[j] >= i) {
        printf(" * ");
        freq[j]--;
      } else {
        printf(" - ");
      }
    }
    printf("\n");
  }
  printf("   +");
  for (i = 0; i < 26; i++) {
    printf("---");
  }
  printf("\n     ");
  for (i = 0; i < 26; i++) {
    printf(" %c ", 'a'+i);
  }
  printf("\n");

  printf("This program has been brought to you by the letter 'C'!\n");
  return 0;
}