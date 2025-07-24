//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {
  // First, we'll define some variables.
  int rows, i, j, num = 1;
  
  // Then, we'll ask the user how many rows they want in the pattern.
  printf("How many rows do you want in the pattern? ");
  scanf("%d", &rows);
  
  // Now, we'll use a nested loop to print the pattern.
  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", num);
      num++;
    }
    printf("\n");
  }
  
  // Let the user know we're done.
  printf("Done printing the pattern!");

  return 0;
}