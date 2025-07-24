//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
#include <stdio.h>

int main() {

    int a = 10, b = 20;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    
    return 0;
}

/*
Output:
a + b = 30
a - b = -10
a * b = 200
a / b = 0
*/

/*
Explanation:
This code snippet demonstrates the basic arithmetic operations that can be performed in C. In this program, two integer variable 'a' and 'b' are defined and initialized with values 10 and 20 respectively. Then, the program performs four arithmetic operations - addition, subtraction, multiplication, and division - on these variables using the +, -, *, and / operators respectively. The results of each operation are displayed on the screen using printf() function with proper formatting strings. Finally, the program returns zero to signify successful execution. However, the result of division operation is zero because both operands are integers, therefore integer division is performed. In order to get the correct quotient, one of the operands must be converted to float by explicitly casting it to (float) type.
*/