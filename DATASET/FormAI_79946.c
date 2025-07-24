//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include<stdio.h> 

int main() 
{ 
    int a = 4, b = 5; 
    int c,d,e,f,g;

    //Performing Bitwise AND operation

    c = a & b;

    printf("*****Bitwise AND Operation*****\n\n");

    printf("The value of a is %d and b is %d\n", a, b); 
    printf("The Bitwise AND Operation of a and b is %d\n\n", c);

    //Performing Bitwise OR operation

    d = a | b;

    printf("*****Bitwise OR Operation*****\n\n");

    printf("The value of a is %d and b is %d\n", a, b); 
    printf("The Bitwise OR Operation of a and b is %d\n\n", d);

    //Performing Bitwise NOT operation

    e = ~a;

    printf("*****Bitwise NOT Operation*****\n\n");

    printf("The value of a is %d\n", a); 
    printf("The Bitwise NOT Operation of a is %d\n\n", e);

    //Performing Bitwise XOR operation

    f = a ^ b;

    printf("*****Bitwise XOR Operation*****\n\n");

    printf("The value of a is %d and b is %d\n", a, b); 
    printf("The Bitwise XOR Operation of a and b is %d\n\n", f);

    //Performing Bitwise Left Shift operation

    g = a<<1;

    printf("*****Bitwise Left Shift Operation*****\n\n");

    printf("The value of a is %d\n", a); 
    printf("The Bitwise Left Shift Operation of a is %d\n\n", g);

    return 0; 
}