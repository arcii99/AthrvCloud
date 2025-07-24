//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char text[1000];
  printf("Hark, what text doth thee desire to count?\n");
  fgets(text, sizeof(text), stdin); // Receives input from user.

  int freq[26] = {0}, i, len = strlen(text);

  for (i = 0; i < len; i++) {
    if (isalpha(text[i])) {
      freq[tolower(text[i]) - 'a']++;
    }
  }

  printf("Lo, the frequency of words present in thine text be shown below:\n");
  printf("---------------------------------------------------------------\n");

  for (i = 0; i < 26; i++) {
    if (freq[i] != 0) {
      printf("'%c' appeareth %d times.\n", i + 'a', freq[i]);
    }
  }
  printf("---------------------------------------------------------------\n");

  printf("Hast thou another text to count, yon yes or nay?\n");
  char answer[3];
  fgets(answer, sizeof(answer), stdin);

  if (tolower(answer[0]) == 'y') {
    main(); // Calls the main function recursively.
  } else {
    printf("Adieu, farewell and good morrow, my friend.\n");
  }

  return 0;
}