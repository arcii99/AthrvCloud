//FormAI DATASET v1.0 Category: Digital signal processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    
    // Initialize input and output buffers
    float input_buffer[BUFFER_SIZE];
    float output_buffer[BUFFER_SIZE];
    
    // Initialize coefficients
    float coef_a[3] = {1.0, -1.5, 0.7};
    float coef_b[3] = {0.2, 0.1, -0.3};
    
    // Initialize state variables
    float state_x[2] = {0.0, 0.0};
    float state_y[2] = {0.0, 0.0};
    
    // Initialize time for generating random input signal
    srand(time(NULL));
    float t = 0.0;
    float dt = 1.0 / SAMPLE_RATE;
    
    // Asynchronous processing loop
    while(1) {
        
        // Generate random input signal
        for(int i = 0; i < BUFFER_SIZE; i++) {
            input_buffer[i] = 0.5 * ((float) rand() / (float) RAND_MAX) - 0.25;
            t += dt;
        }
        
        // Apply digital filter
        for(int i = 0; i < BUFFER_SIZE; i++) {
            float x = input_buffer[i];
            float y = coef_b[0] * x + coef_b[1] * state_x[0] + coef_b[2] * state_x[1] 
                    - coef_a[1] * state_y[0] - coef_a[2] * state_y[1];
            
            state_x[1] = state_x[0];
            state_x[0] = x;
            state_y[1] = state_y[0];
            state_y[0] = y;
            
            output_buffer[i] = y;
        }
        
        // Do some processing with the output buffer
        // Here we simply print the maximum value
        float max_output = 0.0;
        for(int i = 0; i < BUFFER_SIZE; i++) {
            if(output_buffer[i] > max_output)
                max_output = output_buffer[i];
        }
        printf("Max output: %f\n", max_output);
    }
    
    return 0;
}