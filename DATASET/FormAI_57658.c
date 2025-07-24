//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
/* This program performs bitwise operations on two integer values. 
 * It was inspired by a quote from Donald Knuth which said,
 * "Bitwise operators are like the hand tools of programming; 
 *  use them correctly and they can be an extremely powerful force."
 */

#include <stdio.h>

int main(void) {
    int x, y;  // input integers
    int result; // output of the bitwise operations
    
    // get input values from user
    printf("Enter two integer values: ");
    scanf("%d %d", &x, &y);
    
    // perform bitwise AND operation
    result = x & y;
    printf("Bitwise AND operation:\n%d & %d = %d\n", x, y, result);
    
    // perform bitwise OR operation
    result = x | y;
    printf("Bitwise OR operation:\n%d | %d = %d\n", x, y, result);
    
    // perform bitwise XOR operation
    result = x ^ y;
    printf("Bitwise XOR operation:\n%d ^ %d = %d\n", x, y, result);
    
    // perform bitwise NOT operation on x
    result = ~x;
    printf("Bitwise NOT operation (on x):\n~%d = %d\n", x, result);
    
    // perform left shift operation on x
    result = x << 2;
    printf("Left shift operation (on x):\n%d << 2 = %d\n", x, result);
    
    // perform right shift operation on y
    result = y >> 1;
    printf("Right shift operation (on y):\n%d >> 1 = %d\n", y, result);
    
    return 0;
}