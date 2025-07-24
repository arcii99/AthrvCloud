//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define MIN_NUM 1

int main() {

    //Initialize the random number generator
    srand(time(NULL));

    //Declare variables for the input and result
    int num1, num2, result;

    //Get the user input
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    //Perform arithmetic operations
    result = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, result);

    result = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, result);

    result = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, result);

    if(num2 == 0) {
        printf("Cannot divide by zero!\n");
    } else {
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
    }

    //Generate a random number and perform modulo operation
    int randomNum = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    result = num1 % randomNum;
    printf("%d %% %d = %d\n", num1, randomNum, result);

    return 0;
}