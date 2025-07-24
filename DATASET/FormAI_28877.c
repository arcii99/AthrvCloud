//FormAI DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512 // Input signal array size

// Function prototypes
void generate_sine_wave(float sine_wave[N], int frequency);
void plot_graph(float signal[N], int signal_size);

int main()
{
    float input_signal[N];
    int frequency = 10; // Signal frequency in Hz

    // Generate a sine wave signal with a specified frequency
    generate_sine_wave(input_signal, frequency);

    // Apply the discrete Fourier transform (DFT) to the input signal
    float real[N], imaginary[N];

    for(int k=0; k<N; ++k) {
        real[k] = 0;
        imaginary[k] = 0;

        for(int n=0; n<N; ++n) {
            float angle = (2 * M_PI * k * n) / N;
            real[k] += input_signal[n] * cos(angle);
            imaginary[k] -= input_signal[n] * sin(angle);
        }
    }

    // Plot the frequency domain graph
    float magnitudes[N/2];

    for(int k=0; k<N/2; ++k) {
        magnitudes[k] = sqrt(pow(real[k], 2) + pow(imaginary[k], 2));
    }

    plot_graph(magnitudes, N/2);

    return 0;
}

void generate_sine_wave(float sine_wave[N], int frequency)
{
    for(int i=0; i<N; ++i) {
        double omega = 2.0 * M_PI * i * frequency / N;
        sine_wave[i] = sin(omega);
    }
}

// Function to plot a graph using the Gnuplot library
void plot_graph(float signal[N], int signal_size) {
    // Open a pipe to the Gnuplot executable
    FILE *gnu = popen("gnuplot -persist", "w");

    if (gnu == NULL) {
        printf("Error: Could not open pipe to Gnuplot\n");
        exit(1);
    }

    // Set the plot title and size
    fprintf(gnu, "set title 'Frequency Domain Graph'\n");
    fprintf(gnu, "set size square 1,1\n");

    // Create the plot
    fprintf(gnu, "plot '-' with lines title 'Magnitude Spectrum'\n");

    for (int i = 0; i < signal_size; i++) {
        fprintf(gnu, "%d %f\n", i, signal[i]);
    }

    fprintf(gnu, "e\n");

    // Close the pipe to Gnuplot
    pclose(gnu);
}