//FormAI DATASET v1.0 Category: Text processing ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
  char text[MAX_LENGTH], reversed[MAX_LENGTH];
  int i, j, len;
  printf("Enter some text: ");
  fgets(text, MAX_LENGTH, stdin);
  len = strlen(text);
  
  // Reversing the text
  for (i = 0, j = len - 1; j >= 0; i++, j--) {
    reversed[i] = text[j];
  }
  reversed[i] = '\0';
  
  // Counting the number of words in the text
  int wordCount = 0;
  for (i = 0; i < len; i++) {
    if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
      wordCount++;
    }
  }
  
  // Counting the number of vowels in the text
  int vowelCount = 0;
  for (i = 0; i < len; i++) {
    if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
        text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
      vowelCount++;
    }
  }
  
  printf("\nReversed text: %s", reversed);
  printf("\nNumber of words: %d", wordCount);
  printf("\nNumber of vowels: %d", vowelCount);
  
  return 0;
}