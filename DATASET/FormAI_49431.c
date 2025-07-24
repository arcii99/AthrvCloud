//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int a, int b)
{
    int result = a + b;
    printf("Result of %d + %d is %d\n", a, b, result);
}

void subtract(int a, int b)
{
    int result = a - b;
    printf("Result of %d - %d is %d\n", a, b, result);
}

void multiply(int a, int b)
{
    int result = a * b;
    printf("Result of %d * %d is %d\n", a, b, result);
}

void divide(int a, int b)
{
    int result = a / b;
    printf("Result of %d / %d is %d\n", a, b, result);
}

void asynchronous_arithmetic()
{
    int a, b;
    srand(time(NULL));  // Seed the random number generator

    for(int i = 0; i < 10; i++)
    {
        a = rand() % 100;  // Generate random number between 0 and 99
        b = rand() % 15 + 1;  // Generate random number between 1 and 15

        // Generate random arithmetic operation
        int operation = rand() % 4;
        switch(operation)
        {
            case 0:
                printf("Operation %d: ", i+1);
                add(a, b);
                break;
            case 1:
                printf("Operation %d: ", i+1);
                subtract(a, b);
                break;
            case 2:
                printf("Operation %d: ", i+1);
                multiply(a, b);
                break;
            case 3:
                printf("Operation %d: ", i+1);
                divide(a, b);
                break;
        }
    }
}

int main()
{
    asynchronous_arithmetic();

    return 0;
}