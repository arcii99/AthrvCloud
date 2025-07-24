//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main()
{
    int a = 10; // initializing a with 10
    int b = 6;  // initializing b with 6
    printf("Initial Value of a : %d\n",a); // printing the initial value of a
    printf("Initial Value of b : %d\n",b); // printing the initial value of b

    a = a ^ b; // performing XOR
    b = a ^ b; // performing XOR
    a = a ^ b; // performing XOR
    printf("After swapping a : %d\n",a); // printing the value of a
    printf("After swapping b : %d\n",b); // printing the value of b

    int c = 7; // initializing c with 7
    int d = 4; // initializing d with 4
    printf("Initial Value of c : %d\n",c); // printing the initial value of c
    printf("Initial Value of d : %d\n",d); // printing the initial value of d
    c = c << d; // performing left shift
    printf("After left shift c : %d\n",c); // printing the value of c

    int e = 12; // initializing e with 12
    int f = 3;  // initializing f with 3
    printf("Initial Value of e : %d\n",e); // printing the initial value of e
    printf("Initial Value of f : %d\n",f); // printing the initial value of f
    e = e >> f; // performing right shift
    printf("After right shift e : %d\n",e); // printing the value of e

    int g = 5;  // initializing g with 5
    int h = 11; // initializing h with 11
    printf("Initial Value of g : %d\n",g); // printing the initial value of g
    printf("Initial Value of h : %d\n",h); // printing the initial value of h
    g = g | h; // performing OR operation
    printf("After OR operation g : %d\n",g); // printing the value of g

    int i = 7;  // initializing i with 7
    int j = 2;  // initializing j with 2
    printf("Initial Value of i : %d\n",i); // printing the initial value of i
    printf("Initial Value of j : %d\n",j); // printing the initial value of j

    int k = i & j; // performing AND operation
    printf("After AND operation k : %d\n",k); // printing the value of k

    return 0;
}