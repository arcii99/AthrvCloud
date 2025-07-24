//FormAI DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to Happy Calculator v1.0!\n");
  printf("Let's perform some arithmetic with a smile :)\n");
  
  int num1, num2;
  
  printf("Please enter the first number:\n");
  scanf("%d", &num1);

  printf("Fantastic, now enter the second number:\n");
  scanf("%d", &num2);
  
  printf("Awesome, our happy calculator is ready to do some work!\n\n");
  printf("The sum of %d and %d is %d :) \n", num1, num2, num1+num2);
  printf("The difference of %d and %d is %d :) \n", num1, num2, num1-num2);
  printf("The product of %d and %d is %d :) \n", num1, num2, num1*num2);
  
  if (num2 != 0) {
    printf("The quotient of %d divided by %d is %d :) \n", num1, num2, num1/num2);
    printf("The remainder of %d divided by %d is %d :) \n", num1, num2, num1%num2);
  } else {
    printf("Oops, we cannot perform division if the second number is 0 :(\n");
  }
  
  printf("Thank you for using Happy Calculator v1.0! We hope you are smiling :D\n");
  return 0;
}