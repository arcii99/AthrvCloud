//FormAI DATASET v1.0 Category: Arithmetic ; Style: artistic
/* Beautiful Arithmetic Artistic Style */

#include <stdio.h>

int main() {
  int a, b, result;
  
  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);
  
  /* Add */
  result = a + b;
  printf("\n\nBeautiful Addition: %d + %d = %d\n", a, b, result);
  printf("          .\n");
  printf("         / \\\n");
  printf("        /   \\\n");
  printf("       /     \\\n");
  printf("      /_______\\\n");
  
  /* Subtract */
  result = a - b;
  printf("\n\nBeautiful Subtraction: %d - %d = %d\n", a, b, result);
  printf("         _______\n");
  printf("        |       |\n");
  printf("        | %d - %d |\n", a, b);
  printf("        |_______|\n");
  
  /* Multiply */
  result = a * b;
  printf("\n\nBeautiful Multiplication: %d x %d = %d\n", a, b, result);
  printf("          _\n");
  printf("         | |\n");
  printf("%d x %d = | |\n", a, b);
  printf("         |_|\n");
  
  /* Divide */
  result = a / b;
  printf("\n\nBeautiful Division: %d / %d = %d\n", a, b, result);
  if (b == 0) {
    printf("Ooops! Cannot divide by zero.\n");
  } else {
    printf("         _____\n");
    printf("        |     |\n");
    printf("%d / %d = | %d |\n", a, b, result);
    printf("        |_____|\n");
  }
  
  return 0;
}