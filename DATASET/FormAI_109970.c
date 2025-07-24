//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

int main() {

  int n, i, t1 = 0, t2 = 1, nextTerm;
  
  printf("Enter the number of terms: ");
  scanf("%d", &n); // getting the number of terms to be printed

  printf("Fibonacci Series: "); // Printing the fibonacci series

  for (i = 1; i <= n; ++i) {
  
    printf("%d, ", t1); // printing the first term
    
    nextTerm = t1 + t2;
    
    t1 = t2;
    
    t2 = nextTerm;
  }
  
  return 0;
}