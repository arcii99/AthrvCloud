//FormAI DATASET v1.0 Category: Audio processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 8192

/* Create a low pass filter */
void apply_lp_filter(float *data, float cutoff_freq, float resonance) {
    float c = 1.0 / tanf(M_PI * cutoff_freq / SAMPLE_RATE);
    float a1 = 1.0 / (1.0 + resonance*c + c*c);
    float a2 = 2*a1;
    float a3 = a1;
    float b1 = 2.0 * (1.0 - c*c) * a1;
    float b2 = (1.0 - resonance*c + c*c) * a1;
    
    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;

    /* Apply filter to input data */
    for (int i = 0; i < NUM_SAMPLES; i++) {
        float x = data[i];

        float y = a1*x + a2*x1 + a3*x2 - b1*y1 - b2*y2;

        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;

        data[i] = y;
    }
}

int main() {
    /* Generate 1kHz sine wave */
    float data[NUM_SAMPLES];

    for (int i = 0; i < NUM_SAMPLES; i++) {
        data[i] = sinf(2.0 * M_PI * 1000.0 * i / SAMPLE_RATE);
    }

    /* Apply low pass filter with cutoff at 500Hz and resonance of 0.7 */
    apply_lp_filter(data, 500, 0.7);

    /* Output processed data */
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%f\n", data[i]);
    }

    return 0;
}