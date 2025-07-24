//FormAI DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

/* Function to perform division */
float divide(int num, int den){
    if(den == 0){
        fprintf(stderr, "Error: Divide by zero!\n");
        exit(EXIT_FAILURE);
    }
    return (float)num / (float)den;
}

/* Main function */
int main(){
    int num, den;

    /* Taking input from user */
    printf("Enter numerator: ");
    scanf("%d", &num);

    printf("Enter denominator: ");
    scanf("%d", &den);

    /* Error handling */
    if(num < 0 || den < 0){
        fprintf(stderr, "Error: Negative values not allowed!\n");
        exit(EXIT_FAILURE);
    }

    /* Calling function */
    float result = divide(num, den);

    /* Displaying output */
    printf("%d / %d = %f\n", num, den, result);

    return 0;
}