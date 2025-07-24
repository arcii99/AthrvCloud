//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int sample_rate = 44100; // sample rate in Hz
    int duration = 5; // duration of audio in seconds
    int samples = sample_rate * duration; // total number of samples
    double frequency = 440.0; // frequency of sine wave in Hz
    double amplitude = 0.5; // amplitude of sine wave (between 0 and 1)
    
    // allocate memory for audio buffer
    double *audio_buffer = malloc(samples * sizeof(double));
    
    // fill audio buffer with sine wave
    for (int i = 0; i < samples; i++) {
        double time = (double)i / sample_rate;
        double value = amplitude * sin(2 * M_PI * frequency * time);
        audio_buffer[i] = value;
    }
    
    // write audio buffer to file
    FILE *file = fopen("output.raw", "wb");
    fwrite(audio_buffer, sizeof(double), samples, file);
    fclose(file);
    
    // free memory
    free(audio_buffer);
    
    return 0;
}