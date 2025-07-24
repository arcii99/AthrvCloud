//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  int n, i, t1 = 0, t2 = 1, nextTerm;
  printf("Please enter the number of terms to display in the Fibonacci sequence (minimum 2): ");
  scanf("%d", &n);
  printf("\n\nUnraveling the mystery of the Fibonacci sequence:\n\n");
  for (i = 1; i <= n; i++) {
    if(i == 1) {
      printf("The game is afoot! The first term in the sequence is %d\n", t1);
      continue;
    }
    if(i == 2) {
      printf("Elementary, my dear Watson! The second term in the sequence is %d\n", t2);
      continue;
    }
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
    printf("Ah, the mystery unfolds! The %d%s term in the sequence is %d\n", i, i==3?"rd":"th", nextTerm);
  }
  printf("\nCase solved! Now you know the first %d terms in the sequence!", n);
  return 0;
}