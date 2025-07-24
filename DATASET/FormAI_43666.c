//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables for user inputs and results
  double num1, num2, result;
  char op, answer;

  // Greet user with surreal message
  printf("Greetings, user. I am a scientific calculator with the power to manipulate reality itself. What math shall we explore today?\n");

  // Start loop to keep program running until user decides to quit
  do {
    // Prompt user for operation and inputs
    printf("\nPlease enter an operation (+ - * / ^ sqrt): ");
    scanf(" %c", &op);
  
    printf("Please enter your first number: ");
    scanf("%lf", &num1);
  
    // Use switch statement to perform selected operation
    switch(op) {
      case '+':
        printf("Please enter your second number: ");
        scanf("%lf", &num2);
        result = num1 + num2;
        printf("The sum of %lf and %lf is %lf.\n", num1, num2, result);
        break;

      case '-':
        printf("Please enter your second number: ");
        scanf("%lf", &num2);
        result = num1 - num2;
        printf("The difference of %lf and %lf is %lf.\n", num1, num2, result);
        break;

      case '*':
        printf("Please enter your second number: ");
        scanf("%lf", &num2);
        result = num1 * num2;
        printf("The product of %lf and %lf is %lf.\n", num1, num2, result);
        break;

      case '/':
        printf("Please enter your second number: ");
        scanf("%lf", &num2);

        // Check if user is trying to divide by zero
        if (num2 == 0) {
          printf("You cannot divide by zero! Reality is breaking down...\n");
          printf("...\n");
          printf("...\n");
          printf("... Phew! Reality has stabilized.\n");
        } else {
          result = num1 / num2;
          printf("The quotient of %lf and %lf is %lf.\n", num1, num2, result);
        }

        break;

      case '^':
        printf("Please enter the power you wish to raise %lf to: ", num1);
        scanf("%lf", &num2);
        result = pow(num1, num2);
        printf("%lf raised to the %lf power is %lf.\n", num1, num2, result);
        break;

      case 's':
        result = sqrt(num1);
        printf("The square root of %lf is %lf.\n", num1, result);
        break;

      default:
        printf("I'm sorry, I cannot perform that operation. Reality is shifting...\n");
        printf("...\n");
        printf("... Oh, we're back. Let's try again.\n");
        break;
    }

    // Ask user if they want to try another operation
    printf("\nWould you like to perform another operation? (Y/N): ");
    scanf(" %c", &answer);

  } while(answer == 'Y' || answer == 'y');

  // Bid farewell to user
  printf("\nThank you for exploring the surreal realm of mathematics with me. Until next time!\n");

  return 0;
}