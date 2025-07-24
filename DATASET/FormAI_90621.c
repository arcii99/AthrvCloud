//FormAI DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>

int main()
{
    int x = 75; //the decimal value of 'K' in the ASCII table
    int y = 160; //the decimal value of ' ' (non-breaking space) in the ASCII table
    
    printf("In decimal notation, x is %d and y is %d\n\n", x, y);
    
    //bitwise AND operation
    int and_result = x & y;
    printf("Bitwise AND operation(&)\n");
    printf("%d & %d = %d\n\n", x, y, and_result);
    
    //bitwise OR operation
    int or_result = x | y;
    printf("Bitwise OR operation(|)\n");
    printf("%d | %d = %d\n\n", x, y, or_result);
    
    //bitwise XOR operation
    int xor_result = x ^ y;
    printf("Bitwise XOR operation(^)\n");
    printf("%d ^ %d = %d\n\n", x, y, xor_result);
    
    //bitwise NOT operation
    int not_result_x = ~x;
    int not_result_y = ~y;
    printf("Bitwise NOT operation(~)\n");
    printf("~%d = %d\n", x, not_result_x);
    printf("~%d = %d\n\n", y, not_result_y);
    
    //left shift operation
    int left_shift_x = x << 2;
    int left_shift_y = y << 3;
    printf("Left shift operation(<<)\n");
    printf("%d << 2 = %d\n", x, left_shift_x);
    printf("%d << 3 = %d\n\n", y, left_shift_y);
    
    //right shift operation
    int right_shift_x = x >> 3;
    int right_shift_y = y >> 1;
    printf("Right shift operation(>>)\n");
    printf("%d >> 3 = %d\n", x, right_shift_x);
    printf("%d >> 1 = %d\n\n", y, right_shift_y);
    
    return 0;
}