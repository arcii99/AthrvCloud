//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 15
#define MAX_TIME 60

int main() {
  char words[MAX_WORDS][MAX_WORD_LENGTH];
  char input[MAX_WORD_LENGTH];
  int i, j, count = 0, time_left = MAX_TIME;
  clock_t start_time, current_time;

  // Initialize random seed
  srand(time(NULL));

  // Generate random words
  for (i = 0; i < MAX_WORDS; i++) {
    for (j = 0; j < MAX_WORD_LENGTH - 1; j++) {
      words[i][j] = rand() % 26 + 'a'; // Generate random lowercase letters
    }
    words[i][j] = '\0'; // Null terminate string
  }

  // Print instructions
  printf("Welcome to the typing speed test!\n");
  printf("You have %d seconds to type as many words as you can.\n", MAX_TIME);
  printf("Press enter after each word.\n");
  printf("Type 'start' when you're ready to begin.\n");

  // Wait for user to type 'start'
  fgets(input, MAX_WORD_LENGTH, stdin);
  while (strcmp(input, "start\n") != 0) {
    printf("Type 'start' to begin.\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
  }

  // Start the timer
  start_time = clock();

  // Loop until time runs out
  while (time_left > 0) {
    // Generate random index
    i = rand() % MAX_WORDS;

    // Print word and wait for input
    printf("%s", words[i]);
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Check if input matches
    if (strcmp(input, words[i]) == 0) {
      count++;
    }

    // Get current time and calculate time left
    current_time = clock();
    time_left = MAX_TIME - (int)(current_time - start_time) / CLOCKS_PER_SEC;
    printf("Time left: %d seconds.\n", time_left);
  }

  // Print results
  printf("Time's up!\n");
  printf("You typed %d words in %d seconds.\n", count, MAX_TIME);
  printf("Your typing speed is %d words per minute.\n", (int)((float)count / MAX_TIME * 60));

  return 0;
}