//FormAI DATASET v1.0 Category: Scientific ; Style: energetic
#include <stdio.h>

int main() {
    int num1, num2, sum;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    
    if(sum % 2 == 0) {
        printf("It's an even number! Wowzers!!\n");
    } else {
        printf("It's odd! What a strange and wacky world we live in!!\n");
    }
    
    printf("And there you have it folks! A program that adds two numbers and tells you if the sum is odd or even! Are you energized? I know I am!!\n");
    
    return 0;
}