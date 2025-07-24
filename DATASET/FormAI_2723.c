//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include<stdio.h>

// A function that performs bitwise left shift on x and y
void bitwise_left_shift(int x, int y){
    int result = x << y;
    printf("%d << %d = %d\n", x, y, result);
}

// A function that performs bitwise right shift on x and y
void bitwise_right_shift(int x, int y){
    int result = x >> y;
    printf("%d >> %d = %d\n", x, y, result);
}

int main(){
    int x = 10, y = 2;
    printf("Welcome to Bitwise operators program\n");
    
    // Performing Bitwise AND operation
    int a = 15, b = 25;
    int result = a & b;
    printf("%d & %d = %d\n", a, b, result);
    
    // Performing Bitwise OR operation
    a = 15, b = 25;
    result = a | b;
    printf("%d | %d = %d\n", a, b, result);
    
    // Performing Bitwise XOR operation
    a = 15, b = 25;
    result = a ^ b;
    printf("%d ^ %d = %d\n", a, b, result);
    
    // Performing Bitwise Ones Complement operation
    a = 15;
    result = ~a;
    printf("~%d = %d\n", a, result);
    
    // Calling Bitwise shift functions
    bitwise_left_shift(x, y);
    bitwise_right_shift(x, y);
    
    printf("Thanks for using Bitwise operators program!\n");
    return 0;
}