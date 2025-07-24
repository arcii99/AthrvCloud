//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main() {
    char operation;
    int number, result;
    float fnumber, fresult;
    
    printf("Welcome to my scientific calculator!\n");
    printf("Please choose the operation you want to perform:\n");
    printf("a - addition\ns - subtraction\nm - multiplication\nd - division\n");
    scanf("%c", &operation);
    
    switch(operation) {
        case 'a':
            printf("Enter the first number: ");
            scanf("%d", &number);
            printf("Enter the second number: ");
            scanf("%d", &number);
            result = number + number;
            printf("The result is: %d\n", result);
            break;
        
        case 's':
            printf("Enter the first number: ");
            scanf("%d", &number);
            printf("Enter the second number: ");
            scanf("%d", &number);
            result = number - number;
            printf("The result is: %d\n", result);
            break;
        
        case 'm':
            printf("Enter the first number: ");
            scanf("%d", &number);
            printf("Enter the second number: ");
            scanf("%d", &number);
            result = number * number;
            printf("The result is: %d\n", result);
            break;
        
        case 'd':
            printf("Enter the first number: ");
            scanf("%f", &fnumber);
            printf("Enter the second number: ");
            scanf("%f", &fnumber);
            fresult = fnumber / fnumber;
            printf("The result is: %.2f\n", fresult);
            break;
        
        default:
            printf("Invalid operation!\n");
    }
    
    return 0;
}