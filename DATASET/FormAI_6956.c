//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int frequency = 1000; // first frequency
    int sample_rate = 48000; // sample rate of 48kHz
    int duration = 3000; // duration of 3 seconds
    int amplitude = 5000; // amplitude of waveform
    
    int N = sample_rate * duration / 1000; // number of samples
    
    float fn = frequency / (float)sample_rate; // normalized frequency
    
    // Initialize array to store samples
    int waveform[N];
    
    for (int n = 0; n < N; n++) {
        // Generate sine wave using normalized frequency
        waveform[n] = amplitude * sin(2 * PI * fn * n);
    }
    
    // Implement low-pass filter
    float cutoff_freq = 300 / (float)sample_rate; // normalized cutoff frequency
    float alpha = sin(PI * cutoff_freq) / (2 * PI);
    float beta = 1 - alpha;
    
    int output[N];
    output[0] = waveform[0];
    
    for (int n = 1; n < N; n++) {
        output[n] = round(beta * output[n-1] + alpha * waveform[n]);
    }
    
    // Print filtered waveform
    printf("Filtered waveform:\n");
    for (int n = 0; n < N; n++) {
        printf("%d\n", output[n]);
    }
    
    return 0;
}