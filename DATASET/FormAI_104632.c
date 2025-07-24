//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

int main() {

    int num1 = 27;
    int num2 = 5;
    
    printf("Let's do some bitwise operations! \n\n");
    
    //Bitwise AND operation
    printf("The result of num1 & num2 is: %d \n", num1 & num2); 
    
    //Bitwise OR operation
    printf("The result of num1 | num2 is: %d \n", num1 | num2); 
    
    //Bitwise XOR operation
    printf("The result of num1 ^ num2 is: %d \n", num1 ^ num2); 
    
    //Bitwise NOT operation
    printf("The result of ~num1 is: %d \n", ~num1); 
    
    //Left shift operation
    printf("The result of num1 << 2 is: %d \n", num1 << 2); 
    
    //Right shift operation
    printf("The result of num1 >> 2 is: %d \n", num1 >> 2); 
    
    //Setting a bit to 1
    int num3 = 12;
    printf("\nBefore setting the 4th bit of num3: %d \n", num3); 
    num3 |= 1 << 3;
    printf("After setting the 4th bit of num3 to 1: %d \n", num3);
    
    //Setting a bit to 0
    int num4 = 15;
    printf("\nBefore setting the 2nd bit of num4 to 0: %d \n", num4); 
    num4 &= ~(1 << 1);
    printf("After setting the 2nd bit of num4 to 0: %d \n", num4);
    
    return 0;
}