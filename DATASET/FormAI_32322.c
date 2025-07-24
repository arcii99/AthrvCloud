//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include<stdio.h>

int recursive_random(int n) {
  if (n == 0) {
    return 0;
  } else {
    int rand_num = rand() % 10;
    printf("%d ", rand_num);
    return rand_num + recursive_random(n - 1);
  }
}

int main() {
  int n;
  printf("Enter the number of random numbers needed: ");
  scanf("%d", &n);

  if (n < 1) {
    printf("Invalid input! Exiting...\n");
    return 0;
  }

  printf("Here are %d random numbers: ", n);
  int sum = recursive_random(n);

  printf("\n\nThe sum of these random numbers is: %d\n", sum);
  return 0;
}