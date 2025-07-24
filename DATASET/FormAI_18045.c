//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include<stdio.h> 

int main() { 
    long long num1, num2; 

    printf("Enter two integers: "); 
    scanf("%lld %lld", &num1, &num2); 

    printf("\n First integer before swapping bits: %lld", num1); 
    printf("\n Second integer before swapping bits: %lld", num2); 

    // Swapping least significant bits using XOR bitwise operator
    num1 = num1 ^ num2; 
    num2 = num1 ^ num2; 
    num1 = num1 ^ num2; 

    printf("\n First integer after swapping bits: %lld", num1); 
    printf("\n Second integer after swapping bits: %lld", num2); 

    // Reversing the bits of num1 using bitwise shift operators
    int n = sizeof(num1) * 8; // find the number of bits
    unsigned int rev = 0; 
    for(int i = 0; i < n; i++) { 
        if((num1 & (1 << i))) 
            rev |= 1 << ((n - 1) - i); 
    } 

    printf("\n Reversed bits of num1: %lld", rev); 

    // Checking if any bit in num2 is set to 1 using bitwise AND operator and if statement
    if(num2 & 1) 
        printf("\n Least significant bit of num2 is set to 1"); 
    else
        printf("\n Least significant bit of num2 is set to 0"); 

    // Flipping every other bit of num2 using XOR bitwise operator and NOT bitwise operator
    num2 = ~num2 ^ (0xAAAAAAAA); 

    printf("\n num2 after flipping every other bit: %lld", num2); 

    return 0; 
}