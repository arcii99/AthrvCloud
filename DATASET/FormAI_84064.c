//FormAI DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    // Define input and output signals
    float input_signal[512];
    float output_signal[512];
    
    // Generate input signal as a sine wave
    for(int i=0; i<512; i++) {
        input_signal[i] = sin(2 * PI * i / 64) + sin(2 * PI * i / 128) + sin(2 * PI * i / 256);
    }
    
    // Apply a high-pass filter
    float filter_coeffs[6] = {0.1353353, -0.541341, 0.541341, -0.1353353, 0, 0};
    float filter_states[4] = {0, 0, 0, 0};
    for(int i=0; i<512; i++) {
        // Shift states
        filter_states[3] = filter_states[2];
        filter_states[2] = filter_states[1];
        filter_states[1] = filter_states[0];
        // Update state with new input
        filter_states[0] = input_signal[i];
        // Apply filter
        output_signal[i] = filter_coeffs[0] * filter_states[0] + filter_coeffs[1] * filter_states[1] +
                            filter_coeffs[2] * filter_states[2] + filter_coeffs[3] * filter_states[3] +
                            filter_coeffs[4] * output_signal[i-1] + filter_coeffs[5] * output_signal[i-2];
    }
    
    // Print output signal
    for(int i=0; i<512; i++) {
        printf("%f\n", output_signal[i]);
    }
    
    return 0;
}