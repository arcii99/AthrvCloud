//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 16 // number of samples

int main()
{

    float input_signal[N], output_signal[N];
    float hamming_window[N]; // Hamming window function
    
    // Generate input signal
    for(int i=0; i<N; i++){
        input_signal[i] = sin((2*M_PI / N) * i);
        output_signal[i] = 0;
    }
    
    // Generate Hamming window
    for(int i=0; i<N; i++){
        hamming_window[i] = 0.54 - (0.46*cos((2*M_PI*i) / (N-1)));
    }
    
    // Apply discrete Fourier transform
    for(int k=0; k<N; k++){
        
        float real_sum = 0, imag_sum = 0;
        
        for(int n=0; n<N; n++){
            float current_signal = input_signal[n] * hamming_window[n];
            float angle = 2*M_PI*n*k/N;
            real_sum += current_signal * cos(angle);
            imag_sum += current_signal * sin(angle);

        }
        
        output_signal[k] = sqrt(pow(real_sum,2) + pow(imag_sum,2));
    }
    
    // Print the output signal
    printf("Output Signal:\n");
    for(int i=0; i<N; i++){
        printf("%f\n", output_signal[i]);
    }
    
    return 0;
}