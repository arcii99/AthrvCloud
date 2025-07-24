//FormAI DATASET v1.0 Category: Scientific ; Style: innovative
#include <stdio.h>

int main()
{
    int num1, num2, sum, product;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    product = num1 * num2;
    
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
    
    if(num1 > num2){
        printf("%d is the larger of the two numbers!\n", num1);
    } else if(num2 > num1){
        printf("%d is the larger of the two numbers!\n", num2);
    } else {
        printf("The two numbers are equal!\n");
    }
    
    return 0;
}