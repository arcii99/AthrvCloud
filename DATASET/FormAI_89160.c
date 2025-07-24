//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

/* Define some binary numbers */
#define BINARY1 0b11001100
#define BINARY2 0b10101010
 
int main()
{
    int bitwise_or = BINARY1 | BINARY2; // Perform binary OR operation
    int bitwise_and = BINARY1 & BINARY2; // Perform binary AND operation
    int bitwise_not = ~BINARY1; // Perform binary NOT operation
    int bitwise_shift_right = BINARY1 >> 2; // Perform right shift operation
    int bitwise_shift_left = BINARY2 << 2; // Perform left shift operation
   
    printf("Binary OR result: %d\n", bitwise_or);
    printf("Binary AND result: %d\n", bitwise_and);
    printf("Binary NOT result: %d\n", bitwise_not);
    printf("Binary shift-right result: %d\n", bitwise_shift_right);
    printf("Binary shift-left result: %d\n", bitwise_shift_left);

    return 0;
}