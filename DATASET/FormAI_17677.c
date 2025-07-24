//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
/* This DSP program takes an input signal and performs signal shaping
 * by shifting the frequency components using a unique algorithm.
 * Input is a vector of size N, where N is a power of 2. Output is
 * also a vector of size N.
 */

#include <stdio.h>
#include <math.h>

#define N 64        // Input vector size

int main(){
    float input[N]; // Input signal vector
    float output[N];// Output signal vector
    float PI = 3.14159265;

    // Initialize input signal vector
    for(int i=0; i<N; i++)
        input[i] = sin(2 * PI * i / N);
  
    // Perform signal shaping
    for(int k=0; k<N; k++){
        float sum_real = 0;
        float sum_imag = 0;
        for(int n=0; n<N; n++){
            float arg = (2* PI * k * n) / N;
            float cos_arg = cos(arg);
            float sin_arg = sin(arg);
            sum_real += input[n] * cos_arg;
            sum_imag += input[n] * sin_arg;
        }
        float magnitude = sqrt(sum_real*sum_real + sum_imag*sum_imag);
        float phase = atan2(sum_imag, sum_real);
        float freq_shift = (float) k/N;
        phase += 2* PI * freq_shift;
        float output_real = magnitude * cos(phase);
        float output_imag = magnitude * sin(phase);
        output[k] = output_real;
    }

    // Print output signal vector
    for(int i=0; i<N; i++){
        printf("Output[%d] = %f\n", i, output[i]);
    }

    return 0;
}