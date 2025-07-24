//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <ctype.h>

int word_count(const char *sentence);

int main() {
  char sentence[100];
  
  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  int count = word_count(sentence);

  printf("\nWord count: %d\n", count);
  
  return 0;
}

int word_count(const char *sentence) {
  int count = 0;
  int is_word = 0;
  
  while (*sentence) {
    if (isspace(*sentence)) {
      is_word = 0;
    } else if (!is_word) {
      is_word = 1;
      count++;
    }
    
    sentence++;
  }
  
  return count;
}