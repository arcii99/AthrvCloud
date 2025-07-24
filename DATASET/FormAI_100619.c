//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>

int main(){
    printf("Welcome to the Brave Scientific Example Program!\n");

    int x = 10;
    int y = 5;

    printf("Our numbers to operate with: %d and %d\n", x, y);

    //Addition
    int result = x + y;
    printf("Addition: %d + %d = %d\n", x, y, result);

    //Subtraction
    result = x - y;
    printf("Subtraction: %d - %d = %d\n", x, y, result);

    //Multiplication
    result = x * y;
    printf("Multiplication: %d * %d = %d\n", x, y, result);

    //Division
    result = x / y;
    printf("Division (integer division): %d / %d = %d\n", x, y, result);

    float floatResult = (float)x / (float)y;
    printf("Division (float division): %.2f / %.2f = %.2f\n", (float)x, (float)y, floatResult);

    //Modulo
    result = x % y;
    printf("Modulo: %d %% %d = %d\n", x, y, result);

    //Increment
    x++;
    printf("Increment: x++ = %d\n", x);

    //Decrement
    y--;
    printf("Decrement: y-- = %d\n", y);

    //Logical Operators
    printf("Logical Operators:\n");

    int a = 7;
    int b = 5;

    //AND Operator
    if(a > b && b < 10)
        printf("%d is greater than %d AND %d is less than 10\n", a, b, b);

    //OR Operator
    if(a < b || b < 10)
        printf("%d is less than %d OR %d is less than 10\n", a, b, b);

    //NOT Operator
    if(!(a==b))
        printf("%d is NOT equal to %d\n", a, b);

    //Bitwise Operators
    int num1 = 10;
    int num2 = 7;

    int res;

    //Bitwise AND
    res = num1 & num2;
    printf("\nBitwise Operators:\n");
    printf("Bitwise AND: %d & %d = %d\n", num1, num2, res);

    //Bitwise OR
    res = num1 | num2;
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, res);

    //Bitwise XOR
    res = num1 ^ num2;
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, res);

    //Bitwise LEFT SHIFT
    res = num1 << 2;
    printf("Bitwise LEFT SHIFT: %d << 2 = %d\n", num1, res);

    //Bitwise RIGHT SHIFT
    res = num1 >> 2;
    printf("Bitwise RIGHT SHIFT: %d >> 2 = %d\n", num1, res);

    printf("\nThank you for using the Brave Scientific Example Program!\n");

    return 0;
}