//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

int main() {
  int ch;
  int count_chars = 0;
  int count_words = 0;
  int count_lines = 0;
  int in_word = 0;

  printf("Enter some text, finish with Ctrl+D:\n");
  
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      count_lines++;
    }
    
    if (isalpha(ch)) {
      count_chars++;
      
      if (!in_word) {
        count_words++;
        in_word = 1;
      }
    } else {
      in_word = 0;
    }
  }

  printf("Characters: %d\n", count_chars);
  printf("Words: %d\n", count_words);
  printf("Lines: %d\n", count_lines);

  return 0;
}