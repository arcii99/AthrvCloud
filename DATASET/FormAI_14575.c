//FormAI DATASET v1.0 Category: Memory management ; Style: Claude Shannon
/*Consider a program that reads in a long sequence of words and adds them to a dynamically allocated word list array.
In C, heap memory is explicitly allocated and deallocated, so it is up to the programmer to ensure that the memory is
used responsibly and efficiently. This program demonstrates proper memory allocation and deallocation techniques.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int main() {
  //Allocate memory for the array of pointers
  char** word_list = malloc(sizeof(char*) * MAX_WORDS);
  if (word_list == NULL) {
    printf("Memory allocation failed. Exiting.");
    exit(1);
  }

  //Initialize the array of pointers to NULL
  for (int i = 0; i < MAX_WORDS; i++) {
    word_list[i] = NULL;
  }

  //Read in words and add them to the array
  char input[MAX_WORD_LEN];
  int count = 0;
  while (scanf("%s", input) != EOF && count < MAX_WORDS) {
    //Allocate memory for the current word
    char* new_word = malloc(sizeof(char) * (strlen(input) + 1));
    if (new_word == NULL) {
      printf("Memory allocation failed. Exiting.");
      exit(1);
    }

    //Copy the word into the allocated memory
    strcpy(new_word, input);

    //Add the word pointer to the array
    word_list[count] = new_word;
    count++;
  }

  //Print out the word list
  for (int i = 0; i < MAX_WORDS; i++) {
    if (word_list[i] != NULL) {
      printf("%s ", word_list[i]);
    }
  }

  printf("\n");

  //Free the allocated memory
  for (int i = 0; i < MAX_WORDS; i++) {
    if (word_list[i] != NULL) {
      free(word_list[i]);
      word_list[i] = NULL;
    }
  }

  free(word_list);
  word_list = NULL;

  return 0;
}