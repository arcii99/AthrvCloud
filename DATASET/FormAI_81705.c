//FormAI DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>

// Function to perform convolution
void convolution(int signal[], int signal_size, int kernel[], int kernel_size, int result[]) {
    int i, j, k;
    for(i=0; i<signal_size+kernel_size-1; i++) {
        result[i] = 0;
        for(j=0; j<kernel_size; j++) {
            k = i-j;
            if(k >= 0 && k < signal_size)
                result[i] += signal[k] * kernel[j];
        }
    }
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int signal_size = 5;
    int kernel[] = {1, 1, 1};
    int kernel_size = 3;
    int result[signal_size+kernel_size-1];
    convolution(signal, signal_size, kernel, kernel_size, result);
    int i;
    for(i=0; i<signal_size+kernel_size-1; i++)
        printf("%d ", result[i]);
    return 0;
}