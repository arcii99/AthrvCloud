//FormAI DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELAY_LENGTH 3
#define FILTER_ORDER 2

/* Filter coefficients */
const float b[FILTER_ORDER + 1] = {0.25, 0.5, 0.25};
const float a[FILTER_ORDER + 1] = {1, -0.6, 0.08};

/* Delay buffer */
float delay_buffer[DELAY_LENGTH];

/* Initialize delay buffer to zero */
void init_delay_buffer() {
    for(int i = 0; i < DELAY_LENGTH; i++) {
        delay_buffer[i] = 0;
    }
}

/* FIR Filter using provided coefficients */
float FIR_filter(float input) {
    float output = 0;
    /* Shift delay buffer by one */
    for(int i = DELAY_LENGTH - 1; i >= 1; i--) {
        delay_buffer[i] = delay_buffer[i-1];
    }
    /* Add new input to delay buffer */
    delay_buffer[0] = input;
    /* Calculate filter output */
    for(int i = 0; i <= FILTER_ORDER; i++) {
        output += b[i] * delay_buffer[i];
    }
    return output;
}

/* IIR Filter using provided coefficients */
float IIR_filter(float input) {
    float output = 0;
    /* Shift delay buffer by one */
    for(int i = DELAY_LENGTH - 1; i >= 1; i--) {
        delay_buffer[i] = delay_buffer[i-1];
    }
    /* Add new input to delay buffer */
    delay_buffer[0] = input;
    /* Calculate filter output */
    for(int i = 0; i <= FILTER_ORDER; i++) {
        output += a[i] * delay_buffer[i];
    }
    return output;
}

/* Main program */
int main() {
    init_delay_buffer();
    float input_signal[100] = {0};
    float output_signal[100] = {0};
    /* Generate input signal */
    for(int i = 0; i < 100; i++) {
        input_signal[i] = sin(2 * M_PI * i / 10); //10 Hz sine wave as input signal
    }
    /* Process input using FIR filter */
    for(int i = 0; i < 100; i++) {
        output_signal[i] = FIR_filter(input_signal[i]);
    }
    /* Print filtered output */
    printf("FIR Filter Output: ");
    for(int i = 0; i < 100; i++) {
        printf("%f ", output_signal[i]);
    }
    printf("\n");
    init_delay_buffer(); //reset delay buffer
    /* Process input using IIR filter */
    for(int i = 0; i < 100; i++) {
        output_signal[i] = IIR_filter(input_signal[i]);
    }
    /* Print filtered output */
    printf("IIR Filter Output: ");
    for(int i = 0; i < 100; i++) {
        printf("%f ", output_signal[i]);
    }
    printf("\n");
    return 0;
}