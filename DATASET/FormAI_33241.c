//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {

int num1, num2, result;

printf("Enter first number: ");
if(scanf("%d", &num1) != 1) { // If input isn't an integer
    printf("Invalid input. Please enter an integer.");
    return 0;
}

printf("Enter second number: ");
if(scanf("%d", &num2) != 1) { // If input isn't an integer
    printf("Invalid input. Please enter an integer.");
    return 0;
}

if(num2 == 0) { // Division by zero error
    printf("Error: Cannot divide by zero.");
    return 0;
}

result = num1 / num2;

printf("%d divided by %d is equal to %d", num1, num2, result);

return 0;

}