//FormAI DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>

int main() {
  printf("Let's make the perfect cup of C programming knowledge, shall we?!\n");
  printf("First, let's define some variables:\n");

  int x = 4; // the x variable will represent the number of hours that the cup of knowledge needs to steep  
  int y = 8; // the y variable will represent the number of hours you have to devote to studying C programming

  printf("We need to steep the cup of knowledge for %d hours.\n", x);
  printf("You have %d hours to devote to studying C programming.\n", y);
  
  if (y >= x) {
    printf("Great! You have enough time to steep the cup of knowledge and become a C programming master!\n");
  } else {
    printf("Uh-oh, you don't have enough time to steep the cup of knowledge. You need to devote more time to studying C programming!\n");
  }
  
  printf("But wait, there's more! Let's calculate the factorial of 5 using a recursive function:\n");

  int result = factorial(5); // the result variable will hold the value of the factorial of 5
  
  printf("The factorial of 5 is %d!\n", result);
  
  return 0;
}

int factorial(int num) {
  if (num == 1) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}