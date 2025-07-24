//FormAI DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float Fs = 44100.0;    // Sampling frequency
    float duration = 5.0;  // Duration of the signal
    float f = 440.0;       // Frequency of the tone
    float A = 0.5;         // Amplitude of the tone
    
    int num_samples = (int) (duration * Fs); // Number of samples
    float *audio_buffer = (float*) malloc(num_samples * sizeof(float)); // Audio buffer

    // Generate the audio signal
    for(int i=0; i<num_samples; i++){
        float t = (float) i / Fs; // Time of the current sample
        audio_buffer[i] = A * sin(2 * M_PI * f * t);
    }

    // Apply a low-pass filter to the signal
    for(int i=1; i<num_samples; i++){
        audio_buffer[i] = 0.95 * audio_buffer[i-1] + 0.05 * audio_buffer[i];
    }

    // Apply a high-pass filter to the signal
    for(int i=1; i<num_samples; i++){
        audio_buffer[i] = audio_buffer[i] - 0.99 * audio_buffer[i-1];
    }

    // Print the processed audio signal
    for(int i=0; i<num_samples; i++){
        printf("%f\n", audio_buffer[i]);
    }

    free(audio_buffer); // Free the memory allocated for the audio buffer

    return 0;
}