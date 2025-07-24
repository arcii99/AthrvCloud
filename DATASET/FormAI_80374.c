//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <math.h>

int main() {

    // declare variables
    float num1, num2, result;
    char operator;

    // prompt user for input
    printf("Enter an expression: ");
    scanf("%f %c %f", &num1, &operator, &num2);

    // perform calculation based on operator
    switch(operator) {
        case '+': result = num1 + num2;
                  break;
        case '-': result = num1 - num2;
                  break;
        case '*': result = num1 * num2;
                  break;
        case '/': result = num1 / num2;
                  break;
        case '^': result = pow(num1, num2);
                  break;
        case '%': result = fmod(num1, num2);
                  break;
        default:  printf("Invalid operator");
                  return 0;
    }

    // print result
    printf("Result: %.2f", result);

    return 0;
}