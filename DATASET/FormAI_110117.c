//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int check_spelling(char *word) {
  char dictionary[5][10] = {"apple", "banana", "orange", "pear", "grape"};
  int found_word = 0;
  
  for(int i = 0; i<5; i++) {
    if(strcmp(word, dictionary[i]) == 0) {
      found_word = 1;
      break;
    }
  }
  
  return found_word;
}

int main() {
  char word[10];
  
  printf("Enter a word to check the spelling: ");
  scanf("%s", word);
  
  if(check_spelling(word)) {
    printf("The word %s is spelled correctly.\n", word);
  }
  else {
    printf("The word %s is spelled incorrectly.\n", word);
  }
  
  return 0;
}