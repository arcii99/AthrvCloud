//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h> 

// Function to display the bitwise operations
void displayBitwiseOperations(int a, int b) 
{ 
    int result; 
    
    // Bitwise AND
    result = a & b; 
    printf("a & b = %d\n", result); 
    
    // Bitwise OR
    result = a | b; 
    printf("a | b = %d\n", result); 
    
    // Bitwise XOR
    result = a ^ b; 
    printf("a ^ b = %d\n", result); 
    
    // Bitwise NOT
    result = ~a; 
    printf("~a = %d\n", result); 
    
    // Left Shift
    result = a << 1; 
    printf("a << 1 = %d\n", result); 
    
    // Right Shift
    result = a >> 1; 
    printf("a >> 1 = %d\n", result); 
} 

int main() 
{ 
    int a = 15; 
    int b = 30; 
    
    // Display the bitwise operations for a and b
    displayBitwiseOperations(a, b); 
    
    return 0; 
}