//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Fibonacci Sequence Visualizer!\n");

  int first_term = 0;
  int second_term = 1;
  int num_terms;

  printf("\nHow many terms of the sequence would you like to see? ");
  scanf("%d", &num_terms);

  if (num_terms <= 0) {
    printf("Sorry, we can't show you any terms with that input.\n");
    return 0;
  }
  
  if (num_terms == 1) {
    printf("Here's your Fibonacci Sequence: %d\n", first_term);
    return 0;
  }

  printf("Here's your Fibonacci Sequence:\n%d\n%d\n", first_term, second_term);

  for (int i = 2; i < num_terms; i++) {
    int next_term = first_term + second_term;
    printf("%d\n", next_term);
    first_term = second_term;
    second_term = next_term;
  }

  printf("\nCongratulations, you just visualized the beauty of the Fibonacci Sequence!\n");

  return 0;
}