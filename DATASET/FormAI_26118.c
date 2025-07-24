//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Alan Touring
#include <stdio.h>

int main() {
  int a = 0, b = 1, c, num;
  
  printf("How many numbers in the Fibonacci sequence do you want to visualize? ");
  scanf("%d", &num);
  
  printf("%d, %d, ", a, b); // printing the first two numbers
  
  for (int i = 2; i < num; i++) { // calculating and printing the rest of the sequence
    c = a + b;
    printf("%d, ", c);
    a = b;
    b = c;
  }
  
  printf("\n");
  
  return 0;
}