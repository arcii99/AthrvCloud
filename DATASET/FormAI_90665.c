//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 20
#define MAX_INPUT_LEN 100

void printInstructions();
void generateWords(char words[MAX_WORDS][MAX_WORD_LEN]);
int checkInput(char* input, char* expected);

int main() {
  char words[MAX_WORDS][MAX_WORD_LEN];
  printInstructions();
  generateWords(words);
  
  int i;
  int correct = 0;
  int incorrect = 0;
  double time_spent = 0.0;
  clock_t begin, end;

  for (i = 0; i < MAX_WORDS; i++) {
    char input[MAX_INPUT_LEN];
    char* expected = words[i];
    printf("%d) %s\n", i+1, expected);
    begin = clock();
    fgets(input, MAX_INPUT_LEN, stdin);
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    if (checkInput(input, expected)) {
      printf("Correct!\n");
      correct++;
    } else {
      printf("Incorrect.\n");
      incorrect++;
    }
  }

  printf("\nResults:\n");
  printf("Time: %.2f seconds\n", time_spent);
  printf("Correct: %d\n", correct);
  printf("Incorrect: %d\n", incorrect);

  return 0;
}

void generateWords(char words[MAX_WORDS][MAX_WORD_LEN]) {
  const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  srand(time(NULL));
  int i, j;
  for (i = 0; i < MAX_WORDS; i++) {
    for (j = 0; j < MAX_WORD_LEN-1; j++) {
      int index = rand() % strlen(characters);
      words[i][j] = characters[index];
    }
    words[i][MAX_WORD_LEN-1] = '\0';
  }
}

int checkInput(char* input, char* expected) {
  input[strlen(input)-1] = '\0'; // remove newline character
  if (strcmp(input, expected) == 0) {
    return 1;
  }
  return 0;
}

void printInstructions() {
  printf("Welcome to the Typing Speed Test!\n");
  printf("You will be given a series of words to type.\n");
  printf("Type each word and press enter.\n");
  printf("You will be notified whether you typed correctly or not.\n\n");
}