//FormAI DATASET v1.0 Category: Audio processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440
#define AMPLITUDE 0.5

// Create a wave signal with the given frequency, amplitude and duration
void generate_sine_wave(float frequency, float amplitude, float duration, float waveform[]){
    float time_step = 1.0 / SAMPLE_RATE;
    float phase_step = 2.0 * M_PI * frequency * time_step;
    float phase = 0.0;

    int num_samples = (int)(duration * SAMPLE_RATE);

    for(int i = 0; i < num_samples; i++) {
        waveform[i] = amplitude * sin(phase);
        phase += phase_step;
    }
}

// Normalize the given waveform
void normalize_waveform(float waveform[], int num_samples){
    float max_amplitude = 0.0;

    for(int i = 0; i < num_samples; i++){
        if(fabs(waveform[i]) > max_amplitude){
            max_amplitude = fabs(waveform[i]);
        }
    }

    for(int i = 0; i < num_samples; i++){
        waveform[i] /= max_amplitude;
    }
}

// Play the given waveform
void play_waveform(float waveform[], int num_samples){
    FILE *output_file;
    output_file = fopen("audio.pcm", "wb");

    for(int i = 0; i < num_samples; i++){
        float sample = waveform[i] * AMPLITUDE;
        fwrite(&sample, sizeof(float), 1, output_file);
    }

    fclose(output_file);

    char command[1024];
    sprintf(command, "ffplay -autoexit -f f32le -ar %d audio.pcm", SAMPLE_RATE);
    system(command);
}

int main(){
    float waveform[SAMPLE_RATE];

    // Generate a 1 second sine wave signal
    generate_sine_wave(FREQUENCY, 1.0, 1.0, waveform);

    // Normalize the waveform
    normalize_waveform(waveform, SAMPLE_RATE);

    // Play the waveform
    play_waveform(waveform, SAMPLE_RATE);

    return 0;
}