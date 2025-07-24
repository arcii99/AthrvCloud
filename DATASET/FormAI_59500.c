//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include<stdio.h>

int main() {
    int num1, num2, choice;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter your choice of operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The sum of %d and %d is %d", num1, num2, num1+num2);
            break;
        case 2:
            printf("The difference of %d and %d is %d", num1, num2, num1-num2);
            break;
        case 3:
            printf("The product of %d and %d is %d", num1, num2, num1*num2);
            break;
        case 4:
            if(num2 == 0) {
                printf("Cannot divide by zero");
            }
            else {
                printf("The quotient of %d and %d is %d", num1, num2, num1/num2);
            }
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}