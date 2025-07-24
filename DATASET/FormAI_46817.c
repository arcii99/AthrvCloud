//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include<stdio.h>
#include<math.h>

double calculator(char operation, double num1, double num2) {
    if(operation == '+') {
        return(num1 + num2);
    }
    else if(operation == '-') {
        return(num1 - num2);
    }
    else if(operation == '*') {
        return(num1 * num2);
    }
    else if(operation == '/') {
        if(num2 == 0) {
            printf("Error! Dividing by zero is not allowed.\n");
            return 0;
        }
        else {
            return(num1 / num2);
        }
    }
    else if(operation == '^') {
        return(pow(num1, num2));
    }
}

int main() {
    char operation;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operation);

    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    result = calculator(operation, num1, num2);
    printf("%.2lf %c %.2lf = %.2lf\n", num1, operation, num2, result);
    return 0;
}