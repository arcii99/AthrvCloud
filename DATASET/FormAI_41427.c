//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

int mathExercise(int n){
  if(n == 1) return 1; // base case
  
  return n + mathExercise(n-1); // recursive case
}

int main(){
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  
  int result = mathExercise(num);
  printf("The sum of numbers from 1 to %d is: %d", num, result);
  
  return 0;
}