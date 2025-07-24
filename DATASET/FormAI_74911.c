//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>

#define NUM_SAMPLES 1024
#define PI 3.14159265358979323846

// Generate 1 kHz sine wave at 44.1kHz sample rate
float signal[NUM_SAMPLES];

void generate_signal() {
    for(int i = 0; i < NUM_SAMPLES; i++) {
        signal[i] = sin(2.0 * PI * 1000.0 * i / 44100.0);
    }
}

// Apply Blackman Window to signal
float windowed_signal[NUM_SAMPLES];

void apply_window() {
    float a0, a1, a2;
    for(int i = 0; i < NUM_SAMPLES; i++) {
        a0 = 0.42;
        a1 = 0.5 - 0.5 * cos(2.0 * PI * i / (NUM_SAMPLES - 1));
        a2 = 0.08 * cos(4.0 * PI * i / (NUM_SAMPLES - 1));
        windowed_signal[i] = signal[i] * (a0 - a1 + a2);
    }
}

// Apply FFT to windowed signal
float fft_real[NUM_SAMPLES];
float fft_imag[NUM_SAMPLES];

void apply_fft() {
    // Initialize real and imaginary components
    for(int i = 0; i < NUM_SAMPLES; i++) {
        fft_real[i] = windowed_signal[i];
        fft_imag[i] = 0.0;
    }

    // Perform FFT using Cooley-Tukey algorithm
    int n = NUM_SAMPLES;
    for(int k = n; k > 1; k /= 2) {
        for(int i = 0; i < k / 2; i++) {
            float w_r = cos(2.0 * PI * i / k);
            float w_i = sin(2.0 * PI * i / k);
            for(int j = i; j < n; j += k) {
                int l = j + k / 2;
                float t_r = w_r * fft_real[l] - w_i * fft_imag[l];
                float t_i = w_r * fft_imag[l] + w_i * fft_real[l];
                fft_real[l] = fft_real[j] - t_r;
                fft_imag[l] = fft_imag[j] - t_i;
                fft_real[j] += t_r;
                fft_imag[j] += t_i;
            }
        }
    }
}

// Display frequency spectrum of FFT
void display_spectrum() {
    printf("Frequency (Hz)\tMagnitude (dB)\n");
    for(int i = 0; i < NUM_SAMPLES / 2; i++) {
        float frequency = i * 44100.0 / NUM_SAMPLES;
        float magnitude_db = 20.0 * log10(sqrt(pow(fft_real[i], 2) + pow(fft_imag[i], 2)) / NUM_SAMPLES);
        printf("%f\t%f\n", frequency, magnitude_db);
    }
}

int main() {
    generate_signal();
    apply_window();
    apply_fft();
    display_spectrum();
    return 0;
}