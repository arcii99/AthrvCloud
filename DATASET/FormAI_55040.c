//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_table[10][10];

  // initialize table with random numbers
  srand(time(0));
  for(int i=0; i<10; i++) {
    for(int j=0; j<10; j++) {
      num_table[i][j] = rand() % 100;
    }
  }

  // Print the table and the sum of each row and column
  printf("   ");
  for(int i=0; i<10; i++) {
    printf("%2d ", i+1);
  }
  printf("RowSum\n");

  for(int i=0; i<10; i++) {
    printf("%2d ", i+1);
    int row_sum = 0;
    for(int j=0; j<10; j++) {
      row_sum += num_table[i][j];
      printf("%2d ", num_table[i][j]);
    }
    printf("%4d\n", row_sum);
  }

  printf("ColSum ");
  int total_sum = 0;
  for(int j=0; j<10; j++) {
    int col_sum = 0;
    for(int i=0; i<10; i++) {
      col_sum += num_table[i][j];
    }
    total_sum += col_sum;
    printf("%2d ", col_sum);
  }
  printf("%4d\n", total_sum);

  return 0;
}