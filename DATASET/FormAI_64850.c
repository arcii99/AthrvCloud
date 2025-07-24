//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

int factorial(int n){

    // base case
    if (n == 1){
        printf("Reached the base case. \n");
        return 1;
    }
    else {
        printf("Recursing with n = %d. \n", n-1);
        return n * factorial(n - 1);
    }
}

int main() {

    int n = 5;
    printf("The factorial of %d is %d. \n", n, factorial(n));

    // Your turn to explore!
    printf("Do you want to try a different value of n? (y/n) \n");
    char input;
    scanf("%c", &input);

    if (input == 'y'){
        printf("Great! Enter your positive integer value for n: \n");
        int new_n;
        scanf("%d", &new_n);

        printf("The factorial of %d is %d. \n", new_n, factorial(new_n));
    }
    else if (input == 'n'){
        printf("No problem! Thanks for trying out the program. \n");
    }
    else {
        printf("Oops! Invalid input. \n");
    }

    return 0;
}