//FormAI DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *phrase = "My love for memory management";
  char *new_phrase;
 
  printf("Phrase: %s\n", phrase);
 
  new_phrase = (char*) malloc(strlen(phrase) + 1); // allocating memory for new_phrase
  if (new_phrase == NULL) {
    printf("Failed to allocate memory for new_phrase.\n");
    exit(1);
  }
 
  strcpy(new_phrase, phrase);
  printf("New Phrase: %s\n\n", new_phrase);
 
  free(new_phrase); // freeing the memory allocated for new_phrase
 
  return 0;
}