//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_SIZE 100
#define TIME_LIMIT 60

int main() {
  char input[MAX_STRING_SIZE];
  char sentence[MAX_STRING_SIZE] = "The quick brown fox jumps over the lazy dog";

  int correct_chars = 0;
  int total_chars = strlen(sentence);
  int start_time = time(NULL);
  int elapsed_time = 0;

  printf("Welcome to the Typing Speed Test!\n");
  printf("You have %d seconds to type the following sentence:\n\n", TIME_LIMIT);
  printf("%s\n\n", sentence);

  while (elapsed_time < TIME_LIMIT) {
    printf("[Elapsed time: %d seconds] Type the sentence and press enter:\n", elapsed_time);
    fgets(input, MAX_STRING_SIZE, stdin);

    input[strcspn(input, "\n")] = 0;  // Remove newline from input

    if (strcmp(input, sentence) == 0) {
      printf("Congratulations! You typed the sentence correctly.\n");
      break;
    } else {
      for (int i = 0; i < strlen(input); i++) {
        if (input[i] != sentence[i]) {
          break;
        } else {
          correct_chars++;
        }
      }

      printf("Incorrect. You typed %d out of %d characters correctly. Try again!\n\n", correct_chars, total_chars);
    }

    elapsed_time = time(NULL) - start_time;
  }

  if (elapsed_time >= TIME_LIMIT) {
    printf("Time's up! You typed %d out of %d characters correctly.\n", correct_chars, total_chars);
  }

  return 0;
}