//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  char operation;
  int a, b, result;
  
  printf("Welcome to the Medieval Scientific Calculator!\n");
  printf("Please choose an operation: +, -, *, /, or ^: ");
  scanf("%c", &operation);
  
  printf("Enter the first number: ");
  scanf("%d", &a);
  
  printf("Enter the second number: ");
  scanf("%d", &b);
  
  switch(operation)
  {
    case '+':
        result = a + b;
        printf("The sum of %d and %d is %d\n", a, b, result);
        break;
    
    case '-':
        result = a - b;
        printf("%d subtract %d gives %d\n", a, b, result);
        break;
        
    case '*':
        result = a * b;
        printf("%d multiplied with %d equals %d\n", a, b, result);
        break;
        
    case '/':
        if(b == 0)
        {
          printf("Error: Division by 0 is not allowed.\n");
          exit(0);
        }
        result = a / b;
        printf("%d divided by %d gives %d\n", a, b, result);
        break;
        
    case '^':
        result = pow(a, b);
        printf("%d raised to %d is %d\n", a, b, result);
        break;
        
    default:
        printf("Invalid operation chosen. Please try again.\n");
        exit(0);
  }
  
  printf("Thank you for using our Medieval Scientific Calculator!\n");
  
  return 0;
}