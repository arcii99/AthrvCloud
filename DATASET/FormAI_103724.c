//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>

// The case of the bitwise bandit

int main() {
  int clue_one = 0x3C;
  int clue_two = 0xA7;
  int clue_three = 0xAF;
  int suspect_num = 0xB7;

  printf("Welcome to the case of the bitwise bandit.\n\n");

  printf("We have three clues: %d, %d, %d.\n", clue_one, clue_two, clue_three);
  printf("Your task is to use bitwise operations to find the missing number.\n\n");

  // Searching for the missing number
  int partial_result = clue_one & clue_two;
  partial_result = partial_result | clue_three;
  int missing_num = suspect_num ^ partial_result;

  if (missing_num == 0x1A) {
    printf("Congratulations! You've solved the case of the bitwise bandit.\n");
    printf("The missing number is: %d\n", missing_num);
    printf("The suspect is now in custody.\n");
  } else {
    printf("Sorry, your solution is incorrect.\n");
    printf("The missing number is not: %d\n", missing_num);
    printf("Please try again.\n");
  }

  return 0;
}