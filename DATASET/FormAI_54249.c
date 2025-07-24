//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
  int num1, num2, sum, sub, div, mul; //Declare variables

  printf("Hey there, let's get started with some Arithmetic calculations!\n");

  //Ask for user input 
  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  //Perform Arithmetic Operations
  sum = num1 + num2;
  sub = num1 - num2;
  div = num1 / num2;
  mul = num1 * num2;

  printf("\nCalculations complete! Results are as follows:\n\n");

  //Display results
  printf("%d + %d = %d\n", num1, num2, sum);
  printf("%d - %d = %d\n", num1, num2, sub);
  printf("%d / %d = %d\n", num1, num2, div);
  printf("%d * %d = %d\n", num1, num2, mul);

  printf("\nThat was fun! Wanna try again?"); //Energetic ending

  return 0;
}