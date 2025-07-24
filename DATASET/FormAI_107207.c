//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

void fibonacci_sequence(int n) {
  int a = 0, b = 1, c;
  
  for(int i = 0; i < n; i++) {
    if(i == 0){
      printf("%d%s", a, " ");
    }
    else if(i == 1){
      printf("%d%s", b, " ");
    }
    else{
      c = a + b;
      a = b;
      b = c;
      
      printf("%d%s", c, " ");
    }
  }
}

int main() {
  int n;
  
  printf("%s", "Let's visualize the Fibonacci Sequence...\n");
  printf("%s", "Enter a positive integer to generate the sequence: ");
  
  scanf("%d", &n);
  
  printf("%s%d%s", "The first ", n, " numbers of the Fibonacci Sequence are:\n");
  fibonacci_sequence(n);
  
  printf("%s", "\nThank you for using our program!\n");
  
  return 0;
}