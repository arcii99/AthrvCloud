//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 50

char *dictionary[] = {"apple","ball","cat","dog","egg","frog","goose","house","internet","jolly"};
int dictionary_length = 10;

bool is_word_in_dictionary(char *word) {
  for(int i = 0; i < dictionary_length; i++) {
    if(strcmp(word, dictionary[i]) == 0)
      return true;
  }
  return false;
}

int main() {
  char word[MAX_WORD_LEN + 1];
  int word_len = 0;
  int index = 0;

  printf("Enter a sentence: ");

  while(true) {
    index = getchar();
    if(isalpha(index) || (index == '\'' && word_len > 0)) {
      if(word_len == MAX_WORD_LEN) {
        while((index = getchar()) != EOF && isalpha(index));
        word_len = 0;
      } else {
        word[word_len++] = tolower(index);
      }
    } else if(isdigit(index)) {
      while((index = getchar()) != EOF && isalnum(index));
      word_len = 0;
    } else if(index == EOF) {
      break;
    } else {
      if(word_len > 0) {
        word[word_len] = '\0';
        if(!is_word_in_dictionary(word)) {
          printf("%s is spelled incorrectly\n", word);
        }
        word_len = 0;
      }
    }
  }

  printf("\n");
  return 0;
}