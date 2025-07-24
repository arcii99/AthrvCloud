//FormAI DATASET v1.0 Category: Log analysis ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the base 2 logarithm of a given number
double calculateLogarithm(double x) {
    return log(x)/log(2);
}

int main() {
    int numLogs; // The number of logs to be calculated
    printf("Welcome to the logarithm calculator! \n\n");

    // Taking the input for the number of logs to be calculated
    printf("Enter the number of logs you want to calculate: ");
    scanf("%d", &numLogs);

    // Creating an array to store the numbers whose logs need to be calculated
    double* numArray = (double*)malloc(numLogs * sizeof(double));
    if(numArray == NULL) {
        printf("Error: Unable to allocate memory. Please try again later.");
        return -1;
    }

    // Taking input of the numbers whose logs need to be calculated and storing them in the array
    for(int i=0; i<numLogs; i++) {
        printf("Enter value %d : ", i+1);
        scanf("%lf", &numArray[i]);
    }

    // Calculating the logs of the numbers using the calculateLogarithm function and displaying the results
    for(int i=0; i<numLogs; i++) {
        printf("The base 2 logarithm of %lf is %lf \n", numArray[i], calculateLogarithm(numArray[i]));
    }

    // Freeing the memory allocated to the array
    free(numArray);

    return 0;
}