//FormAI DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include<stdio.h>

int main(){

    int num_1 = 57, num_2 = 19, bitwise_and, bitwise_or, bitwise_xor, bitwise_negation;
    // 57 is 0011 1001 in binary
    // 19 is 0001 0011 in binary
    
    bitwise_and = num_1 & num_2;
    // bitwise AND in binary 0011 0001, denary 49
    printf("The bitwise AND of %d and %d is %d.\n", num_1, num_2, bitwise_and);
    
    bitwise_or = num_1 | num_2;
    // bitwise OR in binary 0011 1011, denary 59
    printf("The bitwise OR of %d and %d is %d.\n", num_1, num_2, bitwise_or);
    
    bitwise_xor = num_1 ^ num_2;
    // bitwise XOR in binary 0000 1010, denary 10
    printf("The bitwise XOR of %d and %d is %d.\n", num_1, num_2, bitwise_xor);
    
    bitwise_negation = ~num_2;
    // bitwise negation in binary 1110 1100, denary -20
    printf("The bitwise negation of %d is %d.\n", num_2, bitwise_negation);
    
    return 0;
}