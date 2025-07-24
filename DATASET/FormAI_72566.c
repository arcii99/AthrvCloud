//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's parse some happy C syntax!
    int num = 5;
    float dec = 2.5;
    char letter = 'H';
    char name[10] = "HappyJoy";
    
    printf("Hello! Let's parse some happy syntax in C!\n");
    
    printf("Number: %d\n", num);
    printf("Decimal: %.2f\n", dec);
    printf("Letter: %c\n", letter);
    printf("Name: %s\n", name);
    
    // Let's loop through some happy numbers!
    int i;
    for(i = 1; i <= 10; i++) {
        printf("%d is a happy number!\n", i);
    }
    
    // Happy conditional statements!
    if(num <= 5) {
        printf("The number is <= 5 which makes me happy!\n");
    } else {
        printf("The number is > 5 which is also happy because it's bigger!\n");
    }
    
    // Happy arrays!
    int nums[] = {1, 2, 3, 4, 5};
    printf("The second number in the array is %d!\n", nums[1]);
    
    // Happy pointers!
    int *pNum = &num;
    printf("The value of num is %d and it's stored at address %p!\n", *pNum, pNum);
    
    // Happy memory allocation!
    char *happyString = malloc(sizeof(char) * 20);
    happyString = "I love happy syntax!";
    printf("%s\n", happyString);
    free(happyString);
    
    // Happy functions!
    int sum(int a, int b) {
        int result = a + b;
        return result;
    }
    printf("The sum of num and dec is %d!\n", sum(num, (int)dec));
    
    // Happy bitwise operators!
    int x = 5; // 0101 in binary
    int y = 10; // 1010 in binary
    int z = x | y; // 1111 in binary (15 in decimal)
    printf("The bitwise OR of %d and %d is %d which makes me happy!\n", x, y, z);
    
    printf("Thanks for parsing happy syntax with me in C!\n");
    
    return 0;
}