//FormAI DATASET v1.0 Category: Scientific ; Style: curious
#include<stdio.h>

int main(){
  int num1, num2, result;
  
  printf("Welcome to the Curious Calculator! Please enter two numbers: \n");
  scanf("%d %d", &num1, &num2);
  
  printf("The first number you entered was %d and the second number was %d. \n", num1, num2);
  
  printf("I wonder what will happen if we add them together... \n");
  result = num1 + num2;
  printf("The result of adding %d and %d is %d. \n", num1, num2, result);
  
  printf("Hmm...what about if we multiply them? That could be interesting... \n");
  result = num1 * num2;
  printf("The result of multiplying %d and %d is %d. \n", num1, num2, result);

  printf("But wait! What if we raise the first number to the power of the second number? \n");
  result = pow(num1, num2);
  printf("The result of raising %d to the power of %d is %d. \n", num1, num2, result);

  printf("Let's try something even more curious...what if we divide the second number by the first number? \n");
  result = num2 / num1;
  printf("The result of dividing %d by %d is %d. \n", num2, num1, result);

  printf("I'm starting to think that these numbers are pretty special. Let's do one more calculation... \n");
  result = (num1 * num2) / (num2 - num1);
  printf("The result of calculating (%d * %d) / (%d - %d) is %d. \n", num1, num2, num2, num1, result);

  printf("Wow, that was a lot of math! Thanks for exploring the world of curious calculations with me. \n");
  
  return 0;
}