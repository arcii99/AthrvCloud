//FormAI DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 16000 // number of samples in our audio file
#define SAMPLE_RATE 8000  // number of samples per second

int main() {
    // generate a sine wave audio signal
    int i;
    short audio[NUM_SAMPLES];
    float frequency = 440; // in Hz
    float amplitude = 32767; // max amplitude of a 16-bit stereo audio signal
    float phase = 0;
    float phase_increment = 2*M_PI*frequency/SAMPLE_RATE;

    for (i = 0; i < NUM_SAMPLES; i++) {
        audio[i] = (short)(amplitude*sin(phase));
        phase += phase_increment;
    }

    // write audio data to a file
    FILE *f;
    f = fopen("sine_wave.pcm", "wb");
    fwrite(audio, sizeof(audio[0]), NUM_SAMPLES, f);
    fclose(f);

    // read audio data from file
    short audio_in[NUM_SAMPLES];
    f = fopen("sine_wave.pcm", "rb");
    fread(audio_in, sizeof(audio_in[0]), NUM_SAMPLES, f);
    fclose(f);

    // apply a low-pass filter to the audio signal
    float cutoff = 500; // frequency in Hz
    float RC = 1.0/(2*M_PI*cutoff);
    float dt = 1.0/SAMPLE_RATE;
    float alpha = dt/(RC+dt);
    float filtered_audio[NUM_SAMPLES];
    float prev_sample = 0;

    for (i = 0; i < NUM_SAMPLES; i++) {
        filtered_audio[i] = alpha*audio_in[i] + (1-alpha)*prev_sample;
        prev_sample = filtered_audio[i];
    }

    // write filtered audio data to a file
    f = fopen("sine_wave_filtered.pcm", "wb");
    fwrite(filtered_audio, sizeof(filtered_audio[0]), NUM_SAMPLES, f);
    fclose(f);

    return 0;
}