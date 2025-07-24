//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

int main() {
  // Define variables
  char words[MAX_WORDS][MAX_WORD_LENGTH];
  char user_input[MAX_WORDS][MAX_WORD_LENGTH];
  char correct_input[MAX_WORDS][MAX_WORD_LENGTH];
  int word_count = 0;
  int correct_words = 0;
  int incorrect_words = 0;
  clock_t start_time, end_time;
  
  // Fill the words array with random words
  srand(time(NULL));
  for (int i = 0; i < MAX_WORDS; i++) {
    char random_word[MAX_WORD_LENGTH];
    for (int j = 0; j < MAX_WORD_LENGTH; j++) {
      random_word[j] = rand() % 26 + 'a';
    }
    strcpy(words[i], random_word);
  }
  
  // Prompt the user to start the typing test
  printf("Welcome to the Shape Shifting Typing Test! Press enter to start");
  getchar();
  
  // Record start time
  start_time = clock();
  
  // Display a random word for the user to type and check if it is correct
  while (word_count < MAX_WORDS) {
    printf("\nType the word: %s  ", words[word_count]);
    scanf("%s", user_input[word_count]);
    strcpy(correct_input[word_count], words[word_count]);
    for (int i = 0; i < strlen(user_input[word_count]); i++) {
      user_input[word_count][i] = tolower(user_input[word_count][i]);
    }
    for (int i = 0; i < strlen(correct_input[word_count]); i++) {
      correct_input[word_count][i] = toupper(correct_input[word_count][i]);
    }
    if (strcmp(user_input[word_count], correct_input[word_count]) == 0) {
      printf("Correct!\n");
      correct_words++;
    } else {
      printf("Incorrect. The correct word was: %s\n", correct_input[word_count]);
      incorrect_words++;
    }
    word_count++;
  }
  
  // Record end time and calculate typing speed
  end_time = clock();
  double typing_speed = (double) (MAX_WORDS * MAX_WORD_LENGTH) / ((double) ((end_time - start_time) / CLOCKS_PER_SEC) / 60);
  
  // Display results
  printf("\n\nTyping Test Results:\n");
  printf("Total Words: %d\n", MAX_WORDS);
  printf("Correct Words: %d\n", correct_words);
  printf("Incorrect Words: %d\n", incorrect_words);
  printf("Typing Speed: %.2f WPM\n", typing_speed);
  
  return 0;
}