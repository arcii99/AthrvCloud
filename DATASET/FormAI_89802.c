//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

float get_autocorrelation(float signal[], int len, int delay) {
    float sum = 0;
    for (int i = 0; i < len - delay; i++) {
        sum += signal[i] * signal[i + delay];
    }
    return sum / (float) len;
}

void paranoid_dsp(float signal[], int len) {
    float autocorrelation[len];
    for (int i = 0; i < len; i++) {
        autocorrelation[i] = get_autocorrelation(signal, len, i);
    }
    float max = autocorrelation[0];
    int max_index = 0;
    for (int i = 1; i < len; i++) {
        if (autocorrelation[i] > max) {
            max = autocorrelation[i];
            max_index = i;
        }
    }
    float frequency = 1.0 / (float) max_index;
    float phase = atan2f(signal[max_index], signal[0]);
    float amplitude = sqrt(signal[0] * signal[0] + signal[max_index] * signal[max_index]);
    printf("Detected frequency: %f Hz\n", frequency);
    printf("Detected phase: %f rad\n", phase);
    printf("Detected amplitude: %f\n", amplitude);
}

int main() {
    float signal[] = {
        0.5, 0.7, 1.0, 0.9, 0.6, 0.3, -0.1, -0.3, -0.5, -0.3, 
        -0.1, 0.1, 0.3, 0.2, 0.0, -0.2, -0.4, -0.3, -0.1, 0.1
    };
    paranoid_dsp(signal, 20);
    return 0;
}