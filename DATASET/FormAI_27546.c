//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include<stdio.h>

//Defining Bitwise Operations
#define BITWISE_AND &
#define BITWISE_OR |
#define BITWISE_XOR ^
#define BITWISE_NOT ~
#define BITWISE_LEFT_SHIFT <<
#define BITWISE_RIGHT_SHIFT >>

int main(){

    //Declare two integers
    int num1, num2;

    //Take input from the user
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);

    //Display the Bitwise AND operation
    printf("\nBitwise AND: %d & %d = %d\n", num1, num2, num1 BITWISE_AND num2);

    //Display the Bitwise OR operation
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, num1 BITWISE_OR num2);

    //Display the Bitwise XOR operation
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, num1 BITWISE_XOR num2);

    //Display the Bitwise NOT operation
    printf("Bitwise NOT of first number: ~%d = %d\n", num1, BITWISE_NOT num1);
    printf("Bitwise NOT of second number: ~%d = %d\n", num2, BITWISE_NOT num2);

    //Display the Bitwise Left Shift operation
    printf("Bitwise Left Shift of first number by 2: %d << 2 = %d\n", num1, num1 BITWISE_LEFT_SHIFT 2);

    //Display the Bitwise Right Shift operation
    printf("Bitwise Right Shift of second number by 2: %d >> 2 = %d\n", num2, num2 BITWISE_RIGHT_SHIFT 2);

    return 0;
}