//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

int recursiveFunction(int n);
/* This function takes an integer parameter n, and returns an integer.*/

int main(){
  int n = 5, result;

  result = recursiveFunction(n);

  printf("The factorial of %d is %d.", n, result);
  return 0;
}

int recursiveFunction(int n){
  if(n == 0){
    return 1;
  }
  else{
    return n * recursiveFunction(n-1);
  }
}