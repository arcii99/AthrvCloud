//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int num;
  printf("Welcome to the Happy Number Program!\n");
  printf("\nPlease enter a positive integer: ");
  scanf("%d", &num);

  // Create a loop to check if the number is happy
  while (num != 1 && num != 4) {
    int temp = 0;
    while (num > 0) {
      int digit = num % 10;
      temp += digit * digit;
      num /= 10;
    }
    num = temp;
  }

  // Check if number is happy or not
  if (num == 1) {
    printf("\nHooray! Your number is a happy number!");
  } else {
    printf("\nSorry, your number is not a happy number!");
  }
  
  // Print out what a happy number is
  printf("\n\nA happy number is a number that, when you square its digits and add them together multiple times, you eventually reach the number 1.");
  return 0;
}