//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void example() {
  printf("Welcome to the Error Handling Example!\n");
  char input[100];
  int num1, num2, result;
  printf("Enter two numbers separated by a space: ");
  fgets(input, sizeof(input), stdin);

  if (sscanf(input, "%d %d", &num1, &num2) != 2) {
    printf("Error: Invalid input! Please enter two numbers separated by a space.\n");
    return;
  }

  if (num2 == 0) {
    printf("Error: Division by zero is not allowed.\n");
    return;
  }

  result = num1 / num2;

  printf("%d divided by %d is %d.\n", num1, num2, result);
}

int main() {
  char choice;
  do {
    example();
    printf("Would you like to perform another calculation? (y/n): ");
    scanf(" %c", &choice);
    getchar();
  } while (tolower(choice) == 'y');

  if (tolower(choice) == 'n') {
    printf("Thank you for using the Error Handling Example!\n");
    return 0;
  } else {
    printf("Error: Invalid input!\n");
    return 1;
  }
}