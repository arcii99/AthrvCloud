//FormAI DATASET v1.0 Category: Calculator ; Style: creative
#include <stdio.h>

int main() {
  printf("Welcome to my unique calculator program!\n");
  
  int num1, num2;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  char choice;
  printf("\nWhat would you like to do? \n\nAdd (+)\nSubtract (-)\nMultiply (*)\nDivide (/)\nEnter your choice:");
  scanf(" %c", &choice);
  
  switch(choice) {
    case '+':
      printf("\n%d + %d = %d", num1, num2, num1+num2);
      break;
    case '-':
      printf("\n%d - %d = %d", num1, num2, num1-num2);
      break;
    case '*':
      printf("\n%d * %d = %d", num1, num2, num1*num2);
      break;
    case '/':
      printf("\n%d / %d = %d", num1, num2, num1/num2);
      break;
    default:
      printf("\nInvalid choice.");
      break;
  }
  
  printf("\n\nThank you for using my calculator program!");
  
  return 0;
}