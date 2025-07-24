//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Hello! I am your Bitwise Calculator. Let's make some magic happen!\n\n");

    printf("Enter two numbers and let's see some Bitwise Operations in action: \n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("\n>> The number %d in binary is: ", num1);
    int i;
    for(i = 31; i >= 0; i--) {
        int binary = (num1 >> i) & 1;
        printf("%d", binary);
    }

    printf("\n>> The number %d in binary is: ", num2);
    for(i = 31; i >= 0; i--) {
        int binary = (num2 >> i) & 1;
        printf("%d", binary);
    }

    printf("\n\n---- Let's see some Bitwise Operations in action! ----\n\n");

    int and = num1 & num2;
    printf("        %d &\n        %d =\n        %d\n\n", num1, num2, and);

    int or = num1 | num2;
    printf("        %d |\n        %d =\n        %d\n\n", num1, num2, or);

    int xor = num1 ^ num2;
    printf("        %d ^\n        %d =\n        %d\n\n", num1, num2, xor);

    int not1 = ~num1;
    printf("        ~%d =\n        %d\n\n", num1, not1);

    int not2 = ~num2;
    printf("        ~%d =\n        %d\n\n", num2, not2);

    int left_shift = num1 << 2;
    printf("        %d << 2 =\n        %d\n\n", num1, left_shift);

    int right_shift = num2 >> 3;
    printf("        %d >> 3 =\n        %d\n\n", num2, right_shift);

    printf("Thank you for tinkering with me! Until next time.\n");

    return 0;
}