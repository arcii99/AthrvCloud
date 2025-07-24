//FormAI DATASET v1.0 Category: Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the CALCULATOR!\n");
    printf("Please enter your first number: ");
    float a;
    scanf("%f", &a);

    printf("\nPlease enter your second number: ");
    float b;
    scanf("%f", &b);

    printf("\nAwesome! Now let's perform some calculations!!!\n");

    printf("\n\n----------------------------------------\n");
    printf("Addition: %.2f + %.2f = %.2f", a,b,a+b);
    printf("\n----------------------------------------\n");

    printf("\n\n----------------------------------------\n");
    printf("Subtraction: %.2f - %.2f = %.2f", a,b,a-b);
    printf("\n----------------------------------------\n");

    printf("\n\n----------------------------------------\n");
    printf("Multiplication: %.2f * %.2f = %.2f", a,b,a*b);
    printf("\n----------------------------------------\n");

    printf("\n\n----------------------------------------\n");
    if (b != 0){

        printf("Division: %.2f / %.2f = %.2f", a,b,a/b);
    }else{

      printf("Division: Can't divide by zero! ¯\\_(ツ)_/¯");
    }
    printf("\n----------------------------------------\n");

    printf("\n\nThank you for using the CALCULATOR! Come back soon :)\n");
    return 0;   
}