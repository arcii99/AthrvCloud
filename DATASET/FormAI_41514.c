//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include<stdio.h>
#include<string.h>

int main(){

  char alien_language[20], translated_text[20];

  printf("Welcome to the Alien Language Translator!\n");

  printf("Enter the text in Alien Language: ");
  scanf("%s", alien_language);

  // Translation code here
  int length = strlen(alien_language);
  for (int i = 0; i < length; i++) {
    translated_text[i] = alien_language[length - i - 1];
  }

  printf("The translated text in your language is: %s\n", translated_text);

  printf("I hope this translation helps you express your love to that special alien in your life.\n");

  return 0;
}