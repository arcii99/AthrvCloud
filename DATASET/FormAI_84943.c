//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Data structure to store Alien language and corresponding English word
typedef struct {
  char alien[20];
  char english[20];
} AlienDict;

// Function to translate Alien language word to English
char* translate(char* word, AlienDict dictionary[], int size) {
  for (int i = 0; i < size; i++) {
    if (strcmp(word, dictionary[i].alien) == 0) {
      return dictionary[i].english;
    }
  }
  return "Translation not found.";
}

int main() {
  // Alien language dictionary
  AlienDict dictionary[5] = {
    {"skree", "hello"},
    {"zorp", "goodbye"},
    {"flibbert", "please"},
    {"gork", "thank you"},
    {"glip-glop", "sorry"}
  };
  
  char input[20];
  int size = sizeof(dictionary) / sizeof(dictionary[0]);

  printf("Enter Alien word: ");
  fgets(input, 20, stdin);
  input[strcspn(input, "\n")] = 0; // Remove newline character from input

  char* translation = translate(input, dictionary, size);
  printf("Translation: %s\n", translation);

  return 0;
}