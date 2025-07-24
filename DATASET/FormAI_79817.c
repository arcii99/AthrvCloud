//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include<stdio.h>

int main() {
    // Brave style program to perform basic arithmetic operations
    int a, b;
    printf("Welcome to the Brave Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%d", &a);
    printf("Please enter the second number: ");
    scanf("%d", &b);
    
    // Addition
    printf("%d + %d = %d\n", a, b, a+b);
    
    // Subtraction
    printf("%d - %d = %d\n", a, b, a-b);
    
    // Multiplication
    printf("%d * %d = %d\n", a, b, a*b);
    
    // Division
    if(b != 0) printf("%d / %d = %f\n", a, b, (float)a/b);
    else printf("Cannot perform division by zero!\n");
    
    // Modulus
    if(b != 0) printf("%d %% %d = %d\n", a, b, a%b);
    else printf("Cannot perform modulus by zero!\n");
    
    printf("Thank you for using the Brave Calculator!");
    return 0;
}