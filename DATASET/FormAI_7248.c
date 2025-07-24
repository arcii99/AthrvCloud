//FormAI DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

int main(){
    int a = 12, b = 25, c = 4, d = 7;
    
    //Bitwise AND
    int result_1 = a & b;
    printf("Result of a & b is: %d\n", result_1);
    
    //Bitwise OR
    int result_2 = a | b ;
    printf("Result of a | b is: %d\n", result_2);
    
    //Bitwise XOR
    int result_3 = a ^ b;
    printf("Result of a ^ b is: %d\n", result_3);
    
    //Bitwise LEFT SHIFT
    int result_4 = c << 1;
    printf("Result of c << 1 is: %d\n", result_4);
    
    //Bitwise RIGHT SHIFT
    int result_5 = d >> 1;
    printf("Result of d >> 1 is: %d\n", result_5);
    
    //Bitwise Complement
    int result_6 = ~a;
    printf("Result of ~a is: %d\n", result_6);
    
    //Using Bitwise Operations to Manipulate the Bits of a Number
    
    //Clear a bit: Clearing the 4th bit of variable 'a'
    unsigned int mask = ~(1 << 3);
    int result_7 = a & mask;
    printf("Result of clearing the 4th bit of 'a' is: %d\n", result_7);
    
    //Set a bit: Setting the 3rd bit of variable 'b'
    int result_8 = b | (1 << 2);
    printf("Result of setting the 3rd bit of 'b' is: %d\n", result_8);
    
    //Toggle a bit: Toggling the 2nd bit of variable 'c'
    int result_9 = c ^ (1 << 1);
    printf("Result of toggling the 2nd bit of 'c' is: %d\n", result_9);
    
    return 0;
}