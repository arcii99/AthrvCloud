//FormAI DATASET v1.0 Category: Arithmetic ; Style: decentralized
//Decentralized arithmetic example program

#include <stdio.h>

//function declarations
void fibonacci(int n);
int add(int a, int b);
int multiply(int a, int b);
int power(int x, unsigned int y);
float divide(float a, float b);

int main() {

    int num1 = 10, num2 = 3, sum, product, power_result;
    float quotient;

    //calculating sum of two numbers
    sum = add(num1, num2);
    printf("Sum of %d and %d is %d\n", num1, num2, sum);

    //calculating product of two numbers
    product = multiply(num1, num2);
    printf("Product of %d and %d is %d\n", num1, num2, product);

    //calculating power of a number
    power_result = power(num1, num2);
    printf("%d raised to power %d is %d\n", num1, num2, power_result);

    //calculating division of two numbers
    quotient = divide(num1, num2);
    printf("%d divided by %d is %.2f\n", num1, num2, quotient);

    //printing fibonacci series
    printf("Fibonacci Series of first 10 numbers:\n");
    fibonacci(10);

    return 0;
}

/*
 * Function to add two numbers
 */
int add(int a, int b) {
    return a + b;
}

/*
 * Function to multiply two numbers
 */
int multiply(int a, int b) {
    return a * b;
}

/*
 * Function to calculate power of a number
 */
int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

/*
 * Function to divide two numbers
 */
float divide(float a, float b) {
    return a / b;
}

/*
 * Function to print fibonacci series
 */
void fibonacci(int n) {
    int n1 = 0, n2 = 1, next_number, i;
    for (i = 0; i < n; i++) {
        printf("%d ", n1);
        next_number = n1 + n2;
        n1 = n2;
        n2 = next_number;
    }
}