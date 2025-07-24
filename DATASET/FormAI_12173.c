//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include<stdio.h>

int main() {
  int n, i, j, count=0;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  for(i=2; i<=n; i++) {
    int prime = 1;
    for(j=2; j<=i/2; j++) {
      if(i%j == 0) {
        prime = 0;
        break;
      }
    }
    if(prime) {
      count++;
      printf("%d is a prime number\n", i);
    }
  }
  printf("There are %d prime numbers between 2 and %d\n", count, n);
  return 0;
}