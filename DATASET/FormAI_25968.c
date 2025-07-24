//FormAI DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our protected function with "static" access modifier
static void convolution(int signal[], int signal_size, int kernel[], int kernel_size, int result[]) {
    int i, j;

    // Pad the signal with zeros
    for(i = 0; i < kernel_size - 1; i++) {
        signal[-i - 1 + signal_size] = 0;
    }

    // Convolve the signal with the kernel
    for(i = 0; i < signal_size; i++) {
        result[i] = 0;
        for(j = 0; j < kernel_size; j++) {
            result[i] += signal[i - j + kernel_size - 1] * kernel[j];
        }
    }
}

// Main function
int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int signal_size = 5;
    int kernel[] = {1, 2, 1};
    int kernel_size = 3;
    int result[signal_size];
    int i;

    // Call the protected "convolution" function
    convolution(signal, signal_size, kernel, kernel_size, result);

    // Print the result
    printf("Result: ");
    for(i = 0; i < signal_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}