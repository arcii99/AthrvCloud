//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int signal[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Sample signal
    int coefficients[3] = {1, -2, 1}; // Simple averaging filter
    int filtered_signal[10]; // Filtered output signal
    
    printf("Original signal: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", signal[i]);
    }
    printf("\n\n");
    
    // Convolve signal with filter coefficients
    for(int i = 0; i < 10; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            if(i+j-1 >= 0 && i+j-1 < 10) {
                sum += signal[i+j-1] * coefficients[j];
            }
        }
        filtered_signal[i] = sum;
    }
    
    printf("Filtered signal: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", filtered_signal[i]);
    }
    printf("\n");
    
    return 0;
}