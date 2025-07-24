//FormAI DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>

int main() {
    int num1 = 5, num2 = 10;
    int sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    char myString[] = "Hello, world!";
    int stringLength = sizeof(myString) / sizeof(myString[0]);
    printf("The length of the string \"%s\" is %d\n", myString, stringLength);

    float pi = 3.14159;
    printf("The value of pi is approximately %f\n", pi);

    int userInput;
    printf("Please enter a number: ");
    scanf("%d", &userInput);
    printf("The user entered the number %d.\n", userInput);

    return 0;
}