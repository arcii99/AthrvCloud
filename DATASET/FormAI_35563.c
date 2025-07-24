//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

int main(void) {
    int num1 = 12, num2 = 25;
    printf("We are grateful for the use of Bitwise operators!\n\n");
    printf("We will now demonstrate the power of Bitwise AND operator...\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    int result = num1 & num2;
    printf("num1 & num2 = %d\n\n", result);

    printf("Let us now move on to the Bitwise OR operator...\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    result = num1 | num2;
    printf("num1 | num2 = %d\n\n", result);

    printf("But wait, there's more! The Bitwise XOR operator...\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    result = num1 ^ num2;
    printf("num1 ^ num2 = %d\n\n", result);

    printf("Now, let's try the Bitwise NOT operator...\n");
    printf("num1 = %d\n", num1);
    result = ~num1;
    printf("~num1 = %d\n\n", result);

    printf("Lastly, we will use the Bitwise left-shift operator...\n");
    printf("num1 = %d\n", num1);
    result = num1 << 2;
    printf("num1 << 2 = %d\n", result);

    printf("We hope you found this program helpful. May we always be grateful for the power of Bitwise operators!\n");

    return 0;
}