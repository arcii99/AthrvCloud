//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
  char text[100] = "Welcome to my creative text processing program!";
  
  // count characters in the string
  int count = strlen(text);
  printf("The number of characters in the text is: %d\n", count);
  
  // change all lowercase letters to uppercase
  for (int i = 0; i < count; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = text[i] - 32;
    }
  }
  printf("Here is the text in all uppercase:\n%s\n", text);
  
  // reverse the text
  char reversed_text[100];
  for (int i = 0; i < count; i++) {
    reversed_text[i] = text[count - 1 - i];
  }
  reversed_text[count] = '\0';
  printf("Here is the text in reverse:\n%s\n", reversed_text);
  
  // count the number of occurances of a specific letter
  char letter = 'e';
  int letter_count = 0;
  for (int i = 0; i < count; i++) {
    if (text[i] == letter) {
      letter_count++;
    }
  }
  printf("The letter %c occurs %d times in the text.\n", letter, letter_count);
  
  // find and replace a specific word
  char word_to_replace[10] = "program";
  char replacement_word[10] = "code";
  char *word_position = strstr(text, word_to_replace);
  if (word_position != NULL) {
    int start_position = word_position - text;
    for (int i = start_position; i < start_position + strlen(word_to_replace); i++) {
      text[i] = replacement_word[i - start_position];
    }
  }
  printf("Here is the updated text with the word '%s' replaced with '%s':\n%s\n", word_to_replace, replacement_word, text);
  
  return 0;
}