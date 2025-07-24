//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include<stdio.h>

int main(){

    int x = 10;
    int y = 5;
    int result;

    //Performing AND operation on x and y
    result = x & y;

    printf("The result of bitwise AND between %d and %d is %d\n", x, y, result);

    //Performing OR operation on x and y
    result = x | y;

    printf("The result of bitwise OR between %d and %d is %d\n", x, y, result);

    //Performing XOR operation on x and y
    result = x ^ y;

    printf("The result of bitwise XOR between %d and %d is %d\n", x, y, result);

    //Performing LEFT SHIFT operation on x by two positions
    result = x << 2;

    printf("The result of left shift of %d by 2 bits is %d\n", x, result);

    //Performing RIGHT SHIFT operation on x by two positions
    result = x >> 2;

    printf("The result of right shift of %d by 2 bits is %d\n", x, result);

    //Performing COMPLEMENT operation on x
    result = ~x;

    printf("The result of complement of %d is %d\n", x, result);

    return 0;
}