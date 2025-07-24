//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>

int main() {
  int num1, num2, num3; //declare three integers
  
  printf("Enter three numbers: ");
  scanf("%d %d %d", &num1, &num2, &num3); //take input from user
  
  if(num1>=num2 && num1>=num3)
      printf("%d is the largest number.", num1); //check if the first number is largest
  else if(num2>=num1 && num2>=num3)
      printf("%d is the largest number.", num2); //check if the second number is largest
  else
      printf("%d is the largest number.", num3); //if neither of the above conditions are met, third number is largest

  return 0; //exit the program
}