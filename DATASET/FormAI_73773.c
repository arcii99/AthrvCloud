//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440
#define AMPLITUDE 0.5

int main() {
    // create an array to hold our audio samples
    float audio_samples[SAMPLE_RATE];

    // generate a sine wave at the desired frequency
    for (int i = 0; i < SAMPLE_RATE; i++) {
        audio_samples[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE);
    }

    // apply a low-pass filter to the audio
    float filter_coefficients[6] = {0.001459, 0.007295, 0.014591, 0.014591, 0.007295, 0.001459};
    float filtered_samples[SAMPLE_RATE] = {0};
    for (int i = 5; i < SAMPLE_RATE; i++) {
        for (int j = 0; j < 6; j++) {
            filtered_samples[i] += filter_coefficients[j] * audio_samples[i-j];
        }
    }

    // normalize the audio samples
    float max_amplitude = 0;
    for (int i = 0; i < SAMPLE_RATE; i++) {
        if (fabs(filtered_samples[i]) > max_amplitude) {
            max_amplitude = fabs(filtered_samples[i]);
        }
    }
    for (int i = 0; i < SAMPLE_RATE; i++) {
        filtered_samples[i] /= max_amplitude;
    }

    // write the audio samples to a WAV file
    FILE *wav_file = fopen("output.wav", "wb");
    int16_t int_samples[SAMPLE_RATE];
    for (int i = 0; i < SAMPLE_RATE; i++) {
        int_samples[i] = (int16_t) (filtered_samples[i] * 32767);
    }
    fwrite(&int_samples, sizeof(int16_t), SAMPLE_RATE, wav_file);
    fclose(wav_file);

    printf("Audio processing complete. Check output.wav for the result.");

    return 0;
}