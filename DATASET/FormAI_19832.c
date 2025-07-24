//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {

    unsigned int x = 115; // Binary of 115 is 01110011 
    unsigned int y = 97;  // Binary of 97 is  01100001

   // Bitwise AND operator
    printf("Bitwise AND: x & y = %d\n", x & y); // Binary of 81 is 01010001
  
  // Bitwise OR operator               
    printf("Bitwise OR: x | y = %d\n", x | y);  // Binary of 115 is 01110011
   
   // Bitwise XOR operator
    printf("Bitwise XOR: x ^ y = %d\n", x^y);   // Binary of 34 is 00100010
        
    // Bitwise complement operator
    printf("Bitwise Complement: ~x = %d\n", ~x); // Binary of 4294967180
  
    // Bitwise Left Shift operator
    printf("Bitwise Left Shift: x << 2 = %d\n", x << 2); /* Multiply x with 2^2=4, Binary of 1000100 is 11100100 */
       
    // Bitwise Right Shift operator
    printf("Bitwise Right Shift: x >> 2 = %d\n", x >> 2); /* Divide x with 2^2=4, Binary of 011100 is 1110*/
    
    return 0;
}