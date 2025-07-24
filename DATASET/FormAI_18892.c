//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

char* convert(char* word) {
  if (strlen(word) == 0) {
    return "";
  } else {
    char* sound = "meow";
    char* meow = strcat(sound, convert(word + 1));
    return meow;
  }
}

int main() {
  char word[100];
  
  printf("Enter a word to translate to cat language: ");
  scanf("%s", word);
  
  char* catSpeak = convert(word);
  
  printf("Translation to cat language: %s\n", catSpeak);
  
  return 0;
}