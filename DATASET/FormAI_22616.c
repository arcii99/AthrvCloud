//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result;
    
    printf("Welcome to the cheerful error handling example program!\n");
    printf("Enter two numbers to add: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        printf("Oops, there was an error in getting the two numbers! Let's try again.\n");
        fflush(stdin);
        main();
    } else {
        result = num1 + num2;
        printf("The result of adding %d and %d is: %d \n", num1, num2, result);
    }
    
    printf("Now let's try to divide a number by zero! Enter any number: ");
    if(scanf("%d", &num1) != 1) {
        printf("Uh oh, we couldn't get a number! Let's start over.\n");
        fflush(stdin);
        main();
    } else {
        if(num1 == 0) {
            printf("ERROR: Cannot divide by zero!\n");
            exit(1);
        }
        result = 100 / num1;
        printf("The result of dividing 100 by %d is: %d \n", num1, result);
    }

    printf("Thanks for using our cheerful error handling example program!\n");

    return 0;
}