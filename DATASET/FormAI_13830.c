//FormAI DATASET v1.0 Category: Scientific ; Style: synchronous
#include <stdio.h>

void printDivisors(int n) {
  int i;
  for (i = 1; i <= n; i++) {
 
    if (n % i == 0) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

int main() {

  int n;
 
  printf("Enter an integer: ");
  scanf("%d", &n);
 
  printf("The divisors of %d are: ", n);
  printDivisors(n);
  
  return 0;
}