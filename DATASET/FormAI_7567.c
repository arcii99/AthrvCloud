//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>

/* Function to perform moving average filtering on an input signal */
void moving_average_filter(int *input_signal, int input_length, int *output_signal, int window_size) {
    
    int i, j, window_sum, window_start, window_end;
    
    /* Initialize window sum and window start and end indices */
    window_sum = 0;
    window_start = 0;
    window_end = window_size - 1;
    
    /* Calculate the first output value using the initial window */
    for (i = window_start; i <= window_end; i++) {
        window_sum += input_signal[i];
    }
    output_signal[0] = window_sum / window_size;
    
    /* Update window sum and move window for each subsequent output value */
    for (i = 1; i < input_length - window_size + 1; i++) {
        window_sum -= input_signal[i - 1];
        window_sum += input_signal[i + window_size - 1];
        output_signal[i] = window_sum / window_size;
    }
}

int main() {
    
    int input_signal[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int input_length = sizeof(input_signal) / sizeof(input_signal[0]);
    int output_signal[input_length];
    int window_size = 3;
    int i;
    
    /* Call moving average filter function and print output signal */
    moving_average_filter(input_signal, input_length, output_signal, window_size);
    printf("Input signal: ");
    for (i = 0; i < input_length; i++) {
        printf("%d ", input_signal[i]);
    }
    printf("\nOutput signal: ");
    for (i = 0; i < input_length - window_size + 1; i++) {
        printf("%d ", output_signal[i]);
    }
    printf("\n");
    
    return 0;
}