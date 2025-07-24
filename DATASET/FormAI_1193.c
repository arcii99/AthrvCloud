//FormAI DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>

#define N 8

int main() {
    int signal_in[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    int signal_out[N];
    int i;

    // Filtering operation
    for(i = 0; i < N; i++) {
        if(i == 0) {
            signal_out[i] = (signal_in[i] + signal_in[i+1]) / 2;
        } else if(i == N-1) {
            signal_out[i] = (signal_in[i] + signal_in[i-1]) / 2;
        } else {
            signal_out[i] = (signal_in[i-1] + signal_in[i] + signal_in[i+1]) / 3;
        }
    }

    // Print original signal and filtered signal
    printf("Original Signal: ");
    for(i = 0; i < N; i++) {
        printf("%d ", signal_in[i]);
    }

    printf("\nFiltered Signal: ");
    for(i = 0; i < N; i++) {
        printf("%d ", signal_out[i]);
    }

    return 0;
}