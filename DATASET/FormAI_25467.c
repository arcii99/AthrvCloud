//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_LENGTH 10

void print_words(char words[MAX_WORDS][MAX_LENGTH], int len) {
  for (int i = 0; i < len; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  char words[MAX_WORDS][MAX_LENGTH] = {"apple", "banana", "cherry", "dog", "eagle", "frog", "grass", "helmet", "indigo", "jacket",
                                       "kite", "lemon", "mango", "notebook", "orange", "pepper", "quilt", "river", "scissors", "tiger"};
  
  int num_words = MAX_WORDS;
  int max_length = MAX_LENGTH-1;

  printf("Welcome to the typing speed test!\n");
  printf("You will be given a random set of words to type, and your typing speed will be measured in words per minute.\n");
  printf("Press enter to begin.\n");
  getchar();

  int num_correct = 0;
  int num_attempted = 0;
  double start_time = (double)clock() / CLOCKS_PER_SEC;
  double elapsed_time;

  while (1) {
    int index = rand() % num_words;
    char word[MAX_LENGTH];
    int len = sprintf(word, "%s", words[index]);
    word[len] = '\0';

    printf("Type this word: %s\n", word);
    char typed[MAX_LENGTH];
    scanf("%s", typed);

    if (strcmp(typed, word) == 0) {
      printf("Correct!\n");
      num_correct += 1;
    } else {
      printf("Incorrect!\n");
    }

    num_attempted += 1;
    elapsed_time = (double)clock() / CLOCKS_PER_SEC - start_time;
    printf("Elapsed time: %f\n", elapsed_time);
    if (elapsed_time >= 60.0) {
      break;
    }
  }

  double typing_speed = (double)num_attempted / elapsed_time * 60;
  printf("You typed %d words in %f seconds.\n", num_attempted, elapsed_time);
  printf("Your typing speed is: %.2lf words per minute.\n", typing_speed);
  printf("Accuracy: %.2lf%%\n", (double)num_correct / num_attempted * 100);

  return 0;
}