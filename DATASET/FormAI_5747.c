//FormAI DATASET v1.0 Category: Bitwise operations ; Style: immersive
#include <stdio.h>

int main() {
    printf("Welcome to the secret world of bitwise operations!\n");
    printf("Are you ready to experience the power of the & operator?\n");
    int number1 = 10; // binary equivalent: 1010
    int number2 = 6; // binary equivalent: 0110
    int result = number1 & number2; // bitwise AND operation
    printf("The result of %d & %d is %d\n", number1, number2, result);
    
    printf("Amazing, right? But, can you handle the power of the | operator?\n");
    int number3 = 12; // binary equivalent: 1100
    int result2 = number2 | number3; // bitwise OR operation
    printf("The result of %d | %d is %d\n", number2, number3, result2);
    
    printf("Now, let's explore the power of bitwise XOR!\n");
    int number4 = 2; // binary equivalent: 0010
    int number5 = 7; // binary equivalent: 0111
    int result3 = number4 ^ number5; // bitwise XOR operation
    printf("The result of %d ^ %d is %d\n", number4, number5, result3);
    
    printf("But, let's not forget about the power of one's complement operator!\n");
    int number6 = 17; // binary equivalent: 0001 0001
    int result4 = ~number6; // one's complement operation
    printf("The result of ~%d is %d\n", number6, result4);
    
    printf("Finally, let's experience the beauty of left and right shift operators!\n");
    int number7 = 16; // binary equivalent: 0001 0000
    int result5 = number7 << 2; // left shift operation
    printf("The result of %d << 2 is %d\n", number7, result5);
    int result6 = number7 >> 2; // right shift operation
    printf("The result of %d >> 2 is %d\n", number7, result6);
    
    printf("Congratulations! You have now experienced the power of bitwise operations!\n");
    return 0;
}