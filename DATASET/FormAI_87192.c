//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
/* Romeo and Juliet Recursive Program */

#include <stdio.h>
#include <stdlib.h>

// Declare the recursive function
int love(int a, int b);

// Declare the main function
int main() 
{
  int x, y, result;
  
  printf("Enter two numbers to test the strength of your love\n");
  scanf("%d %d", &x, &y);
  
  result = love(x, y);
  
  if (result == 1) {
    printf("\nYour love is strong and will conquer all obstacles.\n");
  }
  else {
    printf("\nYour love is not strong enough, try again...\n");
  }
  
  return 0;
}

// Define the recursive function
int love(int a, int b) 
{
  if (a == 0 || b == 0) {
    return a + b;
  }
  
  if (a == b) {
    return a;
  }
  
  if (a > b) {
    return love(a-b, b);
  }
  
  return love(a, b-a);
}