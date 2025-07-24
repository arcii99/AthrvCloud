//FormAI DATASET v1.0 Category: Recursive ; Style: modular
#include<stdio.h>

int factorial(int number){
    if(number == 0)
        return 1;
    else
        return number * factorial(number-1);
}

int fibonacci(int number){
    if(number == 0 || number == 1)
        return number;
    else
        return fibonacci(number-1) + fibonacci(number-2);
}

int main(){
    int number, choice;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    printf("Enter 1 to find Factorial or 2 to find Fibonacci: ");
    scanf("%d", &choice);
    if(choice == 1)
        printf("Factorial of %d is: %d", number, factorial(number));
    else
        printf("Fibonacci number at %dth position is: %d", number, fibonacci(number));
    return 0;
}