//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// This function returns the reciprocal of a given number
double reciprocal(double num) {
    if(num == 0) {
        errno = ERANGE;
        return 0;
    } else {
        return 1 / num;
    }
}

int main() {
    double num, rec;
    
    // Ask user for input
    printf("Enter a number: ");
    scanf("%lf", &num);
    
    // Calculate the reciprocal of the input number
    rec = reciprocal(num);
    
    // Check for errors and handle them accordingly
    if(errno == ERANGE) {
        printf("\nError: Entered number is zero. Cannot calculate reciprocal.\n");
    } else {
        printf("\nThe reciprocal of %.2f is %.2f\n", num, rec);
    }
    
    return 0;
}