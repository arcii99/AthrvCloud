//FormAI DATASET v1.0 Category: Random ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, num, lower, upper;
  srand(time(0)); // use time as seed to generate more random numbers

  printf("Enter the number of random numbers to generate: ");
  scanf("%d", &num);

  printf("Enter the lower bound of the range: ");
  scanf("%d", &lower);

  printf("Enter the upper bound of the range: ");
  scanf("%d", &upper);

  int arr[num];
  for(i = 0; i < num; i++) {
    arr[i] = (rand() % (upper - lower + 1)) + lower; // generate random numbers within the specified range
  }

  printf("The generated random numbers are: \n");
  for(i = 0; i < num; i++) {
    printf("%d\n", arr[i]); // print the generated numbers to the console
  }

  return 0;
}