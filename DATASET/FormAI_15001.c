//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
  // Declare variables
  int firstNumber, secondNumber, result;
  
  // Prompt user for input
  printf("Please enter the first number: ");
  scanf("%d", &firstNumber);
  
  printf("Please enter the second number: ");
  scanf("%d", &secondNumber);
  
  // Add the numbers together
  result = firstNumber + secondNumber;
  
  // Display the result in a peaceful message
  printf("The sum of %d and %d is %d, which brings peace to my heart.\n", firstNumber, secondNumber, result);
  
  // Subtract the second number from the first
  result = firstNumber - secondNumber;
  
  // Display the result in a peaceful message
  printf("When %d is subtracted from %d, the result brings peace to my soul. The answer is %d.\n", secondNumber, firstNumber, result);
  
  // Multiply the numbers together
  result = firstNumber * secondNumber;
  
  // Display the result in a peaceful message
  printf("The product of %d and %d is %d, a peaceful thought.\n", firstNumber, secondNumber, result);
  
  // Divide the first number by the second
  float floatResult = (float) firstNumber / secondNumber;
  
  // Display the result in a peaceful message
  printf("If we divide %d by %d, we obtain a peaceful result of %.2f.\n", firstNumber, secondNumber, floatResult);

  return 0;
}