//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b){
    if(b == 0){
        printf("Whoops! Dividing by zero is not allowed. Let's try something else.\n");
        return -1; // Return a negative number to indicate an error occurred
    }
    return (a/b);
}

int main(){
    int a, b, result;

    printf("Hello there! I'm your friendly calculator program. Let's do some math!\n\n");

    printf("Please enter the first number: ");
    scanf("%d", &a);

    printf("Please enter the second number: ");
    scanf("%d", &b);

    result = divide(a, b);

    if(result < 0){
        printf("Oh no! An error occurred while dividing. Let's try again with new numbers.\n");
    } else{
        printf("The result of %d divided by %d is %d.\n", a, b, result);
    }

    printf("\nThank you for using our cheerful calculator program. Have a nice day!\n");
    
    return 0;
}