//FormAI DATASET v1.0 Category: Digital signal processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate cosine wave with specified parameters
void generate_cosine_wave(int num_samples, double freq, double amplitude, double phase_shift, double sampling_rate, double *buffer) {
    int i;
    double time_increment = 1 / sampling_rate;
    for (i = 0; i < num_samples; i++) {
        double time = i * time_increment;
        buffer[i] = amplitude * cos(2 * PI * freq * time + phase_shift);
    }
}

// Function to perform Discrete Fourier Transform
void perform_fft(double *buffer, int num_samples) {
    int i, j, k;
    double theta, complex_real, complex_img;
    double real[num_samples], img[num_samples];
    for (i = 0; i < num_samples; i++) {
        real[i] = buffer[i];
        img[i] = 0;
    }
    j = num_samples / 2;
    for (i = 1; i < num_samples - 1; i++) {
        if (i < j) {
            double tmp_real = real[j];
            real[j] = real[i];
            real[i] = tmp_real;
            double tmp_img = img[j];
            img[j] = img[i];
            img[i] = tmp_img;
        }
        k = num_samples / 2;
        while (k <= j) {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
    }
    k = 1;
    while (k < num_samples) {
        theta = -2 * PI / k;
        for (i = 0; i < k; i++) {
            double w_real = cos(i * theta);
            double w_img = sin(i * theta);
            for (j = i; j < num_samples; j = j + 2 * k) {
                int idx = j + k;
                complex_real = w_real * real[idx] - w_img * img[idx];
                complex_img = w_real * img[idx] + w_img * real[idx];
                real[idx] = real[j] - complex_real;
                img[idx] = img[j] - complex_img;
                real[j] = real[j] + complex_real;
                img[j] = img[j] + complex_img;
            }
        }
        k = k * 2;
    }
    for (i = 0; i < num_samples; i++) {
        double magnitude = sqrt(pow(real[i], 2) + pow(img[i], 2));
        printf("Frequency: %lf Hz, Magnitude: %lf\n", i * (1.0 / num_samples), magnitude);
    }
}

int main() {
    int num_samples = 100;
    double freq = 10.0;
    double amplitude = 1.0;
    double phase_shift = 0.0;
    double sampling_rate = 100.0;
    double buffer[num_samples];
    generate_cosine_wave(num_samples, freq, amplitude, phase_shift, sampling_rate, buffer);
    perform_fft(buffer, num_samples);
    return 0;
}