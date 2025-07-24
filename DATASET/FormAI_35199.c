//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  printf("Enter a sentence:\n");
  fgets(sentence, 100, stdin); // gets user input

  char word[20];
  printf("Enter a word to search for:\n");
  scanf("%s", word); // gets user input

  char *found = strstr(sentence, word); // finds first occurrence of word in sentence
  if (found == NULL) {
    printf("Sorry, the word was not found in the sentence.");
  } else {
    printf("The word was found at position %d in the sentence.\n",found-sentence+1);

    int occurrences = 0;
    while (found != NULL) { // finds further occurrences of word in sentence
      occurrences++;
      found = strstr(found+1, word);
    }

    printf("The word occurred %d time(s) in the sentence.\n", occurrences);

    // capitalizes all occurrences of word in sentence
    for (int i = 0; i < strlen(sentence); i++) {
      char *new_found = strstr(found+1, word); // finds next occurrence of word
      if (found == NULL) { // end of sentence
        break;
      }
      if (found == &sentence[i]) { // word found at current index
        for (int j = 0; j < strlen(word); j++) { // capitalizes word
          sentence[i+j] = toupper(sentence[i+j]);
        }
      }
      found = new_found; // assigns next occurrence of word to found
    }

    printf("The sentence with capitalized word(s):\n%s", sentence);
  }

  return 0;
}