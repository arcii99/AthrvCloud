//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Bitwise Boogie!\n");
    printf("Get ready to groove with some bitwise operations!\n\n");

    // Shift left and right example
    int num = 7;
    printf("Let's start with shifting!\n");
    printf("The number %d in binary is 00000111.\n", num);
    printf("Shifting left by 2 gives us %d in binary, which is 00011100.\n", num << 2);
    printf("Shifting right by 1 gives us %d in binary, which is 00000011.\n\n", num >> 1);

    // AND, OR, XOR example
    int num1 = 9;
    int num2 = 6;
    printf("Now let's try some AND, OR, and XOR operations!\n");
    printf("num1 is %d in binary, which is 00001001.\n", num1);
    printf("num2 is %d in binary, which is 00000110.\n", num2);
    printf("num1 & num2 is %d in binary, which is 00000000. That's because there are no matching bits!\n", num1 & num2);
    printf("num1 | num2 is %d in binary, which is 00001111. That's because every bit has either a 1 or a 0!\n", num1 | num2);
    printf("num1 ^ num2 is %d in binary, which is 00001111 as well. That's because every bit has either a 1 or a 0, but not both!\n\n", num1 ^ num2);
   
    // NOT example
    printf("Lastly, let's try NOT. This is easy!\n");
    printf("NOT num1 is %d in binary, which is 11110110. All bits are flipped!\n", ~num1);

    printf("\nI hope you enjoyed the Bitwise Boogie! Keep grooving with C!\n");

    return 0;
}