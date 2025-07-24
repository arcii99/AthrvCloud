//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100   // Sampling frequency of input signal
#define SIGNAL_LENGTH 2048   // Length of input signal
#define WINDOW_LENGTH 512    // Length of window function
#define HOP_LENGTH 256       // Length of hop between windows

float hamming(int n, int N) {
    // Hamming window function
    return 0.54 - 0.46*cos(2*M_PI*n/(N-1));
}

int main(void) {
    // Generate input signal
    float input_signal[SIGNAL_LENGTH];
    for (int i=0; i<SIGNAL_LENGTH; i++) {
        input_signal[i] = sin(2*M_PI*1000*i/SAMPLE_RATE) + sin(2*M_PI*2000*i/SAMPLE_RATE);
    }
    
    // Apply window function
    float window[WINDOW_LENGTH];
    for (int i=0; i<WINDOW_LENGTH; i++) {
        window[i] = hamming(i, WINDOW_LENGTH);
    }
    
    // Compute STFT using fixed-length windows
    int num_windows = ceil((float)(SIGNAL_LENGTH-WINDOW_LENGTH)/HOP_LENGTH) + 1;
    float spectrogram[num_windows][WINDOW_LENGTH];
    for (int i=0; i<num_windows; i++) {
        float windowed_signal[WINDOW_LENGTH];
        for (int j=0; j<WINDOW_LENGTH; j++) {
            int sample_index = i*HOP_LENGTH + j;
            if (sample_index < SIGNAL_LENGTH) {
                windowed_signal[j] = input_signal[sample_index] * window[j];
            } else {
                windowed_signal[j] = 0;
            }
        }
        // Compute FFT of windowed signal
        for (int k=0; k<WINDOW_LENGTH; k++) {
            float re = 0, im = 0;
            for (int j=0; j<WINDOW_LENGTH; j++) {
                float angle = 2*M_PI*k*j/WINDOW_LENGTH;
                re += windowed_signal[j] * cos(angle);
                im -= windowed_signal[j] * sin(angle);
            }
            spectrogram[i][k] = sqrt(re*re + im*im);
        }
    }
    
    // Print out spectrogram (for debugging purposes)
    for (int i=0; i<num_windows; i++) {
        printf("[ ");
        for (int j=0; j<WINDOW_LENGTH; j++) {
            printf("%.3f ", spectrogram[i][j]);
        }
        printf("]\n");
    }
    
    return 0;
}