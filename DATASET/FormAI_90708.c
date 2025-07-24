//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scalable
// C Cat Language Translator

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

// function declarations
void translate_sentence(char sentence[]);
void translate_word(char word[]);
int is_vowel(char c);

int main() {
  // prompt user to enter a sentence
  printf("Enter a sentence in C Cat language:\n");
  char sentence[MAX_LENGTH];
  fgets(sentence, MAX_LENGTH, stdin);

  // translate the sentence
  translate_sentence(sentence);

  return 0;
}

// function to translate a sentence
void translate_sentence(char sentence[]) {
  // declare a variable to store the translated sentence
  char translated_sentence[MAX_LENGTH] = "";

  // iterate through each word in the sentence
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    // translate the word and add it to the translated sentence
    char translated_word[MAX_LENGTH] = "";
    translate_word(token);
    strcat(translated_sentence, translated_word);
    strcat(translated_sentence, " ");

    // move on to the next word
    token = strtok(NULL, " ");
  }

  // display the translated sentence
  printf("The translated sentence is:\n%s", translated_sentence);
}

// function to translate a word
void translate_word(char word[]) {
  // remove the trailing newline character
  word[strcspn(word, "\n")] = '\0';

  // check if the first letter is a vowel
  if (is_vowel(word[0])) {
    strcat(word, "meow");
  } else {  // if the first letter is a consonant
    // move the first letter to the end
    char first_letter = word[0];
    memmove(&word[0], &word[1], strlen(word));
    word[strlen(word)] = first_letter;

    // add "meow" to the end
    strcat(word, "meow");
  }
}

// function to check if a character is a vowel
int is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}