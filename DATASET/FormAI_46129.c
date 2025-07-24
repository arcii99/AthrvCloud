//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>

// Declare function for filtering signal
void filterSignal(double signal[], double filteredSignal[], int n) {
    double b[4] = {0.1, 0.2, 0.3, 0.4}; // Filter coefficients
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            if (i-j >= 0) {
                filteredSignal[i] += b[j] * signal[i-j];
            }
        }
    }
}

int main() {
    double signal[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}; // Input signal
    double filteredSignal[10] = {0}; // Initialize filtered signal as all zeros
    filterSignal(signal, filteredSignal, 10); // Filter signal
    int i;
    // Print input and filtered signals
    for (i = 0; i < 10; i++) {
        printf("%f\t%f\n", signal[i], filteredSignal[i]);
    }
    return 0;
}