//FormAI DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char text[1000], word[100];
  int count = 0, i;

  printf("Enter a text: ");
  fgets(text, 1000, stdin);

  printf("Enter the word you want to count: ");
  scanf("%s", word);

  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == word[0]) {
      int j = 0;
      while (text[i + j] == word[j] && word[j] != '\0') {
        j++;
      }
      if (word[j] == '\0') {
        count++;
      }
    }
  }

  printf("The word \"%s\" appears %d times in the text.", word, count);

  return 0;
}

/*
 * This is a C Word Count Tool program that allows a user
 * to enter a text and a word they want to count in the text.
 * The program then counts the number of times the word appears
 * in the text and displays the count to the user.
 */