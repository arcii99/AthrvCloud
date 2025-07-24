//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h> 

int main() 
{ 
    int num1 = 12; 
    int num2 = 25; 
    int result;
    
    printf("The initial values of num1 and num2 are %d and %d\n", num1, num2);
  
    //bitwise AND operator 
    result = num1 & num2; 
    printf("Result of num1 & num2 is %d\n", result); 

    //bitwise OR operator 
    result = num1 | num2;    
    printf("Result of num1 | num2 is %d\n", result); 

    //bitwise XOR operator 
    result = num1 ^ num2;   
    printf("Result of num1 ^ num2 is %d\n", result); 

    //bitwise Left Shift operator 
    result = num1<<2;       
    printf("Result of num1<<2 is %d\n", result); 

    //bitwise Right Shift operator 
    result = num2>>2;       
    printf("Result of num2>>2 is %d\n", result); 
    
    //bitwise NOT operator 
    result = ~num1;         
    printf("Result of ~num1 is %d\n", result); 

    num1 &= num2;           
    printf("Result of num1 &= num2 is %d\n", num1);

    num1 |= num2;           
    printf("Result of num1 |= num2 is %d\n", num1);

    num1 ^= num2;           
    printf("Result of num1 ^= num2 is %d\n", num1);

    num1 >>= 2;             
    printf("Result of num1 >>= 2 is %d\n", num1);

    num2 <<= 2;             
    printf("Result of num2 <<= 2 is %d\n", num2); 
 
    return 0; 
}