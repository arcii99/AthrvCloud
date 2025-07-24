//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complex
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {

    /* Generate a Complex Sine Wave */
    double real; // real part of the complex signal
    double imag; // imaginary part of the complex signal
    double freq = 1000; // signal frequency in Hertz
    double sampling_freq = 20000; // sampling frequency in Hertz
    double time_step = 1 / sampling_freq; // time step to sample the signal in seconds
    double phase = 0; // initial phase of the signal in radians

    for (int i = 0; i < 1000; i++) {
        double time = i * time_step; // current time in seconds
        real = sin(2 * PI * freq * time + phase); // calculate the real part of the complex signal
        imag = cos(2 * PI * freq * time + phase); // calculate the imaginary part of the complex signal
        printf("%f%+fi\n", real, imag); // print the complex signal
    }

    /* Generate a Complex Gaussian Signal */
    double sigma = 0.1; // standard deviation of the Gaussian in seconds
    double amplitude = 1; // amplitude of the Gaussian
    double center_time = 0.5; // center time of the Gaussian in seconds

    for (int i = 0; i < 1000; i++) {
        double time = i * time_step; // current time in seconds
        real = amplitude * exp(-pow((time - center_time), 2) / (2 * pow(sigma, 2))); // calculate the real part of the complex signal using the Gaussian equation
        imag = 0; // set the imaginary part of the complex signal to zero
        printf("%f%+fi\n", real, imag); // print the complex signal
    }

    return 0;
}