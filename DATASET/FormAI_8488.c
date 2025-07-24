//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000
#define MAX_TIME_ALLOWED 60

int main() {
  char str[MAX_STRING_LENGTH];
  srand(time(NULL));
  int seconds_left = MAX_TIME_ALLOWED, i = 0, correct_count = 0, total_count = 0, cpm;
  time_t start_time, current_time;

  printf("Welcome to the Cryptic Typing Speed Test!\n");
  printf("Your goal is to type as many correctly spelled words as possible in %d seconds.\n", MAX_TIME_ALLOWED);
  printf("To start the timer, type 'start': ");
  fgets(str, MAX_STRING_LENGTH, stdin);

  if(strncmp("start", str, strlen("start"))) {
    printf("\nInvalid input. Please try again.\n");
    return 0;
  }

  printf("\nTest will begin in:\n\n");
  while(seconds_left >= 1) {
    printf("%d\n", seconds_left);
    sleep(1);
    seconds_left--;
  }
  time(&start_time);

  printf("\nGO!\n\n");
  while(seconds_left >= 0) {
    printf("Type the next word: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    total_count++;

    if(strncmp("end", str, strlen("end")) == 0) {
      break;
    }

    if(strncmp("secret", str, strlen("secret")) == 0) {
      printf("You found the secret word!\n");
      continue;
    }

    if(strncmp("help", str, strlen("help")) == 0) {
      printf("The goal is to type as many correctly spelled words as possible.\n");
      continue;
    }

    if(strncmp("hint", str, strlen("hint")) == 0) {
      printf("The next word is %d letters long.\n", rand() % 10 + 1);
      continue;
    }

    if(strncmp("rules", str, strlen("rules")) == 0) {
      printf("You have %d seconds to type as many correctly spelled words as possible.\n", MAX_TIME_ALLOWED);
      continue;
    }

    if(isalpha(str[0])) {
      correct_count++;
    }

    seconds_left--;
  }

  time(&current_time);
  double time_taken = difftime(current_time, start_time);
  cpm = correct_count / (time_taken / 60);

  printf("\nTest Complete!\n");
  printf("Words Typed Correctly: %d/%d\n", correct_count, total_count);
  printf("Characters per Minute: %d\n", cpm);

  return 0;
}