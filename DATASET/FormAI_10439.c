//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int num1 = rand() % 100;
    int num2 = rand() % 100;

    printf("Welcome, surreal operator! Your mission, if you choose to accept it, is to perform some bitwise operations using two randomly generated integers.\n");

    printf("The first number is %d, and the second number is %d.\n", num1, num2);

    printf("For starters, let's perform a bitwise AND:\n");

    int bitwise_and = num1 & num2;
    printf("%d & %d = %d\n", num1, num2, bitwise_and);

    printf("Now, let's perform a bitwise OR:\n");

    int bitwise_or = num1 | num2;
    printf("%d | %d = %d\n", num1, num2, bitwise_or);

    printf("Next up, let's perform a bitwise XOR:\n");

    int bitwise_xor = num1 ^ num2;
    printf("%d ^ %d = %d\n", num1, num2, bitwise_xor);

    printf("Finally, let's perform a bitwise NOT on the first number:\n");

    int bitwise_not = ~num1;
    printf("~%d = %d\n", num1, bitwise_not);

    printf("Congratulations, surreal operator! You have completed your mission.\n");

    return 0;
}