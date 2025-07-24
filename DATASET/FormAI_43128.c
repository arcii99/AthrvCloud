//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include<stdio.h>
#include<math.h>

//function declarations
float addition(float x, float y);
float subtraction(float x, float y);
float multiplication(float x, float y);
float division(float x, float y);
float modulus(float x, float y);
int factorial(int x);
float power(float x, float y);
float logarithm(float x);
float sine(float x);
float cosine(float x);
float tangent(float x);
float cotangent(float x);
float cosecant(float x);
float secant(float x);

int main() {
    char operator;
    float num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");

    //user inputs two numbers and the operator
    printf("Enter the two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("Enter an operator (+, -, *, /, %%, !, ^, l, s, c, t, cot, sec, csc): ");
    scanf(" %c",&operator);

    //switch statement to perform the desired operation
    switch(operator) {
        case '+':
            result = addition(num1,num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = subtraction(num1,num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = multiplication(num1,num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero is not possible\n");
                break;
            }
            result = division(num1,num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            break;
        case '%':
            result = modulus(num1,num2);
            printf("%.2f %% %.2f = %.2f\n", num1, num2, result);
            break;
        case '!':
            if(num1 < 0) {
                printf("Error: Factorial of negative numbers is not possible\n");
                break;
            }
            result = factorial(num1);
            printf("%.2f! = %.2f\n", num1, result);
            break;
        case '^':
            if(num1 < 0 && num2 != (int)num2) {
                printf("Error: Power of negative and decimal numbers is not possible\n");
                break;
            }
            result = power(num1,num2);
            printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;
        case 'l':
            if(num1 < 0) {
                printf("Error: Logarithm of negative numbers is not possible\n");
                break;
            }
            result = logarithm(num1);
            printf("log %.2f = %.2f\n", num1, result);
            break;
        case 's':
            result = sine(num1);
            printf("sin %.2f = %.2f\n", num1, result);
            break;
        case 'c':
            result = cosine(num1);
            printf("cos %.2f = %.2f\n", num1, result);
            break;
        case 't':
            result = tangent(num1);
            printf("tan %.2f = %.2f\n", num1, result);
            break;
        case 'cot':
            result = cotangent(num1);
            printf("cot %.2f = %.2f\n", num1, result);
            break;
        case 'sec':
            result = secant(num1);
            printf("sec %.2f = %.2f\n", num1, result);
            break;
        case 'csc':
            result = cosecant(num1);
            printf("csc %.2f = %.2f\n", num1, result);
            break;
        default:
            printf("Error: Invalid operator\n");
    }
    return 0;
}

//function to perform addition operation
float addition(float x, float y) {
    return x + y;
}

//function to perform subtraction operation
float subtraction(float x, float y) {
    return x - y;
}

//function to perform multiplication operation
float multiplication(float x, float y) {
    return x * y;
}

//function to perform division operation
float division(float x, float y) {
    return x / y;
}

//function to perform modulus operation
float modulus(float x, float y) {
    return fmod(x,y);
}

//function to perform factorial operation
int factorial(int x) {
    if(x == 0) {
        return 1;
    }
    else {
        return x * factorial(x-1);
    }
}

//function to perform power operation
float power(float x, float y) {
    return pow(x, y);
}

//function to perform logarithm operation
float logarithm(float x) {
    return log(x);
}

//function to perform sine operation
float sine(float x) {
    return sin(x);
}

//function to perform cosine operation
float cosine(float x) {
    return cos(x);
}

//function to perform tangent operation
float tangent(float x) {
    return tan(x);
}

//function to perform cotangent operation
float cotangent(float x) {
    return (1 / tan(x));
}

//function to perform cosecant operation
float cosecant(float x) {
    return (1 / sin(x));
}

//function to perform secant operation
float secant(float x) {
    return (1 / cos(x));
}