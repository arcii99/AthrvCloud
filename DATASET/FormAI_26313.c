//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int recursive_puzzler(int n) {
  if (n <= 0) {
    printf("Congratulations, the answer was right in front of you all along!");
    return 42;
  } else {
    printf("What is the answer to life, the universe, and everything?\n");
    int guess;
    scanf("%d", &guess);
    if (guess == 42) {
      printf("You got it, well done!\n");
      return recursive_puzzler(n-1);
    } else {
      printf("Wrong answer, try again.\n");
      return recursive_puzzler(n);
    }
  }
}

int main() {
  printf("Welcome to the recursive puzzler!\n");
  printf("You have 3 attempts to guess the answer to life, the universe, and everything.\n");
  printf("Good luck!\n");

  int result = recursive_puzzler(3);

  printf("Result: %d\n", result);

  return 0;
}