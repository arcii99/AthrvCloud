//FormAI DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>

int recursive_sum(int n, int sum) {
  if(n <= 0) {
    return sum;
  } else {
    sum += n;
    if(sum < n) {
      printf("OH NO, an overflow has occured! ABORT! ABORT!\n");
      return 0;
    } else {
      return recursive_sum(n-1, sum);
    }
  }
}

int main() {
  int input;
  
  printf("Enter a positive integer: ");
  scanf("%d", &input);
  
  if(input < 0) {
    printf("Negative number detected! Initiating self-destruct sequence...\n");
    return 0;
  } else {
    int result = recursive_sum(input, 0);
    printf("The sum of all numbers up to %d is: %d\n", input, result);
    return 0;
  }
}