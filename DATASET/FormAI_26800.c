//FormAI DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

void printArray(double array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void firFilter(double input[], double output[], double coefficients[], int n) {
    for (int i = 0; i < n; i++) {
        output[i] = 0;
        for (int j = 0; j <= i; j++) {
            if (i - j < N) {
                output[i] += input[j] * coefficients[i - j];
            }
        }
    }
}

int main() {
    double input[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    double coefficients[] = {0.1, 0.15, 0.2, 0.25, 0.1, 0.05, 0.05, 0.03, 0.02, 0.01};
    double output[N];
    firFilter(input, output, coefficients, N);
    printf("Input: ");
    printArray(input, N);
    printf("Coefficients: ");
    printArray(coefficients, N);
    printf("Output: ");
    printArray(output, N);
    return 0;
}