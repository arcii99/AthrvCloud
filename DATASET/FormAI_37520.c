//FormAI DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define SAMPLING_FREQUENCY 44100
#define BIT_DEPTH 16
#define MAX_AMPLITUDE 32767 // 2^(BIT_DEPTH-1) - 1

int main() {

    // Create a sawtooth waveform
    double frequency = 440.0; // A4
    double wavelength = SAMPLING_FREQUENCY / frequency;
    double amplitude = MAX_AMPLITUDE * 0.5;
    double phase = 0.0;
    double wave_data[10000];
    int num_samples = (int) wavelength;
    for (int i = 0; i < num_samples; i++) {
        double sample = amplitude - (amplitude / (wavelength / 2)) * fmod((double) i, (wavelength / 2));
        wave_data[i] = sample;
    }
    
    // Apply a low-pass filter
    double cutoff_frequency = 1000.0; // Hz
    double normalized_cutoff_frequency = 2.0 * M_PI * cutoff_frequency / SAMPLING_FREQUENCY;
    double filter_alpha = 1.0 - exp(-normalized_cutoff_frequency);
    double filtered_data[10000];
    filtered_data[0] = wave_data[0];
    for (int i = 1; i < num_samples; i++) {
        double filtered_sample = filtered_data[i-1] + filter_alpha * (wave_data[i] - filtered_data[i-1]);
        filtered_data[i] = filtered_sample;
    }
    
    // Apply amplitude modulation
    double mod_frequency = 5.0; // Hz
    double mod_amplitude = 0.5;
    double modulated_data[10000];
    for (int i = 0; i < num_samples; i++) {
        double modulator = amplitude * mod_amplitude * sin(2.0 * M_PI * mod_frequency * ((double) i / SAMPLING_FREQUENCY));
        modulated_data[i] = (filtered_data[i] + modulator) * 0.5;
    }
    
    // Apply a gain envelope
    double attack_time = 100.0; // ms
    double decay_time = 500.0; // ms
    int attack_samples = (int) (attack_time * 0.001 * SAMPLING_FREQUENCY);
    int decay_samples = (int) (decay_time * 0.001 * SAMPLING_FREQUENCY);
    double envelope[10000];
    for (int i = 0; i < num_samples; i++) {
        if (i < attack_samples) {
            envelope[i] = (((double) i) / attack_samples) * MAX_AMPLITUDE;
        } else if ((i >= attack_samples) && (i < (attack_samples + decay_samples))) {
            envelope[i] = MAX_AMPLITUDE - ((((double) i) - attack_samples) / decay_samples) * MAX_AMPLITUDE;
        } else {
            envelope[i] = 0.0;
        }
        modulated_data[i] = modulated_data[i] * (envelope[i] / MAX_AMPLITUDE);
    }
    
    // Output to file
    FILE *output_file;
    output_file = fopen("audio.wav", "w");
    fprintf(output_file, "RIFF");
    int chunk_size = 36 + (2 * num_samples);
    fwrite(&chunk_size, 4, 1, output_file);
    fprintf(output_file, "WAVEfmt ");
    int subchunk1_size = 16;
    fwrite(&subchunk1_size, 4, 1, output_file);
    short audio_format = 1;
    fwrite(&audio_format, 2, 1, output_file);
    short num_channels = 1;
    fwrite(&num_channels, 2, 1, output_file);
    int sample_rate = SAMPLING_FREQUENCY;
    fwrite(&sample_rate, 4, 1, output_file);
    int byte_rate = sample_rate * num_channels * (BIT_DEPTH / 8);
    fwrite(&byte_rate, 4, 1, output_file);
    short block_align = num_channels * (BIT_DEPTH / 8);
    fwrite(&block_align, 2, 1, output_file);
    short bits_per_sample = BIT_DEPTH;
    fwrite(&bits_per_sample, 2, 1, output_file);
    fprintf(output_file, "data");
    fwrite(&num_samples, 4, 1, output_file);
    for (int i = 0; i < num_samples; i++) {
        short audio_sample = (short) modulated_data[i];
        fwrite(&audio_sample, 2, 1, output_file);
    }
    fclose(output_file);
    
    return 0;
}