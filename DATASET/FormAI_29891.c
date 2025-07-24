//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include<stdio.h>

int recursive(int n) {
  if(n<=1) {
    return n;
  }
  else {
    return recursive(n-1) + recursive(n-2);
  }
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  while(n<=0) {
    printf("Invalid input! Enter a positive integer: ");
    scanf("%d", &n);
  }
  printf("%dth Fibonacci number is: %d\n", n, recursive(n));
  return 0;
}