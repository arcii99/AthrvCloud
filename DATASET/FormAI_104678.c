//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 50

// Function prototypes
void read_words_from_file(char file_name[], char words[MAX_WORDS][MAX_WORD_LENGTH], int *num_words);
void translate_phrase(char phrase[], char translation[], char words[MAX_WORDS][MAX_WORD_LENGTH], int num_words);

int main() {
 
  // Open file with alien words and read them into an array
  char file_name[] = "alien_words.txt";
  char words[MAX_WORDS][MAX_WORD_LENGTH];
  int num_words = 0;
  read_words_from_file(file_name, words, &num_words);

  // Ask user for phrase to translate
  printf("Enter a phrase to translate: ");
  char phrase[MAX_WORD_LENGTH * MAX_WORDS];
  fgets(phrase, MAX_WORD_LENGTH * MAX_WORDS, stdin);
  phrase[strcspn(phrase, "\n")] = 0; // Remove newline character

  // Translate the phrase
  char translation[MAX_WORD_LENGTH * MAX_WORDS];
  translate_phrase(phrase, translation, words, num_words);

  // Print the translation
  printf("Translation: %s\n", translation);

  return 0;
}

// Reads words from a file and stores them in an array
void read_words_from_file(char file_name[], char words[MAX_WORDS][MAX_WORD_LENGTH], int *num_words) {
  FILE *file = fopen(file_name, "r");
  
  if (file == NULL) {
    printf("Error: could not open file %s\n", file_name);
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LENGTH];
  while (fgets(word, MAX_WORD_LENGTH, file)) {
    word[strcspn(word, "\n")] = 0; // Remove newline character
    strcpy(words[*num_words], word);
    (*num_words)++;
  }

  fclose(file);
}

// Translates a phrase using an array of alien words
void translate_phrase(char phrase[], char translation[], char words[MAX_WORDS][MAX_WORD_LENGTH], int num_words) {
  char *word = strtok(phrase, " ");
  strcpy(translation, ""); // Start with empty string

  while (word != NULL) {
    int found_word = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(word, words[i]) == 0) {
        strcat(translation, words[num_words - i - 1]); // Reverse order of words
        found_word = 1;
        break;
      }
    }
    if (!found_word) { // Word not found in array
      strcat(translation, word);
    }
    strcat(translation, " ");
    word = strtok(NULL, " ");
  }
}