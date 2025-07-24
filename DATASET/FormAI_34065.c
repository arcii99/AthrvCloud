//FormAI DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator
  
  int table[10][10]; // initialize table
  int sum = 0; // initialize sum
  
  // fill table with random numbers between 1 and 10
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      table[i][j] = rand() % 10 + 1;
    }
  }
  
  // display table and calculate sum of numbers in row 5
  printf("  1 2 3 4 5 6 7 8 9 10\n"); // table header
  for(int i = 0; i < 10; i++) {
    printf("%d ", i+1); // table row number
    for(int j = 0; j < 10; j++) {
      printf("%d ", table[i][j]); // print number
      if(i == 4) {
        sum += table[i][j]; // add number to sum if in row 5
      }
    }
    printf("\n"); // move to next row
  }
  
  printf("The sum of the numbers in row 5 is: %d\n", sum); // display sum
  
  return 0;
}