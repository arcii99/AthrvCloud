//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

int recursive_func(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * recursive_func(n-1);
}

int main() {
  int num;
  printf("Please enter a number: ");
  scanf("%d", &num);
  
  if (num < 0) {
    printf("Error: please enter a non-negative number!");
    return 0;
  }
  
  int result = recursive_func(num);
  printf("The factorial of %d is %d", num, result);
  
  return 0;
}