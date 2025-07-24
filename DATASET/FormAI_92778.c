//FormAI DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include<stdio.h>

#define BUFFER_SIZE 1024
#define PI 3.14159265

// Function to generate a sine wave with given frequency and amplitude
void generate_sine_wave(float *sine_wave, int frequency, int amplitude, int sample_rate, int duration){
    int total_samples = sample_rate * duration;
    float increment = (2 * PI * frequency) / sample_rate;

    for(int i=0; i<total_samples; i++){
        sine_wave[i] = amplitude * sin(increment * i);
    }
}

// Function to apply low-pass filter on input signal
void low_pass_filter(float *input_signal, float *output_signal, int signal_length, int cutoff_frequency, int sample_rate){
    float RC = 1.0 / (2 * PI * cutoff_frequency);
    float dt = 1.0 / sample_rate;
    float alpha = dt / (RC + dt);

    output_signal[0] = alpha * input_signal[0];

    for(int i=1; i<signal_length; i++){
        output_signal[i] = alpha * input_signal[i] + (1 - alpha) * output_signal[i-1];
    }
}

int main(){
    float sine_wave[BUFFER_SIZE];
    float filtered_sine_wave[BUFFER_SIZE];

    int frequency = 10; // Hz
    int amplitude = 1000; // mV
    int sample_rate = 44100; // Hz
    int duration = 5; // seconds
    int cutoff_frequency = 5000; // Hz

    generate_sine_wave(sine_wave, frequency, amplitude, sample_rate, duration);

    low_pass_filter(sine_wave, filtered_sine_wave, BUFFER_SIZE, cutoff_frequency, sample_rate);

    // Print the filtered signal values
    for(int i=0; i<BUFFER_SIZE; i++){
        printf("%f\n", filtered_sine_wave[i]);
    }

    return 0;
}