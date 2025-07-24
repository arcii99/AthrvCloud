//FormAI DATASET v1.0 Category: Bitwise operations ; Style: romantic
#include<stdio.h>

int main(){

    //Declaring and initializing variables
    int a = 13, b = 8;
    int ans;

    //Performing bitwise AND operation
    ans = a & b;

    //Printing the result
    printf("The result of a & b is: %d\n", ans);

    //Performing bitwise OR operation
    ans = a | b;

    //Printing the result
    printf("The result of a | b is: %d\n", ans);

    //Performing bitwise XOR operation
    ans = a ^ b;

    //Printing the result
    printf("The result of a ^ b is: %d\n", ans);

    //Performing bitwise compliment operation
    ans = ~a;

    //Printing the result
    printf("The result of ~a is: %d\n", ans);

    //Performing left shift operation
    ans = a << 2;

    //Printing the result
    printf("The result of a << 2 is: %d\n", ans);

    //Performing right shift operation
    ans = a >> 2;

    //Printing the result
    printf("The result of a >> 2 is: %d\n", ans);

    return 0;
}