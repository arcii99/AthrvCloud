//FormAI DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>

int main()
{
    printf("Welcome to the Energized C Learning Program!\n");

    int num1, num2, sum, sub, mul, div;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    
    if(num2 != 0) {
        div = num1 / num2;
    } else {
        printf("Cannot divide by 0.\n");
    }

    printf("The sum of the two numbers is: %d\n", sum);
    printf("The difference between the two numbers is: %d\n", sub);
    printf("The product of the two numbers is: %d\n", mul);
    
    if(num2 != 0) {
        printf("The dividend of the two numbers is: %d\n", div);
    }

    float avg;

    if(num1 != 0 && num2 != 0) {
        avg = (float)(num1 + num2) / 2;
        printf("The average of the two numbers is: %.2f\n", avg);
    } else {
        printf("Cannot find average if either number is 0.\n");
    }

    printf("Thank you for using the Energized C Learning Program!\n");

    return 0;
}