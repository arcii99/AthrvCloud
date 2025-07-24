//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
//Here's a fun and cheerful recursive program to calculate the factorial of a number!

#include <stdio.h>

int factorial(int n) {
    //base case
    if(n==0) {
        return 1;
    }
    else {
        //recursive case
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Hello there! Let's calculate the factorial of a number!\n");
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    //check if user input is valid
    if(num<0) {
        printf("Oops! That's not a positive integer! Let's try again.\n");
        main(); //recursive call to main function
    }
    else {
        int result = factorial(num);
        printf("The factorial of %d is %d. Yay, we did it!", num, result);
    }
    
    return 0;
}