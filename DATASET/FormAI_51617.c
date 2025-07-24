//FormAI DATASET v1.0 Category: Math exercise ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, ans, response, correct = 0, wrong = 0;

  srand(time(0));

  for (int i = 0; i < 5; i++) {
      num1 = rand() % 10;
      num2 = rand() % 10;

      printf("\n%d + %d = ", num1, num2);
      scanf("%d", &response);

      ans = num1 + num2;

      if (ans == response) {
          printf("Correct!\n");
          correct++;
      } else {
          printf("Wrong! The correct answer is %d.\n", ans);
          wrong++;
      }
  }

  printf("\nYou got %d correct and %d wrong.\n", correct, wrong);

  if (correct == 5) {
      printf("Wow! Perfect score!\n");
  } else {
      printf("Keep practicing!\n");
  }

  return 0;
}