//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include<stdio.h>

int main(){
    int num1, num2, result, choice;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("Choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("\n%d x %d = %d\n", num1, num2, result);
            break;

        case 4:
            if(num2 == 0) {
                printf("\nError: Division by zero not possible\n");
            } else {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
            }
            break;

        default:
            printf("\nInvalid choice\n");
    }

    return 0;
}