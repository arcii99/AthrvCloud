//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* Digital signal processing example program */

int main() {
    // Initialize variables
    int n, k;
    float X[n], Y[k], b0, b1, b2, a1, a2;

    // Prompt user for input
    printf("Enter the length of X[n]: ");
    scanf("%d", &n);

    printf("Enter the length of Y[k]: ");
    scanf("%d", &k);

    printf("Enter the values of X[n]: ");
    for(int i=0; i<n; i++) {
        scanf("%f", &X[i]);
    }

    // Calculate the filter coefficients
    b0 = 1.0;
    b1 = -1.6017;
    b2 = 0.9950;
    a1 = 1.0;
    a2 = -0.9950;

    // Apply the filter to the input signal
    for(int i=0; i<k; i++) {
        Y[i] = b0*X[i] + b1*X[i-1] + b2*X[i-2] - a1*Y[i-1] - a2*Y[i-2];
    }

    // Output the filtered signal
    printf("The filtered signal Y[k] is: ");
    for(int i=0; i<k; i++) {
        printf("%f ", Y[i]);
    }

    return 0;
}