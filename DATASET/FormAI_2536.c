//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* A high-energy error handling program */

int main() {

    int num1, num2, result;
    
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);
    
    if(num2 == 0) { // Checking if denominator is zero
        printf("Oh no, division by zero is not possible!\n");
        exit(0); // Exiting program gracefully
    }
    
    /*Verbose calculations*/
    result = num1 / num2;
    
    printf("%d / %d = %d\n", num1, num2, result);
    
    printf("Thanks for using the program.\n");
    
    return 0;
}