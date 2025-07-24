//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    
    // Swapping using + and -
    a = a + b; // a = 30
    b = a - b; // b = 10
    a = a - b; // a = 20
    printf("a = %d, b = %d\n", a, b);
    
    //Incrementing using bitwise operators
    a = a ^ b; // a = 30 ^ 10 = 20
    b = a ^ b; // b = 20 ^ 10 = 30
    a = a ^ b; // a = 20 ^ 30 = 10
    printf("a = %d, b = %d\n", a, b);
    
    //Finding maximum of two numbers
    int c = 50, d = 100;
    int max = c > d ? c : d;
    printf("The maximum of %d and %d is %d\n", c, d, max);
    
    //Finding minimum of two numbers
    int x = 5, y = 10;
    int min = x < y ? x : y;
    printf("The minimum of %d and %d is %d\n", x, y, min);
    
    //Checking if a number is even or odd
    int num = 7;
    if(num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
    
    //Calculating area of circle
    float radius = 5.5;
    float area = 3.14159 * radius * radius;
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);
    
    //Calculating factorial of a number
    int n = 5;
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("The factorial of %d is %d\n", n, fact);
    
    //Checking if a number is prime or not
    int num2 = 13;
    int flag = 0;
    for(int i = 2; i <= num2 / 2; i++) {
        if(num2 % i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("%d is a prime number.\n", num2);
    } else {
        printf("%d is not a prime number.\n", num2);
    }
    
    return 0;
}