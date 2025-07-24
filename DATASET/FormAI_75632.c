//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

/* This program calculates the sum of the integers between two user-defined values. */

int main() {

    /* Declare variables to store input and output */
    int num1, num2, sum = 0;
    
    /* Prompt user for input */
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    
    /* Determine which number is smaller */
    if(num1 < num2) {
        /* Calculate the sum of the integers between num1 and num2 */
        for(int i = num1 + 1; i < num2; i++) {
            sum += i;
        }
    } else {
        /* Calculate the sum of the integers between num2 and num1 */
        for(int i = num2 + 1; i < num1; i++) {
            sum += i;
        }
    }
    
    /* Print the result to the console */
    printf("The sum of the integers between %d and %d is: %d", num1, num2, sum);
    
    /* Exit the program */
    return 0;
}