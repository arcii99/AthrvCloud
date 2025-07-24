//FormAI DATASET v1.0 Category: Digital signal processing ; Style: lively
#include <stdio.h>

int main() {
    printf("Hello there! Welcome to my unique Digital Signal Processing example program!\n");
    printf("In this program, we'll be implementing a low-pass filter using a moving average approach.\n");
    
    float signal[10] = {5.0, 3.0, 2.0, 7.0, 1.0, 9.0, 4.0, 8.0, 6.0, 10.0};
    float filtered_signal[10];
    int window_size = 3;
    
    for (int i = 0; i < 10; i++) {
        float sum = 0.0;
        for (int j = i - window_size + 1; j <= i; j++) {
            if (j >= 0) {
                sum += signal[j];
            }
        }
        filtered_signal[i] = sum / window_size;
    }
    
    printf("\nOriginal signal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", signal[i]);
    }
    
    printf("\nFiltered signal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", filtered_signal[i]);
    }
    
    printf("\n\nAnd there you have it! A simple implementation of a low-pass filter using a moving average approach.\n");
    printf("Feel free to play around with the window size and see how it affects the filtered signal!\n");
    
    return 0;
}