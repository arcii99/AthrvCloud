//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {
  int num1, num2;
  char operand;
  
  printf("Welcome to the Arithmetic Program!\n");
  
  while(1) {
    printf("Enter an expression (e.g. 5 + 3): ");
    scanf("%d %c %d", &num1, &operand, &num2);
    
    switch(operand) {
      case '+':
        printf("Result: %d\n", num1 + num2);
        break;
      case '-':
        printf("Result: %d\n", num1 - num2);
        break;
      case '*':
        printf("Result: %d\n", num1 * num2);
        break;
      case '/':
        if(num2 == 0) {
          printf("Error: Division by zero\n");
        } else {
          printf("Result: %d\n", num1 / num2);
        }
        break;
      default:
        printf("Error: Invalid operator\n");
        break;
    }
    
    int choice;
    printf("Do you want to perform another operation? (1 = yes, 0 = no): ");
    scanf("%d", &choice);
    if(choice == 0) {
      printf("Goodbye!\n");
      break;
    }
  }
  
  return 0;
}