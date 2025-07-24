//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include<stdio.h>

int main() {
    printf("Welcome to the exciting world of C Performance-Critical Components!\n");
    printf("In this program, we will be calculating the factorial of a number entered by the user.\n");
    
    int num, fact=1, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    for(i=1; i<=num; i++) {
        fact = fact * i;
    }

    printf("The factorial of %d is %d\n", num, fact);
    
    printf("But wait, we can make this program even faster!\n");
    printf("Let's use bitwise operators to calculate the factorial!\n");
    
    fact = 1;
    for(i=1; i<=num; i++) {
        fact = fact << i;
    }
    
    printf("The factorial of %d using bitwise operators is %d\n", num, fact);
    printf("Wow, that was amazing! Thank you for joining me on this exciting journey of C Performance-Critical Components!\n");

    return 0;
}