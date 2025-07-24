//FormAI DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>

int main() {

    int num1, num2;
    char operator, choice;

    do {
        printf("Enter an arithmetic expression: ");
        scanf("%d %c %d", &num1, &operator, &num2);

        switch(operator) {
            case '+':
                printf("%d + %d = %d\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("%d - %d = %d\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("%d * %d = %d\n", num1, num2, num1 * num2);
                break;
            case '/':
                if(num2 == 0) {
                    printf("Cannot divide by zero\n");
                }
                else {
                    printf("%d / %d = %.2f\n", num1, num2, (float) num1 / num2);
                }
                break;
            default:
                printf("Invalid operator\n");
        }
        
        printf("Do you want to perform another calculation? (Y/N) ");
        scanf(" %c", &choice);
        
    } while(choice == 'Y' || choice == 'y');

    printf("Exiting program...\n");

    return 0;
}