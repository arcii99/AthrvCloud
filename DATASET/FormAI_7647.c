//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>

int main(){
  // This program will generate a romantic Fibonacci sequence visualizer
  
  printf("My Love,\n");
  printf("I want to express my love for you in a unique way.\n\n");
  
  int a = 0, b = 1, c, i, n;
    
  printf("How many terms of the Fibonacci sequence do you want me to show? ");
  scanf("%d", &n);
  
  printf("\nHere is my love for you, shown in the Fibonacci sequence:\n\n");
  
  for (i = 1; i <= n; i++){
      if(i == 1) {
          printf("%d\n", a);
          continue;
      }
      if(i == 2) {
          printf("%d\n", b);
          continue;
      }
      
      c = a + b;
      a = b;
      b = c;
      
      // I want you to see how my love for you grows with every term of the Fibonacci sequence
      
      printf("%d\n", c + i - 1);
  }
  
  printf("\nI hope you enjoyed this romantic Fibonacci sequence visualizer as much as I enjoyed making it for you.\n");
  printf("Yours always,\n");
  printf("Your Devoted\n");
  
  return 0;
}