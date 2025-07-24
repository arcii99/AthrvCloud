//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main(){

    int num1 = 30;
    int num2 = 20;

    //Bitwise AND operation
    printf("Bitwise AND: %d\n", num1 & num2);

    //Bitwise OR operation
    printf("Bitwise OR: %d\n", num1 | num2);

    //Bitwise XOR operation
    printf("Bitwise XOR: %d\n", num1 ^ num2);

    //Bitwise NOT operation
    printf("Bitwise NOT of num1: %d\n", ~num1);

    //Bitwise left shift operation
    printf("Bitwise left shift of num1: %d\n", num1 << 2);

    //Bitwise right shift operation
    printf("Bitwise right shift of num1: %d\n", num1 >> 2);

    return 0;
}