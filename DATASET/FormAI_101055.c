//FormAI DATASET v1.0 Category: Funny ; Style: lively
#include <stdio.h>

int main() {
  int num1 = 1, num2 = 1;
  printf("Let's play a game!\n");
  printf("Enter a number: ");
  scanf("%d", &num1);
  printf("Enter another number: ");
  scanf("%d", &num2);
  
  printf("You entered %d and %d\n", num1, num2);
  printf("Now, let's see who is bigger...\n");
  
  if (num1 > num2) {
    printf("I think %d is bigger!\n", num1);
    printf("But wait, let's switch them around...\n");
    int temp = num1;
    num1 = num2;
    num2 = temp;
    printf("Now, %d is bigger!\n", num2);
  }
  else if (num2 > num1) {
    printf("I think %d is bigger!\n", num2);
    printf("But wait, let's switch them around...\n");
    int temp = num1;
    num1 = num2;
    num2 = temp;
    printf("Now, %d is bigger!\n", num2);
  }
  else {
    printf("They're both the same number!\n");
  }
  
  printf("Now, let's do some math...\n");
  int sum = num1 + num2;
  int product = num1 * num2;
  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  printf("The product of %d and %d is %d\n", num1, num2, product);
  
  printf("Thanks for playing!\n");
  return 0;
}