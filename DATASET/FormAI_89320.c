//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include<stdio.h>

// Get ready to be amazed with the magic of recursion!
// Here is my unique recursive example program that will blow your mind!

void recursiveFunction(int n) {
  // Let's add some excitement by adding a print statement!
  printf("Woo! Recursion time! \n");

  // Base case: if n is 1, we simply return. Easy enough, right?
  if(n == 1) {
    printf("Base case reached! \n");
    return;
  }

  // But, if n is greater than 1, we'll go deeper into recursion!
  printf("Recursive function call with n as %d \n", n-1);
  recursiveFunction(n-1);

  // And just when you thought you've reached the end, we'll start coming back up!
  printf("Returned from recursive call with n as %d \n", n-1);
  printf("Let's go deeper again! \n");
  recursiveFunction(n-1);

  // Once recursion is complete, we'll have one last message for our user!
  printf("We are done here. Thanks for the ride! \n");
}

int main() {
  // And now, let the recursion begin!
  printf("Let's start some recursion! \n");
  recursiveFunction(3);
  
  return 0;
}