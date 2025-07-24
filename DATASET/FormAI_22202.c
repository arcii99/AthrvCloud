//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>

int main() {
  int array[5][5] = {{7, 2, 3, 4, 1},
                     {2, 5, 7, 8, 6},
                     {9, 8, 2, 3, 2},
                     {1, 2, 3, 4, 5},
                     {4, 9, 6, 1, 3}};
  int sum = 0, count = 0;

  // Get the sum of diagonals
  for (int i = 0; i < 5; i++) {
    sum += array[i][i];
    sum += array[i][4 - i];
  }

  // Get the count of odd numbers
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (array[i][j] % 2 == 1) {
        count++;
      }
    }
  }

  // Print the results
  printf("Sum of all diagonals: %d\n", sum);
  printf("Count of odd numbers: %d\n", count);

  return 0;
}