//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 10

int main()
{
  char words[MAX_WORDS][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "imbe", "jackfruit"};

  // Get a random set of words
  srand(time(NULL));
  char set_of_words[MAX_WORDS][MAX_WORD_LENGTH];
  for (int i = 0; i < MAX_WORDS; i++)
  {
    int random_num = rand() % MAX_WORDS;
    strcpy(set_of_words[i], words[random_num]);
  }

  // Print the set of words
  printf("Type the following words as quickly as you can:\n");
  for (int i = 0; i < MAX_WORDS; i++)
  {
    printf("%s ", set_of_words[i]);
  }
  printf("\n");

  // Get the starting time
  time_t start_time = time(NULL);

  // Allow the user to type in the words
  char input[MAX_WORDS * MAX_WORD_LENGTH];
  fgets(input, MAX_WORDS * MAX_WORD_LENGTH, stdin);

  // Get the ending time
  time_t end_time = time(NULL);

  // Calculate the elapsed time
  double elapsed_time = difftime(end_time, start_time);

  // Calculate the typing speed
  int num_chars = strlen(input) - 1; // Take off '\n' at the end
  double typing_speed = (double)num_chars / elapsed_time * 60; // chars per minute

  printf("You typed %d characters in %.2f seconds.\n", num_chars, elapsed_time);
  printf("Your typing speed is %.2f characters per minute.\n", typing_speed);

  return 0;
}