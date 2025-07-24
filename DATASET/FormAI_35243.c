//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM 0
#define MAX_NUM 100

int main() {
  int user_input, num1, num2, result, correct_answers = 0, incorrect_answers = 0;
  double time_taken;
  clock_t t;

  printf("Welcome to the Typing Speed Test\n");
  printf("You will be presented with two random numbers between %d and %d\n", MIN_NUM, MAX_NUM);
  printf("Your job is to enter the correct sum of these two numbers\n");
  printf("You will have 10 seconds to answer each question\n");
  
  while (1) {
    num1 = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
    num2 = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
    result = num1 + num2;

    printf("%d + %d = ?", num1, num2);

    t = clock();
    scanf("%d", &user_input);
    t = clock() - t;

    if (user_input == result && ((double)t/CLOCKS_PER_SEC) <= 10.0) {
      printf("Correct! Time taken: %f seconds\n\n", (double)t/CLOCKS_PER_SEC);
      correct_answers++;
    } else {
      printf("Incorrect or Time elapsed! Time taken: %f seconds\nThe answer is: %d\n\n", (double)t/CLOCKS_PER_SEC, result);
      incorrect_answers++;
    }

    if (correct_answers + incorrect_answers == 10) break; // stop after 10 questions
  }

  time_taken = (double)t/CLOCKS_PER_SEC;
  printf("Results: Correct answers: %d | Incorrect answers: %d | Time taken: %f seconds\n", correct_answers, incorrect_answers, time_taken);

  return 0;
}