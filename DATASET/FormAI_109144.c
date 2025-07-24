//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include<stdio.h>

int main() {
  // declare an integer variable called 'num'
  int num;
  
  // ask user to enter a positive integer
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  
  // check if the entered number is positive
  if (num < 0) {
    printf("Error: You entered a negative integer. Please enter a positive integer.");
    return 0;
  }
  
  // declare an integer array called 'fibs' of size num
  int fibs[num];
  
  // initialize the first two elements of the array to 0 and 1 respectively
  fibs[0] = 0;
  fibs[1] = 1;
  
  // generate the fibonacci sequence up to the entered number and store it in the array
  for (int i = 2; i < num; i++) {
    fibs[i] = fibs[i-1] + fibs[i-2];
  }
  
  // print out the fibonacci sequence
  printf("The fibonacci sequence up to %d is: ", num);
  for (int i = 0; i < num; i++) {
    printf("%d ", fibs[i]);
  }
  
  return 0;
}