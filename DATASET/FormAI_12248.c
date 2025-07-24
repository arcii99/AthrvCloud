//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int bitCount(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num &= (num - 1);
    }
    return count;
}

int main() {
    int num = 106;
    int bitwiseAndNum = num & 32;
    int bitwiseOrNum = num | 23;
    int bitwiseXorNum = num ^ 78;
    int leftShiftNum = num << 2;
    int rightShiftNum = num >> 1;
    int isMultipleOfTwo = !(num & (num - 1));

    printf("The number is: %d\n", num);
    printf("The number in binary is: %d%d%d%d%d%d%d%d\n", 
            (num >> 7) & 1, (num >> 6) & 1, (num >> 5) & 1, (num >> 4) & 1, 
            (num >> 3) & 1, (num >> 2) & 1, (num >> 1) & 1, num & 1);
    printf("The number of 1 bits in the number is: %d\n", bitCount(num));
    printf("The result of num & 32 is: %d\n", bitwiseAndNum);
    printf("The result of num | 23 is: %d\n", bitwiseOrNum);
    printf("The result of num ^ 78 is: %d\n", bitwiseXorNum);
    printf("The result of num << 2 is: %d\n", leftShiftNum);
    printf("The result of num >> 1 is: %d\n", rightShiftNum);
    printf("The number is %s a multiple of 2\n", isMultipleOfTwo ? "" : "not");

    return 0;
}