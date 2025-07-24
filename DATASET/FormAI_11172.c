//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>

int main() {
  int n, i;
  long int a = 0, b = 1, next = 0;
  
  printf("Enter the number of terms in Fibonacci sequence you would like to see: ");
  scanf("%d", &n);
  
  printf("Fibonacci sequence:\n");
  
  for (i = 1; i <= n; ++i) {
    printf("%ld\n", a);
    
    if (a > 0 && b > 0 && next < 0) {
      printf("Error: Overflow has occurred.\n");
      break;
    }
    
    next = a + b;
    a = b;
    b = next;
  }
  
  return 0;
}