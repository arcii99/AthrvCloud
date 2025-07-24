//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>

int main() {
  int num1, num2, choice;

  printf("Welcome to my calculator\n");
  
  // Loop program indefinitely
  while (1) {
    printf("Please select an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");

    // Get user's choice
    scanf("%d", &choice);

    // Exit if user selects Exit option
    if (choice == 5) {
      printf("Thank you for using my calculator!\n");
      break;
    }

    // Get user's two numbers
    printf("Please enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    // Execute user's chosen operation and display result
    switch (choice) {
      case 1:
        printf("%d + %d = %d\n\n", num1, num2, num1 + num2);
        break;
      case 2:
        printf("%d - %d = %d\n\n", num1, num2, num1 - num2);
        break;
      case 3:
        printf("%d * %d = %d\n\n", num1, num2, num1 * num2);
        break;
      case 4:
        if (num2 == 0) {
          printf("Cannot divide by zero.\n\n");
        } else {
          printf("%d / %d = %d\n\n", num1, num2, num1 / num2);
        }
        break;
      default:
        printf("Invalid choice. Please select again.\n\n");
    }
  }

  return 0;
}