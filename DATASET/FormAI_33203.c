//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include<stdio.h>

int main(){
    int num1, num2, sum, difference, product, quotient, remainder;

    printf("Welcome to the intelligent calculation bot!\n");

    printf("Enter two integers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    // Display the results
    printf("\nIntelligent Calculation Results:\n\n");
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, difference);
    printf("%d * %d = %d\n", num1, num2, product);
    printf("%d / %d = %d\n", num1, num2, quotient);
    printf("%d %% %d = %d\n", num1, num2, remainder);

    if (num1 > num2) {
        printf("\nThe larger of the two numbers is %d.\n", num1);
    } else {
        printf("\nThe larger of the two numbers is %d.\n", num2);
    }

    printf("\nThank you for using our intelligent calculation bot! We hope to see you again soon!\n");

    return 0;
}