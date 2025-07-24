//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include <stdio.h>

int t,t1,t2,t3,t4,t5,t6,t7,t8,t9;  // Initializing Variables

int main(){
    t = 20;                        // Assigning value to the variable
        
    t1 = 2*t;                      // Multiplication
    t2 = t/3;                      // Division
    t3 = t+5;                      // Addition
    t4 = t-9;                      // Subtraction
    t5 = t%4;                      // Modulus
    t6 = t<<2;                     // Left shift
    t7 = t>>1;                     // Right shift
    t8 = ~t;                       // Bitwise NOT
    t9 = t&t2;                     // Bitwise AND
        
    printf("Value of t: %d\n",t);
    printf("Result after multiplication: %d\n",t1);
    printf("Result after division: %d\n",t2);
    printf("Result after addition: %d\n",t3);
    printf("Result after subtraction: %d\n",t4);
    printf("Result after modulus: %d\n",t5);
    printf("Result after left shift: %d\n",t6);
    printf("Result after right shift: %d\n",t7);
    printf("Result after bitwise NOT: %d\n",t8);
    printf("Result after bitwise AND: %d\n",t9);
    return 0;  
}